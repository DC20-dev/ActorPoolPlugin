// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PoolableActor.generated.h"

DECLARE_DELEGATE_OneParam(OnReset, APoolableActor*)

UCLASS(Abstract)
class ACTORPOOLING_API APoolableActor : public AActor
{
	GENERATED_BODY()
	
public:
	OnReset ResetDelegate;

protected:
	bool bIsActive = false;

public:
	// Sets default values for this actor's properties
	APoolableActor();

	UFUNCTION(BLueprintCallable, Category = "Behaviour")
		// Activates the actor for in game usage.
		virtual void Activate();

protected:

	UFUNCTION(BLueprintCallable, Category = "Behaviour")
		// Places the actor back in its pool if the pool is still present, otherwise it gets destroyed.
		// Remember to also set the actor state back to stock.
		virtual void Reset();

};
