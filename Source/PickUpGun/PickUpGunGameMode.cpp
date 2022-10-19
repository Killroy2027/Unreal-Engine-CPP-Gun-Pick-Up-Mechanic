// Copyright Epic Games, Inc. All Rights Reserved.

#include "PickUpGunGameMode.h"
#include "PickUpGunCharacter.h"
#include "UObject/ConstructorHelpers.h"

APickUpGunGameMode::APickUpGunGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
