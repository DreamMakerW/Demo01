// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/BaseGameplayAbility.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "Components/Combat/PawnCombatComponent.h"


void UBaseGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	/** Called when the ability is given to an AbilitySystemComponent */
	Super::OnGiveAbility(ActorInfo, Spec);
	
	if (AbilityActivationPolicy == ECharacterAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void UBaseGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	/** Native function, called if an ability ends normally or abnormally. If bReplicate is set to true, try to replicate the ending to the client/server */
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (AbilityActivationPolicy == ECharacterAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}

UCharacterAbilitySystemComponent* UBaseGameplayAbility::GetCharacterAbilitySystemComponentFromActorInfo() const
{
	return Cast<UCharacterAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}

UPawnCombatComponent* UBaseGameplayAbility::GetPawnCombatComponentFromActorInfo() const
{
	// 从Actor上查找component可以用FindComponentByClass()，返回第一个查找到的结果
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
}
