#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"

#include "GameFramework/PlayerState.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Engine/Canvas.h"

#include "TestSubsystem.generated.h"

USTRUCT()
struct FPlayerInfo
{
	GENERATED_BODY()

	FPlayerInfo()
		: PlayerId(INDEX_NONE)
		, PlayerState(nullptr)
		, Controller(nullptr)
		, Pawn(nullptr)
	{}

public:
	UPROPERTY()
	int32 PlayerId;

	UPROPERTY()
	APlayerState* PlayerState;

	UPROPERTY()
	AController* Controller;

	UPROPERTY()
	APawn* Pawn;
};

UCLASS()
class UTestSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
	UTestSubsystem();

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection);
	virtual void Deinitialize();

public:
	void AddPlayer(const FPlayerInfo& playerInfo);

private:
	void Draw(UCanvas* InCanvas, APlayerController* InPC);

private:
	FDelegateHandle DrawDebugDelegate;

	UPROPERTY(Transient)
	class UFont* FontObject;

	UPROPERTY()
	TArray<FPlayerInfo> PlayerInfoList;
};
