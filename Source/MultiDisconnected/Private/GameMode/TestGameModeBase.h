#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TestGameModeBase.generated.h"

UCLASS()
class ATestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATestGameModeBase();

public:
	virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

	UPROPERTY(Transient, EditDefaultsOnly, Category = "TestGameMode")
	TArray<FName> PlayerStartTagList;

private:
	int32 m_spawnIndex;
};
