// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PawnCombatComponent.h"

#include "DebugHelper.h"
#include "Items/Weapons/WeaponBase.h"


void UPawnCombatComponent::RegisterWeapon(FGameplayTag InWeaponTagToRegister, AWeaponBase* InWeaponToRegister)
{
	// 检查标签是否已经存在
	checkf(!CarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("The tag name %s has already been registered as carried weapon"), *InWeaponTagToRegister.ToString());

	// 检查武器是否有效
	check(InWeaponToRegister);

	CarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);

	

}

AWeaponBase* UPawnCombatComponent::GetCarriedWeaponByTag(FGameplayTag InWeaponToGet) const
{
	if (CarriedWeaponMap.Contains(InWeaponToGet))
	{
		if (AWeaponBase* const* FoundWeapon = CarriedWeaponMap.Find(InWeaponToGet))
		{
			return *FoundWeapon;
		}
	}
	return nullptr;
}

AWeaponBase* UPawnCombatComponent::GetCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}
	return GetCarriedWeaponByTag(CurrentEquippedWeaponTag);
}
