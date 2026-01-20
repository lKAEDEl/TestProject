#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UpDownFloor.generated.h"

UCLASS()
class TESTPROJECT_API AUpDownFloor : public AActor
{
	GENERATED_BODY()

public:
	AUpDownFloor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move")
	float MoveDistance;

	// 시작 위치
	FVector StartLocation;

	// 현재 이동한 거리
	float CurrentMove;

	// 이동 방향
	int32 Direction;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
