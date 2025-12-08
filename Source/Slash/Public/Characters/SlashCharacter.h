// copyright: none

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "SlashCharacter.generated.h"

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
	
	// Input Functions
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	
private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;
	
	UPROPERTY(VisibleAnywhere,Category=Groom)
	UGroomComponent* Hair;
	
	UPROPERTY(VisibleAnywhere,Category=Groom)	
	UGroomComponent* Eyebrows;
};
