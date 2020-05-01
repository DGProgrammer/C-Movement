// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 *
 */
UCLASS()
class FIRSTPROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere)
		TArray<class ACarPawn*> Pawns;
public:
	AMyPlayerController();
	void Press1();
	void Press2();
	void Press3();
	void Press4();
	void Press5();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
