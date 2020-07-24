// Please visit www.chriskelly48th.ca for contact info

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaTime) override;
	bool IsDead() const;

protected:
	virtual void BeginPlay() override;


private:

	//UPROPERTY(EditDefaultsOnly)
	//float AcceptanceRadius = 300.f;

	APawn* Player = nullptr;
	APawn* ControlledPawn = nullptr;

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
};
