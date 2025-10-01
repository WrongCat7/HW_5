// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay 호출 확인:"));
	move();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMyActor::move()
{
	totCvn = 0;
	totDist = 0;
	start = FVector2D(0, 0);

	//시작 지점
	VectorArray.Add(start);
	const FVector2D& startVec = VectorArray[0];
	UE_LOG(LogTemp, Warning, TEXT("start vector: X = %f, Y = %f"), startVec.X, startVec.Y);

	//10회 이동
	for (int32 i = 1; i < 11; i++) {
		start.X += step();
		start.Y += step();
		VectorArray.Add(start);
		const FVector2D& Vec = VectorArray[i];
		float d = distance(VectorArray[i - 1], VectorArray[i]);
		distan.Add(d);
		totDist += d;
		totCvn += createEvent();
		//이동 좌표 및 거리 log
		UE_LOG(LogTemp, Warning, TEXT("vector %d: X = %f, Y = %f, distance: %f"), i, Vec.X, Vec.Y, d);
	}
	//10회 이동 후 이동 거리 합계 및 이벤트 발생 횟수 합계
	UE_LOG(LogTemp, Warning, TEXT("total distance: %f, total event: %d"), totDist, totCvn);
}
int32 AMyActor::createEvent() {
	int32 randomValue = FMath::RandRange(1, 100);
	//50% 확률로 이벤트 O
	if (randomValue > 50) {
		UE_LOG(LogTemp, Warning, TEXT("Random Event Triggered!"));
		return 1;
	}
	//50% 확률로 이벤트 X
	else {
		UE_LOG(LogTemp, Warning, TEXT("Random Event Not Triggered"));
		return 0;
	}
}
//랜덤하게 0 또는 1 반환
int32_t AMyActor::step() {
	return FMath::RandRange(0, 1);
}
//이동거리 계산
float AMyActor::distance(FVector2D first, FVector2D second)
{
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;
	return FMath::Sqrt(dx * dx + dy * dy);
}
