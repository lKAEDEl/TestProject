#include "UpDownFloor.h"

AUpDownFloor::AUpDownFloor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	MoveSpeed = 150.0f;
	MoveDistance = 1000.0f;

	CurrentMove = 0.0f;
	Direction = 1;
}

void AUpDownFloor::BeginPlay()
{
	Super::BeginPlay();

	// 배치한곳에서 시작
	StartLocation = GetActorLocation();
}

void AUpDownFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 이동 거리
	CurrentMove += MoveSpeed * Direction * DeltaTime;

	
	if (CurrentMove >= MoveDistance)
	{
		CurrentMove = MoveDistance;
		Direction = -1;
	}
	else if (CurrentMove <= 0.0f)
	{
		CurrentMove = 0.0f;
		Direction = 1;
	}

	
	FVector NewLocation =
		StartLocation +
		GetActorUpVector() * CurrentMove;

	SetActorLocation(NewLocation);
}
