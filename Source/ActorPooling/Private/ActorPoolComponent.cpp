// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPoolComponent.h"


void UActorPoolComponent::AddToPool(APoolableActor* actor)
{
	Pool.Enqueue(actor);
}

APoolableActor* UActorPoolComponent::GetFromPool()
{
	APoolableActor* actor;
	if (Pool.Dequeue(actor))
	{
		return actor;
	}
	else
	{
		return nullptr;
	}
}

void UActorPoolComponent::InitPool()
{
	if (!ActorClass)
	{
		return;
	}
	for (int32 i = 0; i < ActorsCount; i++)
	{
		APoolableActor* actor = (APoolableActor*)GetWorld()->SpawnActor(ActorClass);
		actor->SetOwner(this->GetOwner());
		actor->ResetDelegate.BindUObject(this, &UActorPoolComponent::AddToPool);
		Pool.Enqueue(actor);
	}
}

void UActorPoolComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	// upon destruction clear the pool of inactive actors
	// the active actors will destroy themselves if the owner is destroyed

	APoolableActor* actor;
	while (Pool.Dequeue(actor))
	{
		actor->Destroy();
	}
}

// Sets default values for this component's properties
UActorPoolComponent::UActorPoolComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

