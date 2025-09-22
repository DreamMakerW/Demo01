// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "CharacterCombatComponent.generated.h"

class ACharacterWeapon;

/**
 * 
 */
UCLASS()
class GAME01_API UCharacterCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "MyPawn|Character")
	ACharacterWeapon* GetCharacterWeaponByTag(FGameplayTag InWeaponTag) const;

	UFUNCTION(BlueprintCallable, Category = "MyPawn|Character")
	ACharacterWeapon* GetCharacterCurrentEquippedWeapon() const;
	
};
