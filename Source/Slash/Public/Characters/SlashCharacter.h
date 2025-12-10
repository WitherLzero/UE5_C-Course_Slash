// copyright: none

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "SlashCharacter.generated.h"

class AItem;
class UCameraComponent;
class USpringArmComponent;
class UGroomComponent;

class UInputMappingContext;
class UInputAction;

UCLASS()
class SLASH_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	virtual void BeginPlay() override;
	
	// Input Assets
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* EchoMappingContext;
	
	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;
	
	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* LookAction;
	
	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* JumpAction;
	
	UPROPERTY(editanywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* InteractAction;
	
	// Input Functions
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	virtual void Jump() override;
	void Interact();
	
private:
	// Components
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;
	
	UPROPERTY(VisibleAnywhere,Category=Groom)
	UGroomComponent* Hair;
	
	UPROPERTY(VisibleAnywhere,Category=Groom)	
	UGroomComponent* Eyebrows;
	
	// Interactables
	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlappingItem;
	
public:
	FORCEINLINE void SetOverlappingItem(AItem* NewItem) { OverlappingItem = NewItem; }
};
