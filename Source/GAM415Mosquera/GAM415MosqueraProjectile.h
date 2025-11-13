// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GAM415MosqueraProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraSystem;

UCLASS(config=Game)
class AGAM415MosqueraProjectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	/** Initialize projectile mesh */
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* ballMesh;

	/** Initialize splatter material */
	UPROPERTY(EditAnywhere)
		UMaterial* baseMat;

	/** Initialize random color variable */
	UPROPERTY()
		FLinearColor randColor;

	/** Initialize projectile material */
	UPROPERTY(EditAnywhere)
		UMaterialInterface* projMat;

	/** Initialize projectile material reference */
	UPROPERTY()
		UMaterialInstanceDynamic* dmiMat;

	/** Initialize color variable for the niagara system */
	UPROPERTY(EditAnywhere)
		UNiagaraSystem* colorP;

public:
	AGAM415MosqueraProjectile();

protected:
	virtual void BeginPlay();

public:
	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};

