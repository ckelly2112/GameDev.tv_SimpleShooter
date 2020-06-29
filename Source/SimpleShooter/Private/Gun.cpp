// Please visit www.chriskelly48th.ca for contact info


#include "Gun.h"
#include "DrawDebugHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
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

	AController* OwnerController = Cast<APawn>(GetOwner())->GetController();
	if(!ensure(OwnerController)){return;}

	FVector GunLocation(0);
	FRotator GunRotation(0);
	OwnerController->GetPlayerViewPoint(GunLocation, GunRotation);

	FVector End = GunLocation + GunRotation.Vector() * MaxRange;
	FHitResult BulletHit;

	if(GetWorld()->LineTraceSingleByChannel(BulletHit, GunLocation, End, ECollisionChannel::ECC_GameTraceChannel1))
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BulletContact, BulletHit.Location, (-GunRotation.Vector()).Rotation());
	}
}

