// copyright: none

#pragma once

#include "CoreMinimal.h"

#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld(),Location,25.f,12,FColor::Red,true)  