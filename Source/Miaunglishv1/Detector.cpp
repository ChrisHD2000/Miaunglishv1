// Fill out your copyright notice in the Description page of Project Settings.


#include "Detector.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#define OUT
// Sets default values for this component's properties
UDetector::UDetector()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDetector::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDetector::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// obtener el punto de vista del jugador 
	
	FVector MarvinViewpointLocation;
	FRotator MarvinViewpointRotation;
	/*GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT MarvinViewpointLocation,
		OUT MarvinViewpointRotation
	);*/

	GetOwner()->GetActorEyesViewPoint(
		OUT MarvinViewpointLocation,
		OUT MarvinViewpointRotation
	);
	//Probando en el log
	/*UE_LOG(LogTemp, Warning, TEXT("Posicion: %s, Rotacion: %s "), 
		*MarvinViewpoint.ToString(), 
		*MarvinViewpointRotation.ToString())*/
//Dibujar una linea rojo en el mundo para visualizar 
	//MarvinViewpointLocation = MarvinViewpointLocation + (0.f, 200.f, 0.f);
	FVector FinalDeLinea = MarvinViewpointLocation + MarvinViewpointRotation.Vector() *alcance;
	DrawDebugLine(GetWorld(),
		MarvinViewpointLocation,
		FinalDeLinea,
		FColor(0, 255, 0),
		false,
		0.f,
		0.f,
		10.f
	);
	//Crear parametros de busqueda 
	FCollisionQueryParams ParametrosBusqueda(FName(TEXT("")), false, GetOwner());
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		MarvinViewpointLocation,
		FinalDeLinea,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		ParametrosBusqueda
	);
// ver con lo que colisionamos
	AActor * actorQueGolpea = Hit.GetActor();
	if (actorQueGolpea) {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *(actorQueGolpea->GetName()))

	}
}

