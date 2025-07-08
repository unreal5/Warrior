// 版权没有，拷贝自由。

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	template <typename T>
	T* GetOwningPawn() const;

	APawn* GetOwningPawn() const;

	template <typename T>
	T* GetOwningController() const;
};

template <typename T>
T* UPawnExtensionComponentBase::GetOwningPawn() const
{
	static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "T must be a subclass of APawn");
	return CastChecked<T>(GetOwner());
}

template <typename T>
T* UPawnExtensionComponentBase::GetOwningController() const
{
	static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "T must be a subclass of AController");
	if (!GetOwningPawn()) return nullptr;

	AController* Controller = GetOwningPawn()->GetController();
	return Controller;
}
