// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/BaseGameplayAbility.h"
#include "CharacterGameplayAbility.generated.h"

class APlayerCharacter;

/**
 * 
 */
UCLASS()
class GAME01_API UCharacterGameplayAbility : public UBaseGameplayAbility
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "Character|Ability")
	APlayerCharacter* GetPlayerCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Character|Ability")
	APlayerController* GetPlayerControllerFromAcotrInfo();

	UFUNCTION(BlueprintPure, Category = "Character|Ability")
	UCharacterCombatComponent* GetCharacterCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Character|Ability")
	USkeletalMeshComponent* GetSkeletalMeshComponentFromActorInfo();
	
private:
	TWeakObjectPtr<APlayerCharacter> CachedPlayerCharacter;
	TWeakObjectPtr<APlayerController> CachedPlayerController;
	TWeakObjectPtr<USkeletalMeshComponent> CachedSkeletalMeshComponent;
};
