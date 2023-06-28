// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PoolableActor.h"
#include "ActorPoolComponent.generated.h"


UCLASS( ClassGroup=(Pool), meta=(BlueprintSpawnableComponent) )
class ACTORPOOLING_API UActorPoolComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pool", meta = (ClampMin = "0"))
		int32 ActorsCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pool")
		TSubclassOf<class APoolableActor> ActorClass = nullptr;

protected:
	TQueue<APoolableActor*> Pool;

public:
	// Sets default values for this component's properties
	UActorPoolComponent();

	UFUNCTION(Category = "Pool")
		void AddToPool(APoolableActor* actor);

	UFUNCTION(BlueprintCallable, Category = "Pool")
		// Returns a PoolableActor from the pool if not empty, otherwise nullptr
		APoolableActor* GetFromPool();

	UFUNCTION(BlueprintCallable, Category = "Pool")
		// Initializes the pool; calling from BeginPlay is suggested
		void InitPool();

	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
};
