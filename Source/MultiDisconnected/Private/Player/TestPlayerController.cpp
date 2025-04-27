#include "Player/TestPlayerController.h"
#include "TestDefine.h"

void ATestPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		UE_LOG(LogAuthority, Log, TEXT("BeginPlay()"));
	}
	else
	{
		UE_LOG(LogClient, Log, TEXT("BeginPlay()"));
	}

	DebugLog();
}

void ATestPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DebugLog();
}

void ATestPlayerController::DebugLog()
{
	FString debugString = TEXT("");

	debugString += FString::Printf(TEXT("%s"), HasAuthority() ? TEXT("[Authority]") : TEXT("[Client]"));

	debugString += FString::Printf(TEXT(", PlayerController: %s"), *GetActorNameOrLabel());
	debugString += FString::Printf(TEXT(", LocalRole: %s"), *UEnum::GetDisplayValueAsText(GetLocalRole()).ToString());
	debugString += FString::Printf(TEXT(", IsLocalController(): %s"), IsLocalController() ? TEXT("true") : TEXT("false"));

	if (HasAuthority())
	{
		UE_LOG(LogAuthority, Log, TEXT("%s"), *debugString);
	}
	else
	{
		UE_LOG(LogClient, Log, TEXT("%s"), *debugString);
	}
}