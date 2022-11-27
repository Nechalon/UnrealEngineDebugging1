// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/CPP_InteractBase.h"

// Sets default values
ACPP_InteractBase::ACPP_InteractBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Interactable = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Interactable"));
	Interactable->SetupAttachment(RootComponent);
	Interactable->SetSimulatePhysics(true);
	Interact = CreateDefaultSubobject<USphereComponent>(TEXT("Interact"));
	Interact->SetupAttachment(Interactable);
	Interact->SetGenerateOverlapEvents(true);
	Interact->SetWorldScale3D(FVector(1.0f,1.0f,1.0f));

	//TestInvBar = CreateDefaultSubobject<UCPP_InventoryBar>(TEXT("TestInvBar"));	
	Interact->OnComponentBeginOverlap.AddDynamic(this, &ACPP_InteractBase::OverlapBeginInteractable);
	Interact->OnComponentEndOverlap.AddDynamic(this, &ACPP_InteractBase::OverlapEndInteractable);
}

// Called when the game starts or when spawned
void ACPP_InteractBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_InteractBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(LynchCharacter != nullptr){
		if(LynchCharacter->bPickUpInitiated && bItemInRange){
			Pickup();
		}
	}

}

void ACPP_InteractBase::OverlapBeginInteractable(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){

	bItemInRange = true;
	GetPlayer(OtherActor);
	TestInvBar = NewObject<UCPP_InventoryBar>(GetWorld(),InventoryBarClass);
}	

void ACPP_InteractBase::OverlapEndInteractable(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex){

	bItemInRange = false;
}

void ACPP_InteractBase::Pickup(){
    GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Orange,FString::Printf(TEXT("+ %s"),(*ItemInfo.Name.ToString())));
	if(TestInvBar != nullptr){
		TestInvBar->UpdateInventoryBarSlot(ItemInfo.Image);
    	GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Orange,FString::Printf(TEXT("TestInvBar is not nullptr")));
    	//GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Orange,FString::Printf(TEXT("testFloat, %f"), TestInvBar->test));
	}
	else{
    	GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Orange,FString::Printf(TEXT("TestInvBar is nullptr")));
	}
	Destroy();
}

void ACPP_InteractBase::GetPlayer(AActor* Player){
	LynchCharacter = Cast<ACH_LynchCharacter>(Player);
}


