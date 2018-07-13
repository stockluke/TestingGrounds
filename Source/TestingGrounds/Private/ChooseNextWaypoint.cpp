// No Rights Reserved 2018 Luke Stocking

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8* NodeMemory)
{
	// Get the patrol route
	UPatrolRoute* PatrolRoute = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UPatrolRoute>();
	if(!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }

	// Warn about empty patrol routes
	TArray<AActor*> Waypoints = PatrolRoute->GetWaypoints();
	if (Waypoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("A guard is missing patrol points"))
			return EBTNodeResult::Failed;
	}

	// Set next waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, Waypoints[Index]);
	
	// Cycle next index
	auto NextIndex = (Index + 1) % Waypoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;
}

