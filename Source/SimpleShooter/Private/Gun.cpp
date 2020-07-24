// Please visit www.chriskelly48th.ca for contact info


#include "Gun.h"
#include "DrawDebugHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun Mesh"));
	Mesh->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));	
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlashSocket"));
	FHitResult BulletHit;
	FVector ShotDirection;
	if(GunTrace(BulletHit, ShotDirection))
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BulletContact, BulletHit.Location, ShotDirection.Rotation());
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), ContactSound, BulletHit.Location, ShotDirection.Rotation());
		AActor* ActorHit = BulletHit.GetActor();
		if(ActorHit)
		{
			FPointDamageEvent DamageEvent(Damage, BulletHit, ShotDirection, nullptr);
			ActorHit->TakeDamage(Damage, DamageEvent, OwnerController, this);
			UE_LOG(LogTemp, Warning, TEXT("Actor who just got SNIPED: %s"), *ActorHit->GetName());
		}
	}
}

bool AGun::GunTrace(FHitResult& Hit, FVector& ShotDirection)
{

	FVector GunLocation(0);
	FRotator GunRotation(0);
	OwnerController = GetOwnerController();
	if (!ensure(OwnerController)) { return false; }
	OwnerController->GetPlayerViewPoint(GunLocation, GunRotation);
	ShotDirection = -GunRotation.Vector();
	
	
	FVector End = GunLocation + GunRotation.Vector() * MaxRange;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());

	return GetWorld()->LineTraceSingleByChannel(Hit, GunLocation, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

AController* AGun::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (!ensure(OwnerPawn)) { return nullptr; }
	return Cast<AController>(OwnerPawn->GetController());
	
}