// Fill out your copyright notice in the Description page of Project Settings.


#include "PoolableActor.h"

// Sets default values
APoolableActor::APoolableActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void APoolableActor::Reset()
{
	// if the owner has been destroyed we also destroy the bullet at the end of its life instead of enqueueing it 
	if (Owner->IsPendingKill())
	{
		Destroy();
		return;
	}
	// execute delegate that places the bullet back in the queue
	ResetDelegate.ExecuteIfBound(this);
	bIsActive = false;
	SetActorHiddenInGame(true);
}

void APoolableActor::Activate()
{
	SetActorHiddenInGame(false);
	bIsActive = true;
}

