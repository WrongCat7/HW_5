#pragma once
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HW_5_API AMyActor : public AActor
{
	GENERATED_BODY()
private:
	TArray<FVector2D> VectorArray;//밑에 것과 이것은 헤더와 cpp어디에 선언해야할까?
	TArray<float> distan;
	FVector2D start;
	int32 totCvn;
	float totDist;

public:
	// Sets default values for this actor's properties
	AMyActor();
	void move();

	int32_t step();
	float distance(FVector2D first, FVector2D second);
	int32 createEvent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
