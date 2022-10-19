// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Components/CapsuleComponent.h"
#include "Projectile.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision"));

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));

	WeaponMesh->SetupAttachment(RootComponent);

	CapsuleComponent->SetupAttachment(WeaponMesh);

}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::Fire()
{
	if(CurrentAmmoCount == 0) return;

	FTransform socketTransform = WeaponMesh->GetSocketTransform(FName("MuzzleSocket"));

	UWorld* const World = GetWorld();
	if(World)
	{
		FActorSpawnParameters Parameters;
		Parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		World->SpawnActor<AProjectile>(BulletType,socketTransform.GetLocation(),BulletRotation,Parameters);
	}

	--CurrentAmmoCount;

}

void AWeapon::Reload()
{
	CurrentAmmoCount = TotalAmmoCount;
}

