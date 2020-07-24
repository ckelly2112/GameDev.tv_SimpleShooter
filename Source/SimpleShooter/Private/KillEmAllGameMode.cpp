// Please visit www.chriskelly48th.ca for contact info


#include "KillEmAllGameMode.h"
#include "AIController.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);
	
	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if (PlayerController)
	{
		EndGame(false);
	}

	for (AAIController* AIControllers : TActorRange<AAIController>(GetWorld()))
	{
		if (AIControllers)
		{
			return;
		}
	}

	EndGame(true);
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);

	}
}
