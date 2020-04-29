// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerBox.h"
#include "Components/BoxComponent.h"
#include "CarPawn.h"
// Sets default values
AMyTriggerBox::AMyTriggerBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
}

// Called when the game starts or when spawned
void AMyTriggerBox::BeginPlay()
{
	Super::BeginPlay();

	collision->OnComponentBeginOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapBegin);
	collision->OnComponentEndOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapEnd);
}

// Called every frame
void AMyTriggerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTriggerBox::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, 
class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("He tocado algo"));
	if (OtherActor != nullptr)
	{
		ACarPawn* player = Cast<ACarPawn>(OtherActor);

		if (player != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("He tocado un coche!"));
			totalCars++;
			if(totalCars>=totalCarsToWin)
				UE_LOG(LogTemp, Warning, TEXT("HAS GANADO"));
		}
	}
}

void AMyTriggerBox::OnOverlapEnd(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
		ACarPawn* player = CastChecked<ACarPawn>(OtherActor);

		if (player != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("He salido un coche!"));
			totalCars--;
		}
}

