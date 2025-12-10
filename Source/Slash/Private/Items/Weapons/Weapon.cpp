// copyright: none


#include "Items/Weapons/Weapon.h"

#include "Characters/SlashCharacter.h"


// Sets default values
AWeapon::AWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeapon::OnSphereOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereOverlap(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void AWeapon::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnSphereEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}

void AWeapon::Interact(ASlashCharacter* Caller)
{
	FAttachmentTransformRules Rules(EAttachmentRule::SnapToTarget,true);
	ItemMesh->AttachToComponent(Caller->GetMesh(),Rules,FName("RightHandSocket"));
}

void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

