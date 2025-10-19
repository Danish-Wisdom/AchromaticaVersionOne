// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"

#include "AchromaticaAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class ACHROMATICA_API UAchromaticaAttributeSet : public UAttributeSet
{
	GENERATED_BODY()


public:
	UAchromaticaAttributeSet();


	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& MyData) override;

	// Health Attributes
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing= OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS_BASIC(UAchromaticaAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing= OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS_BASIC(UAchromaticaAttributeSet, MaxHealth);



	
	// Stamina Attributes
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing= OnRep_Stamina)
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS_BASIC(UAchromaticaAttributeSet, Stamina);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing= OnRep_MaxStamina)
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS_BASIC(UAchromaticaAttributeSet, MaxStamina);

private:
	// Health RepNotify functions
	UFUNCTION(Category = "Attributes")
	void OnRep_Health(const FGameplayAttributeData& OldValue) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UAchromaticaAttributeSet, Health, OldValue);
	}

	UFUNCTION(Category = "Attributes")
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UAchromaticaAttributeSet, MaxHealth, OldValue);
	}



	// Stamina RepNotify functions
	UFUNCTION(Category = "Attributes")
	void OnRep_Stamina(const FGameplayAttributeData& OldValue) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UAchromaticaAttributeSet, Stamina, OldValue);
	}

	UFUNCTION(Category = "Attributes")
	void OnRep_MaxStamina(const FGameplayAttributeData& OldValue) const
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UAchromaticaAttributeSet, MaxStamina, OldValue);
	}
	
};
