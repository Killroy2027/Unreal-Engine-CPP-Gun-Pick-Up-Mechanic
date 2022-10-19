// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

class AProjectile;
class UCapsuleComponent;

UCLASS()
class PICKUPGUN_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	UPROPERTY(BlueprintReadWrite)
	FRotator BulletRotation;

	UPROPERTY(Category=Ammo, EditAnywhere)
	float ReloadTime = 0.5f;

	UPROPERTY(Category=Ammo, EditAnywhere, BlueprintReadWrite)
	int TotalAmmoCount = 20;

	UPROPERTY(Category=Ammo, EditAnywhere, BlueprintReadWrite)
	int CurrentAmmoCount = TotalAmmoCount;

	FTransform GetSocketTransform(FName SocketName) const { return WeaponMesh->GetSocketTransform(SocketName);}

	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Category=Weapon, EditAnywhere)
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(Category=Collision, EditAnywhere)
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(Category = BulletType,EditAnywhere)
	TSubclassOf<AProjectile> BulletType;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Fire();
	void Reload();
};
