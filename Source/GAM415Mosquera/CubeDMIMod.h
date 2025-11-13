// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "CubeDMIMod.generated.h"

class UNiagaraSystem;

UCLASS()
class GAM415MOSQUERA_API ACubeDMIMod : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeDMIMod();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Initialize box collision
	UPROPERTY(EditAnywhere)
		UBoxComponent* boxComp;

	// Initialize mesh
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* cubeMesh;

	// Initialize material
	UPROPERTY(EditAnywhere)
		UMaterialInterface* baseMat;

	// Initalize material reference
	UPROPERTY()
		UMaterialInstanceDynamic* dmiMat;

	// Initialize color variable for the niagara system 
	UPROPERTY(EditAnywhere)
		UNiagaraSystem* colorP;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
