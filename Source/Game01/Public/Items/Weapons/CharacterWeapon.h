// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/WeaponBase.h"
#include "GameplayAbilitySpecHandle.h"
#include "CharacterTypes/CharacterStructTypes.h"

#include "CharacterWeapon.generated.h"

/**
 * 
 */

struct FCharacterWeaponData;
class UStaticMesh;


UCLASS()
class GAME01_API ACharacterWeapon : public AWeaponBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponDta")
	FCharacterWeaponData CharacterWeaponData;

	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilitySpecHandle(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles);

private:
	TArray<FGameplayAbilitySpecHandle> GrantedAbilitySpecHandles;

};
