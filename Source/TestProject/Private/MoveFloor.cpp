#include "MoveFloor.h"

AMoveFloor::AMoveFloor()
{
	PrimaryActorTick.bCanEverTick = true;

	
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	
	MoveSpeed = 200.0f;
	MoveDistance = 300.0f;
	Direction = 1;
}

void AMoveFloor::BeginPlay()
{
	Super::BeginPlay();

	
	StartLocation = GetActorLocation();
}

void AMoveFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	FVector MoveOffset =
		GetActorForwardVector()
		* MoveSpeed
		* Direction
		* DeltaTime;

	FVector NewLocation = GetActorLocation() + MoveOffset;
	SetActorLocation(NewLocation);

	
	float Distance = FVector::Dist(StartLocation, NewLocation);

	
	if (Distance >= MoveDistance)
	{
		Direction *= -1;
	}
}
