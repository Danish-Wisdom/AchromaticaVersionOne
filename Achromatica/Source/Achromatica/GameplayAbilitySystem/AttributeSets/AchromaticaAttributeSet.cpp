// Fill out your copyright notice in the Description page of Project Settings.


#include "AchromaticaAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UAchromaticaAttributeSet::UAchromaticaAttributeSet()
{
	
}

void UAchromaticaAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAchromaticaAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAchromaticaAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAchromaticaAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAchromaticaAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
	
}

void UAchromaticaAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& MyData)
{
	Super::PostGameplayEffectExecute(MyData);

	// Refactor Later

	if (MyData.EvaluatedData.Attribute == GetHealthAttribute())
	{
		// Clamp Health between 0 and MaxHealth
		SetHealth(FMath::Clamp(Health.GetCurrentValue(), 0.f, GetMaxHealth()));
	}

	if (MyData.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		// Clamp Stamina between 0 and MaxStamina
		SetStamina(FMath::Clamp(Stamina.GetCurrentValue(), 0.f, GetMaxStamina()));
	}
	
}