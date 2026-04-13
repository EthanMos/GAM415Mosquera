// Fill out your copyright notice in the Description page of Project Settings.


#include "PerlinProcTerrain.h"
#include "KismetProceduralMeshLibrary.h"

// Sets default values
APerlinProcTerrain::APerlinProcTerrain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create mesh
	procMesh = CreateDefaultSubobject<UProceduralMeshComponent>("Proc Mesh");
	RootComponent = procMesh;

}

void APerlinProcTerrain::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);


}

// Called when the game starts or when spawned
void APerlinProcTerrain::BeginPlay()
{
	Super::BeginPlay();

	// Create plane
	CreateVertices();
	CreateTriangles();
	procMesh->CreateMeshSection(sectionID, Vertices, Triangles, Normals, UV0, UpVertexColors, Tangents, true);
	procMesh->SetMaterial(0, Mat);

}

// Called every frame
void APerlinProcTerrain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APerlinProcTerrain::AlterMesh(FVector impactPoint)
{
	// Update mesh section using altered vertices
	for (int i = 0; i < Vertices.Num(); i++)
	{
		FVector tempVector = impactPoint - this->GetActorLocation();

		if (FVector(Vertices[i] - tempVector).Size() < radius)
		{
			float Dist = FVector(OriginalVertices[i] - tempVector).Size();

			if (Dist < radius)
			{
				float Falloff = 1.0f - (Dist / radius);
				Falloff = FMath::Clamp(Falloff, 0.0f, 1.0f);

				AccumulatedDepth[i] += Depth * Falloff;

				Vertices[i] = OriginalVertices[i] - AccumulatedDepth[i];
			}
		}
	}
	procMesh->UpdateMeshSection(sectionID, Vertices, Normals, UV0, UpVertexColors, Tangents);

}

void APerlinProcTerrain::CreateVertices()
{
	// Loop to add Vertices and UVs according to size
	for (int X = 0; X <= XSize; X++)
	{
		for (int Y = 0; Y <= YSize; Y++)
		{
			float Z = FMath::PerlinNoise2D(FVector2D(X * NoiseScale + 0.1, Y * NoiseScale + 0.1)) * ZMultiplier;
			Vertices.Add(FVector(X * Scale, Y * Scale, Z));
			UV0.Add(FVector2D(X * UVScale, Y * UVScale));


		}
	}
	AccumulatedDepth.SetNum(Vertices.Num());

	for (int i = 0; i < AccumulatedDepth.Num(); i++)
	{
		AccumulatedDepth[i] = FVector::ZeroVector;
	}
	OriginalVertices = Vertices;

}

void APerlinProcTerrain::CreateTriangles()
{
	// Loop to add triangles and count vertices
	int Vertex = 0;
	
	for (int X = 0; X < XSize; X++)
	{
		for (int Y = 0; Y < YSize; Y++)
		{
			Triangles.Add(Vertex);
			Triangles.Add(Vertex + 1);
			Triangles.Add(Vertex + YSize + 1);
			Triangles.Add(Vertex + 1);
			Triangles.Add(Vertex + YSize + 2);
			Triangles.Add(Vertex + YSize + 1);

			Vertex++;

		}

		Vertex++;

	}
}

