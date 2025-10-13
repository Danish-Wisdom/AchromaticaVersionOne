// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Achromatica/GameplayAbilitySystem/AbilitySystemComponent/AchromaticaASC.h"
#include "Achromatica/GameplayAbilitySystem/AttributeSets/AchromaticaAttributeSet.h"
#include "GameFramework/Character.h"
#include "AchromaticaCharacter.generated.h"

UCLASS()
class ACHROMATICA_API AAchromaticaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAchromaticaCharacter();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilitySystem")
	EGameplayEffectReplicationMode AscReplicationMode = EGameplayEffectReplicationMode::Mixed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TObjectPtr<UAchromaticaASC> AbilitySystem;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TObjectPtr<UAchromaticaAttributeSet> AttributeSet;

	void InitAbilityActorInfo();
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
