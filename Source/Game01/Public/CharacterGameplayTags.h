// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NativeGameplayTags.h"

namespace CharacterGameplayTags
{
	/* Input */
	GAME01_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_MoveForward);
	GAME01_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_MoveRight);
	GAME01_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Jump);
	GAME01_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_LookUp);
	GAME01_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_LookRight);
	GAME01_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Equip_Sword);
	GAME01_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_LightAttack_Sword);


	/* Player */
	GAME01_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Sword);
	GAME01_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light_Sword);

	GAME01_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Plyaer_Weapon_Sword);

	GAME01_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Sword);
	GAME01_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_UnEquip_Sword);
}
