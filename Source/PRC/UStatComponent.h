// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UStatComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCollectibleCountChanged, int32, NewCount);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRC_API UUStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float MoveSpeedMultiplier = 1.f;
	UPROPERTY(BlueprintReadOnly)
	int32 CollectibleCount = 0;
	UPROPERTY(BlueprintAssignable)
	FOnCollectibleCountChanged OnCollectibleCountChanged;
	float GetMoveSpeed(float BaseSpeed) const;
	void AddCollectible(int32 Amount = 1);



	// Sets default values for this component's properties
	UUStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
