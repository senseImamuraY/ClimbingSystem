// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CustomMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class CLIMBINGSYSTEM_API UCustomMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction);

private:

#pragma region ClimbTraces
	TArray<FHitResult> DoCapsuleTraceMultiByObject(const FVector& Start, const FVector& End, bool bShowDebugShape = false);
	FHitResult DoLineTraceSingleByObject(const FVector& Start, const FVector& End, bool bShowDebugShape = false);

#pragma endregion

#pragma region ClimbCore

	void TraceClimbableSurfaces();

	void TraceFromEyeHeight(float TraceDistance, float TraceStartOffset = 0.f);

	bool CanStartClimbing();

#pragma endregion



#pragma region ClimVariables

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Movement: Climbing", meta = (AllowPrivateAccess = "true"))
	TArray<TEnumAsByte<EObjectTypeQuery>> ClimbableSurfaceTraceTypes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Movement: Climbing", meta = (AllowPrivateAccess = "true"))
	float ClimbCapsuleTraceRadius = 50.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character Movement: Climbing", meta = (AllowPrivateAccess = "true"))
	float ClimbCapsuleTraceHalfHeight = 72.f;

#pragma endregion

public:
	void ToggleClimbing(bool bEnableClimb);
	bool IsClimbing() const;
};
