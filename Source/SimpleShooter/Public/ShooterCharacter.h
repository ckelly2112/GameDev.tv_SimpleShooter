// Please visit www.chriskelly48th.ca for contact info

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;
UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintPure)
	bool bIsDead() const;
	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	void FireGun();

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);

	UPROPERTY(EditAnywhere)
	float RotationRate = 10.f;
	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100.f;
	UPROPERTY(VisibleAnywhere)
	float CurrentHealth = MaxHealth; // Set again in BeginPlay


	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
	AGun* Gun = nullptr;
};
