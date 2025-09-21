// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/CharacterAnimInstance.h"
#include "Characters/BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


void UCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<ABaseCharacter>(TryGetPawnOwner());
	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	// ÀàËÆÓÚtickº¯Êý

	if (!OwningCharacter || !OwningCharacter)
	{
		return;
	}

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	Velocity = OwningCharacter->GetVelocity();
	IsFalling = OwningMovementComponent->IsFalling();
}
