// Please visit www.chriskelly48th.ca for contact info

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	AController* OwnerController = nullptr;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere) // TODO Change to Defaults during production
	UParticleSystem* MuzzleFlash = nullptr;
	UPROPERTY(EditAnywhere)
	USoundBase* MuzzleSound = nullptr;

	UPROPERTY(EditAnywhere)
	UParticleSystem* BulletContact = nullptr;
	UPROPERTY(EditAnywhere)
	USoundBase* ContactSound = nullptr;
	
	UPROPERTY(EditAnywhere)
	float Damage = 10.f;
	
	UPROPERTY(EditDefaultsOnly)
	float MaxRange = 1000.f;

	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);
	AController* GetOwnerController() const;

};
