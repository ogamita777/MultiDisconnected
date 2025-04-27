#include "System/TestSubsystem.h"

#include "Debug/DebugDrawService.h"
#include "Engine/EngineBaseTypes.h"

UTestSubsystem::UTestSubsystem()
{
	static ConstructorHelpers::FObjectFinder<UFont> font(TEXT("/Engine/EngineFonts/Roboto"));
	FontObject = font.Object;
}

void UTestSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	auto drawDebugDelegate = FDebugDrawDelegate::CreateUObject(this, &UTestSubsystem::Draw);

	if (drawDebugDelegate.IsBound()) {
		this->DrawDebugDelegate = UDebugDrawService::Register(TEXT("GameplayDebug"), drawDebugDelegate);
	}
}

void UTestSubsystem::Deinitialize()
{
	if (DrawDebugDelegate.IsValid()) {
		UDebugDrawService::Unregister(DrawDebugDelegate);
		DrawDebugDelegate.Reset();
	}
}

void UTestSubsystem::AddPlayer(const FPlayerInfo& playerInfo)
{
	PlayerInfoList.Add(playerInfo);

	// PlayerIdÇ≈è∏èáÇ…ï¿Ç◊ÇÈ
	PlayerInfoList.Sort([](const FPlayerInfo& left, const FPlayerInfo& right) { return left.PlayerId < right.PlayerId; });
}

void UTestSubsystem::Draw(UCanvas* InCanvas, APlayerController* InPC)
{
	if (!InCanvas || !InCanvas->Canvas) {
		return;
	}

	// WorldPartitionSubsystem.cpp ÇéQçlÇ…ï WorldÇÃèÍçáÇÕï`âÊÇµÇ»Ç¢ÇÊÇ§Ç…
	if (!GetWorld()->IsNetMode(NM_DedicatedServer) &&
		(InCanvas->SceneView->ViewActor == nullptr || InCanvas->SceneView->ViewActor->GetWorld() != GetWorld()))
	{
		return;
	}

	FString playerInfoText = TEXT("");

	for (const FPlayerInfo& playerInfo : PlayerInfoList)
	{
		playerInfoText += FString::Printf(TEXT("=====PlayerId:%d=====\n"), playerInfo.PlayerId);
		playerInfoText += FString::Printf(TEXT("PlayerState:%s\n"), IsValid(playerInfo.PlayerState) ? *(playerInfo.PlayerState->GetActorNameOrLabel()) : TEXT("IsValid() false"));
		playerInfoText += FString::Printf(TEXT("Controller:%s\n"), IsValid(playerInfo.Controller) ? *(playerInfo.Controller->GetActorNameOrLabel()) : TEXT("IsValid() false"));
		playerInfoText += FString::Printf(TEXT("Pawn:%s\n"), IsValid(playerInfo.Pawn) ? *(playerInfo.Pawn->GetActorNameOrLabel()) : TEXT("IsValid() false"));
		playerInfoText += TEXT("\n");
	}

	if (playerInfoText.IsEmpty())
	{
		return;
	}

	FString displayText = TEXT("");

	// NetModeÇÃï\é¶
	{
		static const TCHAR* NETMODE_STRING[] = {
			TEXT("NM_Standalone"),
			TEXT("NM_DedicatedServer"),
			TEXT("NM_ListenServer"),
			TEXT("NM_Client"),
		};
	
		displayText += FString::Printf(TEXT("%s\n\n"), NETMODE_STRING[GetWorld()->GetNetMode()]);
	}
	
	displayText += playerInfoText;

	InCanvas->K2_DrawText(FontObject, displayText, FVector2D(0.0f, 0.0f), FVector2D(1.0f, 1.0f), FLinearColor::Black);
}
