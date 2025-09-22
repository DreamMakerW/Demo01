// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_CharacterStartUpData.h"
#include "AbilitySystem/Abilities/BaseGameplayAbility.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "CharacterTypes/CharacterStructTypes.h"


void UDataAsset_CharacterStartUpData::GiveToAbilitySystemComponent(UCharacterAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);
	
	for (const FCharacterAbilitySet& AbilitySet : CharacterStartUpAbilitySets)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec Spec(AbilitySet.AbilityToGrant);
		Spec.SourceObject = InASCToGive->GetAvatarActor();
		Spec.Level = ApplyLevel;
		Spec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);
	
		InASCToGive->GiveAbility(Spec);
	}
}
