// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Achromatica/GameplayAbilitySystem/AbilitySystemComponent/AchromaticaASC.h"
#include "Achromatica/GameplayAbilitySystem/AttributeSets/AchromaticaAttributeSet.h"
#include "GameFramework/PlayerState.h"
#include "AchromaticaPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ACHROMATICA_API AAchromaticaPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	AAchromaticaPlayerState();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintPure)
	UAchromaticaASC* GetAchromaticaASC() const
	{
		return AbilitySystem;
	}

	UFUNCTION(BlueprintPure)
	UAchromaticaAttributeSet* GetAchromaticaAttributeSet() const
	{
		return AttributeSet;
	}

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilitySystem")
	EGameplayEffectReplicationMode AscReplicationMode = EGameplayEffectReplicationMode::Mixed;

private:
	
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TObjectPtr<UAchromaticaASC> AbilitySystem;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TObjectPtr<UAchromaticaAttributeSet> AttributeSet;
};
