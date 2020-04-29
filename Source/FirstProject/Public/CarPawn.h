// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CarPawn.generated.h"

UCLASS()
class FIRSTPROJECT_API ACarPawn : public APawn
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* staticMeshComp; //El class hace forward declaration, se puede hacer arriba tambn
	UPROPERTY(VisibleAnywhere)
		class USpringArmComponent* springArmComp;
	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* cameraComp;
	UPROPERTY(VisibleAnywhere)
		class UFloatingPawnMovement* floatingPawnMovement;
public:
	// Sets default values for this pawn's properties
	ACarPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	void OnSpaceInput();

	void OnHorizontal(float axis);
	void OnVertical(float axis);

	void YawRotateCamera(float axis);
	void PitchRotateCamera(float axis);
	void SetCameraDistance(float axis);
};
