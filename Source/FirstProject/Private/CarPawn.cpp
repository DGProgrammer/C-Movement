// Fill out your copyright notice in the Description page of Project Settings.


#include "CarPawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
// Sets default values
ACarPawn::ACarPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	staticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	floatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
	springArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	springArmComp->bUsePawnControlRotation = true;
	cameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	staticMeshComp->SetupAttachment(RootComponent);
	springArmComp->SetupAttachment(staticMeshComp);
	cameraComp->SetupAttachment(springArmComp);
}

// Called when the game starts or when spawned
void ACarPawn::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Hello, I'm alive!"));
}

// Called every frame
void ACarPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACarPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent && "Can´t found PlayerInputComponent");
	//PlayerInputComponent->BindAxis("MouseLeft", EInputEvent::IE_Pressed, this, &ACarPawn::OnSpaceInput);
	PlayerInputComponent->BindAxis("MoveVertical", this, &ACarPawn::OnVertical);
	PlayerInputComponent->BindAxis("MoveHorizontal", this, &ACarPawn::OnHorizontal);

	PlayerInputComponent->BindAxis("HorizontalMouse", this, &ACarPawn::YawRotateCamera);
	PlayerInputComponent->BindAxis("VerticalMouse", this, &ACarPawn::PitchRotateCamera);
	PlayerInputComponent->BindAxis("ScrollMouse", this, &ACarPawn::SetCameraDistance);


	PlayerInputComponent->BindAction("MouseLeft", EInputEvent::IE_Pressed, this, &ACarPawn::OnSpaceInput);
}

void ACarPawn::OnSpaceInput()
{
	UE_LOG(LogTemp, Warning, TEXT("Input do it"));
}

void ACarPawn::OnVertical(float axis)
{
	//UE_LOG(LogTemp, Warning, TEXT("Axis: %f "), axis);
	AddMovementInput(GetActorForwardVector(), axis);
}

void ACarPawn::OnHorizontal(float axis)
{
	//UE_LOG(LogTemp, Warning, TEXT("Axis: %f "), axis);
	AddMovementInput(GetActorRightVector(), axis);
}
void ACarPawn::YawRotateCamera(float axis)
{
	AddControllerYawInput(axis);
}

void ACarPawn::PitchRotateCamera(float axis)
{
	AddControllerPitchInput(axis);
}

void ACarPawn::SetCameraDistance(float axis)
{
	//UE_LOG(LogTemp, Warning, TEXT("Axis: %f "), axis);
	springArmComp->TargetArmLength += axis * 10;
}


