// Please visit www.chriskelly48th.ca for contact info


#include "EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	ControlledPawn = GetPawn();
	if (!ensure(AIBehavior)) { return; }
	RunBehaviorTree(AIBehavior);
	GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), ControlledPawn->GetActorLocation());
}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!ensure(Player)) { return; }
	if (LineOfSightTo(Player))
	{
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), Player->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownLocation"), Player->GetActorLocation());

		//Set PlayerLocation
		//Set LastKnownLocation
	}
	else
	{
		//Clear PlayerLocation
		GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
	}

}
