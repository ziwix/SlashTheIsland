#pragma once

#include "DrawDebugHelpers.h"

#define DRAW_DEBUG_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, true);
#define DRAW_DEBUG_LINE(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, StartLocation + EndLocation, FColor::Red, true, -1.0f, 0, 1.f);
#define DRAW_DEBUG_POINT(Location) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Red, true);
#define DRAW_DEBUG_VECTOR(StartLocation, EndLocation) if (GetWorld()) DrawDebugDirectionalArrow(GetWorld(), StartLocation, EndLocation, 25.f, FColor::Red, true, -1.0f, 0, 1.f);

#define DRAW_ACTOR_DEBUG(Location, EndLocation) DRAW_DEBUG_SPHERE(Location) DRAW_DEBUG_VECTOR(Location, EndLocation)
