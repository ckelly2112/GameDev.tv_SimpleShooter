// Please visit www.chriskelly48th.ca for contact info


#include "ShooterPlayerController.h"
#include "TimerManager.h"

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
	UE_LOG(LogTemp, Error, TEXT("YOU DIED"));

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}