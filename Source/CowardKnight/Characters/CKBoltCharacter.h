// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "CKBoltCharacter.generated.h"

class UCameraComponent;
class UInputAction;
class USpringArmComponent;

UCLASS()
class COWARDKNIGHT_API ACKBoltCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACKBoltCharacter();

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<UCameraComponent> SideViewCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> AttackAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> SkillAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat")
	float AttackCooldown = 0.35f;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void BasicAttack();

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void UseSkill();

	UFUNCTION(BlueprintImplementableEvent, Category = "Combat")
	void OnBasicAttack();

	UFUNCTION(BlueprintImplementableEvent, Category = "Combat")
	void OnSkillUsed();

private:
	void Move(const FInputActionValue& Value);
	void StopJumpingInput(const FInputActionValue& Value);

	float LastAttackTime = -100.0f;
};
