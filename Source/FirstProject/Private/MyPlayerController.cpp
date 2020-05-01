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
	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("MyPlayerController_Press2", EKeys::NumPadTwo));
	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("MyPlayerController_Press3", EKeys::NumPadThree));
	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("MyPlayerController_Press4", EKeys::NumPadFour));
	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("MyPlayerController_Press5", EKeys::NumPadFive));

	InputComponent->BindAction("MyPlayerController_Press1", EInputEvent::IE_Pressed, this, &AMyPlayerController::Press1);
	InputComponent->BindAction("MyPlayerController_Press2", EInputEvent::IE_Pressed, this, &AMyPlayerController::Press2);
	InputComponent->BindAction("MyPlayerController_Press3", EInputEvent::IE_Pressed, this, &AMyPlayerController::Press3);
	InputComponent->BindAction("MyPlayerController_Press4", EInputEvent::IE_Pressed, this, &AMyPlayerController::Press4);
	InputComponent->BindAction("MyPlayerController_Press5", EInputEvent::IE_Pressed, this, &AMyPlayerController::Press5);
}

void AMyPlayerController::Press1()
{
	UE_LOG(LogTemp, Warning, TEXT("DO IT 1!!"));
	Possess(Pawns[0]);
}
void AMyPlayerController::Press2()
{
	UE_LOG(LogTemp, Warning, TEXT("DO IT 2!!"));
	Possess(Pawns[1]);
}
void AMyPlayerController::Press3()
{
	UE_LOG(LogTemp, Warning, TEXT("DO IT 3!!"));
	Possess(Pawns[2]);
}
void AMyPlayerController::Press4()
{
	UE_LOG(LogTemp, Warning, TEXT("DO IT 4!!"));
	Possess(Pawns[3]);
}
void AMyPlayerController::Press5()
{
	UE_LOG(LogTemp, Warning, TEXT("DO IT 5!!"));
	Possess(Pawns[4]);
}