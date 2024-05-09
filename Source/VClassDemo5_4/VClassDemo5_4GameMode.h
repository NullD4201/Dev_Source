// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "VClassDemo5_4GameMode.generated.h"

UCLASS()
class AVClassDemo5_4GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AVClassDemo5_4GameMode();

	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
};



