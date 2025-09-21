// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "GameplayTagContainer.h"

#include "PlayerCharacter.generated.h"

class UInputAction;
class UInputMappingContext;
struct FInputActionValue;
class UDataAsset_InputConfig;
class UCharacterCombatComponent;
/**
 * 
 */
UCLASS()
class GAME01_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:

	APlayerCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

protected:

	void MoveFwd(const FInputActionValue& InputValue);
	void MoveRight(const FInputActionValue& InputValue);
	void LookRight(const FInputActionValue& InputValue);
	void LookUp(const FInputActionValue& InputValue);
	void StartJump(const FInputActionValue& InputValue);
	void StopJump(const FInputActionValue& InputValue);

	void Input_AbilityInputPressed(FGameplayTag InInputTag);
	void Input_AbilityInputReleased(FGameplayTag InInputTag);

private:
	
#pragma region Inputs
	
	/*
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UInputAction> MoveForwardAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UInputAction> MoveRightAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UInputAction> LookUpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UInputAction> LookRightAction;*/

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
		UDataAsset_InputConfig* InputConfigDataAsset;

#pragma endregion

#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerCharacter|Components", meta = (AllowPrivateAccess = "True"))
		UCharacterCombatComponent* CharacterCombatComponent;
#pragma endregion

	float ControllerSpeed = 0.5;
	bool IsInAir = false;
	
public:
	FORCEINLINE UCharacterCombatComponent* GetCharacterCombatComponent() const { return CharacterCombatComponent; }
};
