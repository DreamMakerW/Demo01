// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "GameplayTagContainer.h"

#include "DataAsset_CharacterStartUpData.generated.h"

struct FCharacterAbilitySet;

/**
 * 
 */
UCLASS()
class GAME01_API UDataAsset_CharacterStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()


public:
	virtual void GiveToAbilitySystemComponent(UCharacterAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

	
private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
		TArray<FCharacterAbilitySet> CharacterStartUpAbilitySets;
};
