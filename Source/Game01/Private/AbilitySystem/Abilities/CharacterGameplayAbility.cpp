// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/CharacterGameplayAbility.h"
#include "Characters/PlayerCharacter.h"

APlayerCharacter* UCharacterGameplayAbility::GetPlayerCharacterFromActorInfo()
{
	if (!CachedPlayerCharacter.IsValid())
	{
		CachedPlayerCharacter = Cast<APlayerCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedPlayerCharacter.IsValid() ? CachedPlayerCharacter.Get() : nullptr;
}

APlayerController* UCharacterGameplayAbility::GetPlayerControllerFromAcotrInfo()
{
	if (!CachedPlayerController.IsValid())
	{
		CachedPlayerController = Cast<APlayerController>(CurrentActorInfo->PlayerController);
	}
	return CachedPlayerController.IsValid() ? CachedPlayerController.Get() : nullptr;
}

UCharacterCombatComponent* UCharacterGameplayAbility::GetCharacterCombatComponentFromActorInfo()
{
	return GetPlayerCharacterFromActorInfo()->GetCharacterCombatComponent();
}
