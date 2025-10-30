// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAM415MosqueraGameMode.h"
#include "GAM415MosqueraCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGAM415MosqueraGameMode::AGAM415MosqueraGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
