// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/BaseAnimInstance.h"
#include "CharacterAnimInstance.generated.h"

class ABaseCharacter;
class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class GAME01_API UCharacterAnimInstance : public UBaseAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
		ABaseCharacter* OwningCharacter;

	UPROPERTY()
		UCharacterMovementComponent* OwningMovementComponent;
	
#pragma region MovementProperties

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimData|LocomotionData")
		float GroundSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimData|LocomotionData")
		FVector Velocity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimData|LocomotionData")
		bool IsFalling;

#pragma endregion

};
