// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "CarPawn.h"
#include "GameFramework/PlayerInput.h"
AMyPlayerController::AMyPlayerController()
{
	AutoReceiveInput = EAutoReceiveInput::Type::Player0;
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UWorld* world = GetWorld();
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(world, ACarPawn::StaticClass(), Actors);

	for (AActor* p : Actors)
	{
		ACarPawn* c = Cast<ACarPawn>(p);
		Pawns.Add(c);
	}

	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("MyPlayerController_Press1", EKeys::NumPadOne));
	InputComponent->BindAction("MyPlayerController_Press1", EInputEvent::IE_Pressed,this, &AMyPlayerController::Press1);
}

void AMyPlayerController::Press1()
{
	UE_LOG(LogTemp, Warning, TEXT("DO IT!!"));

}
