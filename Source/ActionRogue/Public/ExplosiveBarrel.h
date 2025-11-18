// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "ExplosiveBarrel.generated.h"

//class URadialForceComponent;
class UStaticMeshComponent;


UCLASS()
class ACTIONROGUE_API AExplosiveBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UStaticMeshComponent* BarrelMesh;
	UPROPERTY(VisibleAnywhere)
	URadialForceComponent* RadialForceComp;

	// Sets default values for this actor's properties
	AExplosiveBarrel();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnActorHit(
		UPrimitiveComponent* HitComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit
);



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;	


};
