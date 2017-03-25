// Copyright Kyle Norburn (C) 2017

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
	void OpenDoor();
	void CloseDoor();
	float GetTotalMassOnPlate();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
	UPROPERTY(EditAnywhere) float OpenAngle = 80.0f;
	UPROPERTY(EditAnywhere) ATriggerVolume* PressurePlate;
	UPROPERTY(EditAnywhere) float DoorCloseDelay = 1.f;
	UPROPERTY(EditAnywhere) float TriggerMass = 40.f;

	float LastDoorOpenTime;

	AActor* Owner; // The owning door
};
