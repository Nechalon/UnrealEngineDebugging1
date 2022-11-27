// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/GridPanel.h"
#include "Components/UniformGridPanel.h"
#include "Components/TextBlock.h"
#include "Engine/Texture2D.h"
#include "Containers/Array.h"
#include "Components/UniformGridSlot.h"
#include "UI/Inventory/CPP_InventoryBarSlot.h"
#include "CPP_InventoryBar.generated.h"


class UImage;
class UUniformGridPanel;
class CPP_InventoryBarSlot;
class CPP_InventoryBar;
class UTexture2D;
/**
 * 
 */
UCLASS()
class ORANGEBOG_API UCPP_InventoryBar : public UUserWidget
{
	GENERATED_BODY()

protected:


public:
	void NativeConstruct() override;
	void AddInventoryBarSlots();
	void UpdateInventoryBarSlot(UTexture2D* NormalImage);
	UPROPERTY( meta = (BindWidget))
	UImage* InventoryBarFrame;
	UPROPERTY( meta = (BindWidget))
	UUniformGridPanel* InventoryBarSlotPanel;

	UPROPERTY()
	float test;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UCPP_InventoryBarSlot> InventoryBarSlotClass;
	UPROPERTY()
	TArray<UCPP_InventoryBarSlot*> InventoryBarSlots;
	UPROPERTY()
	UCPP_InventoryBarSlot* InventoryBarSlot;
};

