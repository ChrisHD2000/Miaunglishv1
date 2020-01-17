// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Indentificador.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MIAUNGLISHV1_API UIndentificador : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UIndentificador();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnywhere, Category = "ID de objeto")
	int num;
	FString nombre, name;
	void MostrarNombre();
};
