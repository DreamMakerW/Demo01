// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "BaseCharacter.generated.h"

class UCharacterAbilitySystemComponent;
class UCharacterAttributeSet;
class UDataAsset_StartUpDataBase;

UCLASS()
class GAME01_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface

public:	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

private:
	UPROPERTY(VisibleAnywhere, Category = "BaseCharacter|Components")
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "BaseCharacter|Components")
		class UCameraComponent* Camera;

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
		UCharacterAbilitySystemComponent* CharacterAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
		UCharacterAttributeSet* CharacterAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
		TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;

public:
	FORCEINLINE UCharacterAbilitySystemComponent* GetCharacterAbilitySystemComponent() const { return CharacterAbilitySystemComponent; }
	FORCEINLINE UCharacterAttributeSet* GetCharacterAttributeSet() const { return CharacterAttributeSet; }
};
