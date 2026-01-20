#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveFloor.generated.h"

UCLASS()
class TESTPROJECT_API AMoveFloor : public AActor
{
	GENERATED_BODY()

public:
	AMoveFloor();

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Floor|Components")
	USceneComponent* SceneRoot;

	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Floor|Components")
	UStaticMeshComponent* StaticMeshComp;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floor|Move")
	float MoveSpeed;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floor|Move")
	float MoveDistance;

	
	FVector StartLocation;

	
	int32 Direction;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
