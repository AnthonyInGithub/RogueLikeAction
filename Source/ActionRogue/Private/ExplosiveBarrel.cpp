// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosiveBarrel.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"


// Sets default values
AExplosiveBarrel::AExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BarrelMesh = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	RootComponent = BarrelMesh;
	BarrelMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BarrelMesh->SetCollisionObjectType(ECC_WorldStatic);
	BarrelMesh->SetCollisionResponseToAllChannels(ECR_Block);
	BarrelMesh->SetNotifyRigidBodyCollision(true);
	BarrelMesh->OnComponentHit.AddDynamic(this, &AExplosiveBarrel::OnActorHit);

    RadialForceComp = CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForceComp"));
    RadialForceComp->SetupAttachment(RootComponent);

    // Radius of effect
    RadialForceComp->Radius = 600.f;

    // Strength of impulse
    RadialForceComp->ImpulseStrength = 2000.f;

    // velocity change = ignore mass (like explosion)
    RadialForceComp->bImpulseVelChange = true;

    // Only affect physics bodies
    RadialForceComp->AddCollisionChannelToAffect(ECC_PhysicsBody);

    // We will trigger it manually
    RadialForceComp->bAutoActivate = false;
    RadialForceComp->bIgnoreOwningActor = true;


}

// Called when the game starts or when spawned
void AExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AExplosiveBarrel::OnActorHit(
    UPrimitiveComponent* HitComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    FVector NormalImpulse,
    const FHitResult& Hit)
{
    RadialForceComp->FireImpulse();
}