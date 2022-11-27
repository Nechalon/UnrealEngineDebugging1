// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/Image.h"
#include "Engine/Texture2D.h"
#include "Engine/GameEngine.h"
#include "Containers/Array.h"
#include "UI/Inventory/CPP_InventoryBar.h"
#include "Interface/CPP_InteractInterface.h"
#include "Character/CH_LynchCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "CPP_InteractBase.generated.h"


class UStaticMeshComponent;
class USphereComponent;
class ACH_LynchCharacter;
class UCPP_InventoryBar;
class UImage;
class UTexture2D;
class UCPP_InventoryBar;


UENUM(BlueprintType)
enum EPickUpType
{
	None UMETA(DisplayName = "Unknown"),
	LightSource UMETA(DisplayName = "LightSource"),
	Food UMETA(DisplayName = "Food")
};

USTRUCT(BlueprintType)
struct FItemInfo
{
	GENERATED_USTRUCT_BODY();
	
public: 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EPickUpType> Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Weight = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ACPP_InteractBase> Class;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Index = 0;
};

UCLASS()
class ORANGEBOG_API ACPP_InteractBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_InteractBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Interactable;
	UPROPERTY(EditAnywhere)
	USphereComponent* Interact;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UCPP_InventoryBar> InventoryBarClass;

	UPROPERTY()
	UCPP_InventoryBar* TestInvBar;
	ACH_LynchCharacter* LynchCharacter;

	void Pickup();
	void GetPlayer(AActor* Player);

	bool bItemInRange = false;
	

	UFUNCTION()
	void OverlapBeginInteractable(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OverlapEndInteractable(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	FItemInfo ItemInfo;
};

