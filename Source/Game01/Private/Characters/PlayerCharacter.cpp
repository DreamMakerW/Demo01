// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PlayerCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/Input/CharacterInputComponent.h"
#include "CharacterGameplayTags.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "Components/Combat/CharacterCombatComponent.h"

#include "DebugHelper.h"

APlayerCharacter::APlayerCharacter()
{
	CharacterCombatComponent = CreateDefaultSubobject<UCharacterCombatComponent>(TEXT("PlayerCombatComponent"));
	// CurrentState = EState::Unarmed;
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

#pragma region Original Input System
	/*
	* 原本的输入系统

	PlayerInputComponent->BindAxis("MoveFwd", this, &ThisClass::MoveFwd);
	PlayerInputComponent->BindAxis("MoveRight", this, &ThisClass::MoveRight);

	PlayerInputComponent->BindAxis("LookRight", this, &ThisClass::LookRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ThisClass::LookUp);

	PlayerInputComponent->BindAction("SpeedUp", EInputEvent::IE_Pressed, this, &ThisClass::SpeedUp);
	PlayerInputComponent->BindAction("SpeedUp", EInputEvent::IE_Released, this, &ThisClass::SpeedDown);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ThisClass::StartJump);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Released, this, &ThisClass::StopJump);
	*/

#pragma endregion

	/* 增强输入 */

	// 增强输入子系统，绑定mappingcontext
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			SubSystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);
		}
	}

	// 需要在项目设置中修改default input component class
	UCharacterInputComponent* MyInputComponent = CastChecked<UCharacterInputComponent>(PlayerInputComponent);

	MyInputComponent->BindNativeInputAction(InputConfigDataAsset, CharacterGameplayTags::Input_MoveRight, ETriggerEvent::Triggered, this, &ThisClass::MoveRight);
	MyInputComponent->BindNativeInputAction(InputConfigDataAsset, CharacterGameplayTags::Input_MoveForward, ETriggerEvent::Triggered, this, &ThisClass::MoveFwd);
	MyInputComponent->BindNativeInputAction(InputConfigDataAsset, CharacterGameplayTags::Input_Jump, ETriggerEvent::Triggered, this, &ThisClass::Jump);
	MyInputComponent->BindNativeInputAction(InputConfigDataAsset, CharacterGameplayTags::Input_LookUp, ETriggerEvent::Triggered, this, &ThisClass::LookUp);
	MyInputComponent->BindNativeInputAction(InputConfigDataAsset, CharacterGameplayTags::Input_LookRight, ETriggerEvent::Triggered, this, &ThisClass::LookRight);

	MyInputComponent->BindAbilityInputAction(InputConfigDataAsset, this, &ThisClass::Input_AbilityInputPressed, &ThisClass::Input_AbilityInputReleased);
	
#pragma region Enhanced Input Component
	// 增强输入组件
	/*
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &ThisClass::MoveFwd);
		EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &ThisClass::MoveRight);
		EnhancedInputComponent->BindAction(LookUpAction, ETriggerEvent::Triggered, this, &ThisClass::LookUp);
		EnhancedInputComponent->BindAction(LookRightAction, ETriggerEvent::Triggered, this, &ThisClass::LookRight);

		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ThisClass::StartJump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ThisClass::StopJump);
	}
	*/
#pragma endregion
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	/*
	if (CharacterAbilitySystemComponent && CharacterAttributeSet)
	{
		const FString ASCText = FString::Printf(TEXT("Owner Actor: %s"), *CharacterAbilitySystemComponent->GetOwner()->GetActorLabel());
		Debug::Print(ASCText, FColor::Purple);
	}
	*/

	if (!CharacterStartUpData.IsNull())
	{
		if (UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(CharacterAbilitySystemComponent);
		}
	}
}

void APlayerCharacter::MoveFwd(const FInputActionValue& InputValue)
{
	float AxisValue = InputValue.GetMagnitude();
	if (Controller != nullptr && AxisValue != 0.0f)
	{
		const FRotator ControllerRotation(0, GetControlRotation().Yaw, 0);
		const FVector Direction = FRotationMatrix(ControllerRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, AxisValue);
	}
}

void APlayerCharacter::MoveRight(const FInputActionValue& InputValue)
{
	float AxisValue = InputValue.GetMagnitude();
	if (Controller != nullptr && AxisValue != 0.0f)
	{
		const FRotator ControllerRotation(0, GetControlRotation().Yaw, 0);
		const FVector Direction = FRotationMatrix(ControllerRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, AxisValue);
	}
}

void APlayerCharacter::LookRight(const FInputActionValue& InputValue)
{
	float AxisValue = InputValue.GetMagnitude();
	AddControllerYawInput(AxisValue * ControllerSpeed);
}

void APlayerCharacter::LookUp(const FInputActionValue& InputValue)
{
	float AxisValue = InputValue.GetMagnitude();
	AddControllerPitchInput(-AxisValue * ControllerSpeed);
}

void APlayerCharacter::StartJump(const FInputActionValue& InputValue)
{
	Jump();
}

void APlayerCharacter::StopJump(const FInputActionValue& InputValue)
{
	StopJumping();
}

void APlayerCharacter::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
	CharacterAbilitySystemComponent->OnAbilityInputPressed(InInputTag);
	// Debug::Print(InInputTag.GetTagName().ToString(), FColor::Yellow);
}

void APlayerCharacter::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
	// UE_LOG(LogTemp, Warning, TEXT("Input Ability Input Released"));
	CharacterAbilitySystemComponent->OnAbilityInputReleased(InInputTag);
}


