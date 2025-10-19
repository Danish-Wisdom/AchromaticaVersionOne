// Fill out your copyright notice in the Description page of Project Settings.


#include "AchromaticaPlayerState.h"


AAchromaticaPlayerState::AAchromaticaPlayerState()
{
	SetNetUpdateFrequency(100.f);
	SetMinNetUpdateFrequency(66.f);

	AbilitySystem = CreateDefaultSubobject<UAchromaticaASC>(TEXT("AbilitySystemComponent"));
	AbilitySystem->SetIsReplicated(true);
	AbilitySystem->SetReplicationMode(AscReplicationMode);

	AttributeSet = CreateDefaultSubobject<UAchromaticaAttributeSet>(TEXT("AttributeSet"));
	
}

UAbilitySystemComponent* AAchromaticaPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}
