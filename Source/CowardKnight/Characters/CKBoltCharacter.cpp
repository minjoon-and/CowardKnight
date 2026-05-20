// Copyright Epic Games, Inc. All Rights Reserved.

#include "CKBoltCharacter.h"

#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

ACKBoltCharacter::ACKBoltCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	UCharacterMovementComponent* Movement = GetCharacterMovement();
	Movement->bOrientRotationToMovement = false;
	Movement->GravityScale = 2.0f;
	Movement->JumpZVelocity = 700.0f;
	Movement->AirControl = 0.6f;
	Movement->MaxWalkSpeed = 650.0f;
	Movement->bConstrainToPlane = true;
	Movement->SetPlaneConstraintAxisSetting(EPlaneConstraintAxisSetting::Y);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 900.0f;
	CameraBoom->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->bUsePawnControlRotation = false;

	SideViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCamera->bUsePawnControlRotation = false;
}

void ACKBoltCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!EnhancedInput)
	{
		return;
	}

	if (MoveAction)
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACKBoltCharacter::Move);
	}

	if (JumpAction)
	{
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACKBoltCharacter::StopJumpingInput);
	}

	if (AttackAction)
	{
		EnhancedInput->BindAction(AttackAction, ETriggerEvent::Started, this, &ACKBoltCharacter::BasicAttack);
	}

	if (SkillAction)
	{
		EnhancedInput->BindAction(SkillAction, ETriggerEvent::Started, this, &ACKBoltCharacter::UseSkill);
	}
}

void ACKBoltCharacter::Move(const FInputActionValue& Value)
{
	const float Direction = Value.Get<float>();
	if (!FMath::IsNearlyZero(Direction))
	{
		AddMovementInput(FVector::ForwardVector, Direction);
	}
}

void ACKBoltCharacter::StopJumpingInput(const FInputActionValue& Value)
{
	StopJumping();
}

void ACKBoltCharacter::BasicAttack()
{
	const float CurrentTime = GetWorld()->GetTimeSeconds();
	if (CurrentTime - LastAttackTime < AttackCooldown)
	{
		return;
	}

	LastAttackTime = CurrentTime;
	OnBasicAttack();
}

void ACKBoltCharacter::UseSkill()
{
	OnSkillUsed();
}
