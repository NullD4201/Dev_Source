// Copyright Epic Games, Inc. All Rights Reserved.

#include "VClassDemo5_4GameMode.h"
#include "VClassDemo5_4Character.h"
#include "UObject/ConstructorHelpers.h"

AVClassDemo5_4GameMode::AVClassDemo5_4GameMode()
{

}

void AVClassDemo5_4GameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) {
	//Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *Options);
}
