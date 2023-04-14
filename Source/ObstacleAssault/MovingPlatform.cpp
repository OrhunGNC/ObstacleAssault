// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
   
    //MyVector.X = MyX;
	
	//MyVector.Y = MyY;
	
	//MyVector.Z = MyZ;

    StartLocation = GetActorLocation();

	UE_LOG(LogTemp, Warning, TEXT("Configured Moved Distance : %f") ,MovedDistance );
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FVector LocalVector = MyVector;

	//LocalVector.Z= LocalVector.Z + 100;
	
    //MyVector.X= MyVector.X + 5;

	//SetActorLocation(LocalVector);

	MovePlatform(DeltaTime);
	
	RotatePlatform(DeltaTime);

}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if(ShouldPlatformReturn())
	{
	FVector MoveDirection=PlatformVelocity.GetSafeNormal();
	StartLocation= StartLocation + MoveDirection*MovedDistance;
	SetActorLocation(StartLocation);
	PlatformVelocity= -PlatformVelocity;
		//float OverShoot= DistanceFloat - MovedDistance;
		//FString MyString = GetName();
		//UE_LOG(LogTemp, Display, TEXT("%s  Over Shoot: %f"),*MyString, OverShoot);
	}
	else
	{
    FVector CurrentLocation = GetActorLocation();

	CurrentLocation = CurrentLocation + (PlatformVelocity*DeltaTime) ;

	SetActorLocation(CurrentLocation);
	}
	
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
 AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MovedDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
   return FVector ::Dist(StartLocation,GetActorLocation());
}

