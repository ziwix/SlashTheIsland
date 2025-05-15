#pragma once

#include "DrawDebugHelpers.h"

#define S_FRAME -1.f

#define DRAW_DEBUG_SPHERE(Location, Size) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, Size, 12, FColor::Red, true);
#define DRAW_DEBUG_VECTOR(StartLocation, EndLocation, Size) if (GetWorld()) DrawDebugDirectionalArrow(GetWorld(), StartLocation, EndLocation, Size, FColor::Red, true, -1.0f, 0, 1.f);
#define DRAW_DEBUG_LINE(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, StartLocation + EndLocation, FColor::Red, true, -1.0f, 0, 1.f);
#define DRAW_DEBUG_POINT(Location) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Red, true);

#define DRAW_DEBUG_SPHERE_SingleFrame(Location, Size) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, Size, 12, FColor::Red, false, S_FRAME);
#define DRAW_DEBUG_VECTOR_SingleFrame(StartLocation, EndLocation, Size) if (GetWorld()) DrawDebugDirectionalArrow(GetWorld(), StartLocation, EndLocation, Size, FColor::Red, false, S_FRAME, 0, 1.f);
#define DRAW_DEBUG_LINE_SingleFrame(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, StartLocation + EndLocation, FColor::Red, false, S_FRAME, 0, 1.f);
#define DRAW_DEBUG_POINT_SingleFrame(Location) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Red, false, S_FRAME);

#define DRAW_ACTOR_DEBUG(Location, EndLocation, Size) DRAW_DEBUG_SPHERE(Location, Size) DRAW_DEBUG_VECTOR(Location, EndLocation, Size)
#define DRAW_ACTOR_DEBUG_SingleFrame(Location, EndLocation, Size) DRAW_DEBUG_SPHERE_SingleFrame(Location, Size) DRAW_DEBUG_VECTOR_SingleFrame(Location, EndLocation, Size)
