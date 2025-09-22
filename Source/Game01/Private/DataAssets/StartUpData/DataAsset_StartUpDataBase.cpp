// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/BaseGameplayAbility.h"


void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UCharacterAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbilities(InASCToGive, ActivateOnGivenAbilities, ApplyLevel);
	GrantAbilities(InASCToGive, ReactiveAbilities, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(UCharacterAbilitySystemComponent* InASCToGive, TArray<TSubclassOf<UBaseGameplayAbility>> InAbilitiesToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UBaseGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;
		
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
