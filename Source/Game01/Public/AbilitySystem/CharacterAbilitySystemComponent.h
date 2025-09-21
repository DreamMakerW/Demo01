// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CharacterTypes/CharacterStructTypes.h"

#include "CharacterAbilitySystemComponent.generated.h"


/**
 * 
 */
UCLASS()
class GAME01_API UCharacterAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:

	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);

	UFUNCTION(BlueprintCallable, Category = "CharacterASC|Ability", meta = (ApplyLevel = "1"))
	void GrantCharacterWeaponAbility(const TArray<FCharacterAbilitySet>& InDefaultWeaponAbilities, int32 ApplyLevel);


};
