﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GA_Test.generated.h"

/**
 * 
 */
UCLASS()
class ACHROMATICA_API UGA_Test : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_Test();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	static FVector GetDodgeDirection(const FGameplayAbilityActorInfo* ActorInfo);
	static float GetMaxSpeed(const FGameplayAbilityActorInfo* ActorInfo);
};
