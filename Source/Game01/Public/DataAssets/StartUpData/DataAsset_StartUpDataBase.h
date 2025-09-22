// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UBaseGameplayAbility;
class UCharacterAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class GAME01_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UCharacterAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
		TArray<TSubclassOf<UBaseGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
		TArray<TSubclassOf<UBaseGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(UCharacterAbilitySystemComponent* InASCToGive, TArray<TSubclassOf<UBaseGameplayAbility>> InAbilitiesToGive, int32 ApplyLevel = 1);
};
