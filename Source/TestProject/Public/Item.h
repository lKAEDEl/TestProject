// Fill out your copyright notice in the Description page of Project Settings.

#pragma once //중복방지

#include "CoreMinimal.h"// 
#include "GameFramework/Actor.h"
#include "Item.generated.h"//항상 맨마지막에 추가해야됨 안그러면 빌드오류


UCLASS()
class TESTPROJECT_API AItem : public AActor
{
	GENERATED_BODY()

public:
	AItem();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Item|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "Item|Properties")
	float RotationSpeed;

	FVector StartLocation;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};