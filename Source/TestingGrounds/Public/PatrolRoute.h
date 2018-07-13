// No Rights Reserved 2018 Luke Stocking

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"

/**
* A "route card" to help AI choose their next waypoint
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPatrolRoute();

	 TArray<AActor*> GetWaypoints() const;

private:	
	UPROPERTY(EditInstanceOnly, Category = "PatrolRoute")
	TArray<AActor*> Waypoint;

		
	
};
