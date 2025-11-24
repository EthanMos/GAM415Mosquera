// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcPlane.h"
#include "ProceduralMeshComponent.h"

// Sets default values
AProcPlane::AProcPlane()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create mesh
	procMesh = CreateDefaultSubobject<UProceduralMeshComponent>("Proc Mesh");
	
}

// Called when the game starts or when spawned
void AProcPlane::BeginPlay()
{
	Super::BeginPlay();
	
}

// Call upon creation
void AProcPlane::PostActorCreated()
{
	Super::PostActorCreated();
	CreateMesh();

	// Set material if it exists
	if (PlaneMat)
	{
		procMesh->SetMaterial(0, PlaneMat);

	}
}

void AProcPlane::PostLoad()
{
	Super::PostLoad();
	CreateMesh();

	// Set material if it exists
	if (PlaneMat)
	{
		procMesh->SetMaterial(0, PlaneMat);

	}
}

// Called every frame
void AProcPlane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Define procedurl mesh
void AProcPlane::CreateMesh()
{
	procMesh->CreateMeshSection(0, Vertices, Triangles, TArray<FVector>(), UV0, TArray<FColor>(), TArray<FProcMeshTangent>(), true);

}

