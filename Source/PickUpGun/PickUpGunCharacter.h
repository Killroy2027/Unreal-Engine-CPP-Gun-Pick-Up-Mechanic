// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Weapon.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PickUpGunCharacter.generated.h"

UCLASS(config=Game)
class APickUpGunCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;


public:
	APickUpGunCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UFUNCTION(BlueprintImplementableEvent)
	void CreateUI();

	UFUNCTION(BlueprintImplementableEvent)
	void DestroyUI();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsHolding = false;

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite)
	AWeapon* Weapon;

	UPROPERTY(EditAnywhere)
	USkeletalMesh* FirstModeSkeletalMesh;

	UPROPERTY(EditAnywhere)
	USkeletalMesh* SecondModeSkeletalMesh;

	UPROPERTY(EditAnywhere)
	UClass* FirstModeAnimClass;
	
	UPROPERTY(EditAnywhere)
	UClass* SecondModeAnimClass;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* AimingMesh;
	
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* AimingBoom;

	void SetBulletRotation();


	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	void PickUp();

	void Drop();

	void FireGun();

	void ReloadGun();

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

