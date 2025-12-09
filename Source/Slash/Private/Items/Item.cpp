// copyright: none


#include "Items/Item.h"

#include "Components/SphereComponent.h"
#include "Slash/DebugMacro.h"

// Sets default values
AItem::AItem()
	: RunningTime(0.f), Amplitude(0.5f), TimeConstant(2.f) 
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
	
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());

}

float AItem::TransformedSine() const
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCosine() const
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

// Called when the game starts or when spawned
void AItem::BeginPlay() 
{
	Super::BeginPlay();
	
	UWorld* World = GetWorld(); // Get the world pointer that this actor is in
	
	SetActorRotation(FRotator(0.f,45.f,0.f));
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

}

