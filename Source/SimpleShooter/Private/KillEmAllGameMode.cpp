// Please visit www.chriskelly48th.ca for contact info


#include "KillEmAllGameMode.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);
	UE_LOG(LogTemp, Error, TEXT("Pawn %s Was Killed!"), *PawnKilled->GetName());
}
