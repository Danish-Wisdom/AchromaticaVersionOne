// Fill out your copyright notice in the Description page of Project Settings.


#include "GA_Test.h"
#include "Abilities/Tasks/AbilityTask_ApplyRootMotionConstantForce.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/RootMotionSource.h"

UGA_Test::UGA_Test()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UGA_Test::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	CommitAbilityCost(Handle, ActorInfo, ActivationInfo);

	// Example: Apply a root motion force to the character
	UAbilityTask_ApplyRootMotionConstantForce* RootMotionTask = UAbilityTask_ApplyRootMotionConstantForce::ApplyRootMotionConstantForce(
		this,
		NAME_None,
		FVector(1000.f, 0.f, 0.f), // Force direction
		1250.f, // Strength
		0.3f, // Duration
		false, // bIsAdditive
		nullptr,
		ERootMotionFinishVelocityMode::ClampVelocity, // Velocity Mode
		FVector::ZeroVector, // Set Velocity On Finish
		0.f, // Clamp Velocity On Finish
		false // Enable Gravity
	);

	if (RootMotionTask != nullptr){ RootMotionTask->ReadyForActivation(); }
	
	

	CommitAbilityCooldown(Handle, ActorInfo, ActivationInfo, false);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

FVector UGA_Test::GetDodgeDirection(const FGameplayAbilityActorInfo* ActorInfo)
{
	// Implement dodge direction logic here
	FVector DodgeDirection(0.f);
	APawn* ActorPawn = CastChecked<APawn>(ActorInfo->OwnerActor.Get());

	if (ActorPawn != nullptr)
	{
		if (ActorPawn->GetLastMovementInputVector() != FVector::ZeroVector)
		{
			// Use the last movement input vector as the dodge direction
			DodgeDirection = ActorPawn->GetLastMovementInputVector().GetSafeNormal();
		}
		else
		{
			// If there's no movement input, use the actor's forward vector
			DodgeDirection = ActorPawn->GetActorForwardVector();
		}

		return DodgeDirection;
	}

	return ActorPawn->GetActorForwardVector();
}

float UGA_Test::GetMaxSpeed(const FGameplayAbilityActorInfo* ActorInfo)
{
	// Implement max speed logic here
	float MaxSpeed = 500.f;
	APawn* ActorPawn = CastChecked<APawn>(ActorInfo->OwnerActor.Get());

	if (ActorPawn != nullptr)
	{
		MaxSpeed = ActorPawn->GetMovementComponent()->GetMaxSpeed();

		return MaxSpeed;
	}



	return MaxSpeed;
}