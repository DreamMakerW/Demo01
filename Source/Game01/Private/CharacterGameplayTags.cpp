// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterGameplayTags.h"

namespace CharacterGameplayTags
{
	/* Input */
	UE_DEFINE_GAMEPLAY_TAG(Input_MoveForward, "Input.MoveForward");
	UE_DEFINE_GAMEPLAY_TAG(Input_MoveRight, "Input.MoveRight");
	UE_DEFINE_GAMEPLAY_TAG(Input_Jump, "Input.Jump");
	UE_DEFINE_GAMEPLAY_TAG(Input_LookUp, "Input.LookUp");
	UE_DEFINE_GAMEPLAY_TAG(Input_LookRight, "Input.LookRight");
	UE_DEFINE_GAMEPLAY_TAG(Input_Equip_Sword, "Input.Equip.Sword");
	UE_DEFINE_GAMEPLAY_TAG(Input_LightAttack_Sword, "Input.LightAttack.Sword");


	/* Player */
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Sword, "Player.Ability.Equip.Sword");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light_Sword, "Player.Ability.Attack.Light.Sword");

	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Sword, "Player.Weapon.Sword");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Sword, "Player.Event.Equip.Sword");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_UnEquip_Sword, "Player.Event.UnEquip.Sword");
}
