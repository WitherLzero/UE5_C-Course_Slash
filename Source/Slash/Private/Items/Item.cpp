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

void AItem::OnSphereOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const FString OverlapActorName = OtherActor->GetName();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1,30.f,FColor::Red,
		FString::Printf(TEXT("Overlap Actor Name: %s"),*OverlapActorName));
	}
}

void AItem::OnTestSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	const FString EndOverlapCompName = OtherComp->GetName();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(2, 30.f, FColor::Red,
			FString::Printf(TEXT("End Overlap Comp Name: %s"), *EndOverlapCompName));
	}
}

// Called when the game starts or when spawned
void AItem::BeginPlay() 
{
	Super::BeginPlay();
	
	// Bind the callback to the delegate
	Sphere->SetGenerateOverlapEvents(true);
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AItem::OnTestSphereEndOverlap);
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

}

