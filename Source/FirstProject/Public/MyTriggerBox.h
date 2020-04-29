// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTriggerBox.generated.h"

UCLASS()
class FIRSTPROJECT_API AMyTriggerBox : public AActor
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere)
		class UBoxComponent* collision;

	UPROPERTY(EditAnywhere)
		int32 totalCarsToWin;

	int32 totalCars;

public:	
	// Sets default values for this actor's properties
	AMyTriggerBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
			class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
