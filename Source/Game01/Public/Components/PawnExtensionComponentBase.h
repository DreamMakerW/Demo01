// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME01_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:

	template<class T>
	T* GetOwningPawn() const
	{
		// static_assert 和 TPointerIsConvertibleFromTo可以在编译阶段就检查T是否派生自APawn
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "PawnExtensionComponentBase -> 'T' template parameter of GetOwningPawn() must be derived from APawn!");
		return CastChecked<T>(GetOwner());
	}

	APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}

	template<class T>
	T* GetOwningController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APlayerController>::Value, "PawnExtensionComponentBase -> 'T' template parameter of GetOwningPawn() must be derived from APlayerController!");
		return GetOwningPawn<APawn>()->GetController<T>();
	}
		
};
