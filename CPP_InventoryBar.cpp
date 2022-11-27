// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Inventory/CPP_InventoryBar.h"

void UCPP_InventoryBar::NativeConstruct(){
    Super::NativeConstruct();

    test = 666.0f;
    AddInventoryBarSlots();
}
    
void UCPP_InventoryBar::AddInventoryBarSlots(){
    for(int i = 0; i <= 9; i++)
    {
        //UImage* InventoryBarSlot = NewObject<UImage>(UImage::StaticCLass());
        InventoryBarSlot = CreateWidget<UCPP_InventoryBarSlot>(GetWorld(),InventoryBarSlotClass);
        InventoryBarSlots.Add(InventoryBarSlot);
        //GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Orange,FString::Printf(TEXT("Slot: %d SlotName: %s"),i,InventoryBarSlot));
        InventoryBarSlotPanel->AddChildToUniformGrid(InventoryBarSlots[i],0,i);
    }
}

void UCPP_InventoryBar::UpdateInventoryBarSlot(UTexture2D* NormalImage){
    GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Orange,FString::Printf(TEXT("testFloat, %f"), test));
    if(InventoryBarSlot != nullptr){
        GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Orange,FString::Printf(TEXT("Not Null")));
    }
    else{
        GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Orange,FString::Printf(TEXT("Null")));
    }
    //InventoryBarSlots[0]->UpdateButtonNormalImage(NormalImage);
}

