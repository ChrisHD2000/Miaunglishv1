// Fill out your copyright notice in the Description page of Project Settings.


#include "Indentificador.h"

// Sets default values for this component's properties
UIndentificador::UIndentificador()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UIndentificador::BeginPlay()
{
	Super::BeginPlay();
	if (num == 1) {
		nombre = "silla";
		name = "chair";
	}
	
	if (num == 2) {
		nombre = "mesa";
		name = "table";
	}
	MostrarNombre();
	// ...
	
}


// Called every frame
void UIndentificador::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UIndentificador::MostrarNombre() {
	UE_LOG(LogTemp, Warning, TEXT("Nombre en español: %s Nombre en ingles: %s"), *nombre, *name);

}
