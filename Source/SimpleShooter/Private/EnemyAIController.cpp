// Please visit www.chriskelly48th.ca for contact info


#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	//Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (!ensure(AIBehavior)) { return; }
	RunBehaviorTree(AIBehavior);
}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (!ensure(Player)) { return; }
	//if (LineOfSightTo(Player))
	//{
	//	SetFocus(Player, EAIFocusPriority::Gameplay);
	//	MoveToActor(Player, AcceptanceRadius, false, true, true);
	//}
	//else
	//{
	//	ClearFocus(EAIFocusPriority::Gameplay);
	//	StopMovement();
	//}

}
