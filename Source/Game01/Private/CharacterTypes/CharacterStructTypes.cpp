// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterTypes/CharacterStructTypes.h"

#include "AbilitySystem/Abilities/BaseGameplayAbility.h"

bool FCharacterAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
