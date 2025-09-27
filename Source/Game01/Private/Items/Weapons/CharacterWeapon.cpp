// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/CharacterWeapon.h"
#include "DebugHelper.h"

void ACharacterWeapon::AssignGrantedAbilitySpecHandle(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles)
{
	GrantedAbilitySpecHandles = InSpecHandles;
}
