// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/CharacterCombatComponent.h"

#include "Items/Weapons/CharacterWeapon.h"

ACharacterWeapon* UCharacterCombatComponent::GetCharacterWeaponByTag(FGameplayTag InWeaponTag) const
{
    return Cast<ACharacterWeapon>(GetCarriedWeaponByTag(InWeaponTag));
}

ACharacterWeapon* UCharacterCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
    return Cast<ACharacterWeapon>(GetCurrentEquippedWeapon());
}
