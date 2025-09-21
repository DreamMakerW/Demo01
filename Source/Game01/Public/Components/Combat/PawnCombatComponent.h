// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"

#include "PawnCombatComponent.generated.h"

class AWeaponBase;

/**
 * 
 */
UCLASS()
class GAME01_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "MyPawn|Combat")
	void RegisterWeapon(FGameplayTag InWeaponTagToRegister, AWeaponBase* InWeaponToRegister);

	UFUNCTION(BlueprintCallable, Category = "MyPawn|Combat")
	AWeaponBase* GetCarriedWeaponByTag(FGameplayTag InWeaponToGet) const;

	UFUNCTION(BlueprintCallable, Category = "MyPawn|Combat")
	AWeaponBase* GetCurrentEquippedWeapon() const;

	UPROPERTY(BlueprintReadWrite, Category = "MyPawn|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

private:
	TMap<FGameplayTag, AWeaponBase*> CarriedWeaponMap;

};
