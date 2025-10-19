// Fill out your copyright notice in the Description page of Project Settings.


#include "AchromaticaCharacter.h"

#include "Achromatica/Game/PlayerState/AchromaticaPlayerState.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AAchromaticaCharacter::AAchromaticaCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(35.f, 90.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.f;

}

// Called when the game starts or when spawned
void AAchromaticaCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAchromaticaCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (HasAuthority())
	{
		InitAbilityActorInfo();
	}
}

void AAchromaticaCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilityActorInfo();
}

void AAchromaticaCharacter::InitAbilityActorInfo()
{
	if (AAchromaticaPlayerState* AchromaticaPlayerState = GetPlayerState<AAchromaticaPlayerState>())
	{
		AbilitySystem = AchromaticaPlayerState->GetAchromaticaASC();
		AttributeSet = AchromaticaPlayerState->GetAchromaticaAttributeSet();

		if (IsValid(AbilitySystem))
		{
			AbilitySystem->InitAbilityActorInfo(AchromaticaPlayerState, this);
		}
	}
}

// Called every frame
void AAchromaticaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAchromaticaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

