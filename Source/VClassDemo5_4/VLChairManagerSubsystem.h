// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "VLChair.h"
#include "VLChairManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class VCLASSDEMO5_4_API UVLChairManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable)
	AVLChair* GetChairByName(FString name);

	UPROPERTY(EditAnywhere)
	TMap<FString, AVLChair*> ChairMap;
};
