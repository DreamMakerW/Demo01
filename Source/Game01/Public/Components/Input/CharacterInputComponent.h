// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"

#include "CharacterInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class GAME01_API UCharacterInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);

	template<class UserObject, typename CallbackFunc>
	void BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallbackFunc PressedFunc, CallbackFunc ReleasedFunc);
};

template<class UserObject, typename CallbackFunc>
inline void UCharacterInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("CharacterInputComponent.cpp: Forget to load DataAsset_InputConfig!"));
	if (UInputAction* InputAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(InputAction, TriggerEvent, ContextObject, Func);
	}
}

template<class UserObject, typename CallbackFunc>
inline void UCharacterInputComponent::BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallbackFunc PressedFunc, CallbackFunc ReleasedFunc)
{
	
	checkf(InInputConfig, TEXT("CharacterInputComponent.cpp: Forgot to load DataAsset_InputConfig!"));
	
	TArray<FInputActionConfig> AbilityActionConfigArray = InInputConfig->AbilityInputActions;

	for (FInputActionConfig& ActionConfig : AbilityActionConfigArray)
	{
		if (!ActionConfig.IsValid()) continue;
		BindAction(ActionConfig.InputAction, ETriggerEvent::Started, ContextObject, PressedFunc, ActionConfig.InputTag);
		BindAction(ActionConfig.InputAction, ETriggerEvent::Completed, ContextObject, ReleasedFunc, ActionConfig.InputTag);
	}

}


