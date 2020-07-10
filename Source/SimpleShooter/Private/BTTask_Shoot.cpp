// Please visit www.chriskelly48th.ca for contact info


#include "BTTask_Shoot.h"
#include "AIController.h"
#include "ShooterCharacter.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = "Shoot";
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (!OwnerComp.GetAIOwner()) { return EBTNodeResult::Failed; }
	AShooterCharacter* OwnerCharacter = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (!OwnerCharacter) { return EBTNodeResult::Failed; }
	OwnerCharacter->FireGun();
	return EBTNodeResult::Succeeded;
}
