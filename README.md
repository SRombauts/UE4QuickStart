Unreal Engine 4 C++ Programming Quick Start Tutorials
-----------------------------------------------------

This is intended as a lightweight (no heavy assets)
mix of all [C++ Tutorials](https://docs.unrealengine.com/latest/INT/Programming/Tutorials/index.html)
from the official [Programming Guide](https://docs.unrealengine.com/latest/INT/Programming/index.html)
and various other sources

### Progression

1. Let's start with the [Programming Quick Start](https://docs.unrealengine.com/latest/INT/Programming/QuickStart/index.html)
using a C++ BasicCode project in Scalable Quality, without Starter Content. 
    - Uses Tick with sine to move/float smoothly in loop [FloatingActor.h](Source/UE4QuickStart/FloatingActor.h), [FloatingActor.cpp](Source/UE4QuickStart/FloatingActor.cpp)

2. Add a Timer Event from [Variables, Timers, and Events Tutorial](https://docs.unrealengine.com/latest/INT/Programming/Tutorials/VariablesTimersEvents/index.html)
    - Uses a Timer instead of the Tick to trigger an event after a few seconds [Countdown.h](Source/UE4QuickStart/Countdown.h), [Countdown.cpp](Source/UE4QuickStart/Countdown.cpp)
    - [MovingPlatform.h](Source/UE4QuickStart/MovingPlatform.h), [MovingPlatform.cpp](Source/UE4QuickStart/MovingPlatform.cpp)
    - [FollowingActor.h](Source/UE4QuickStart/FollowingActor.h), [FollowingActor.cpp](Source/UE4QuickStart/FollowingActor.cpp)

3. Add a Pawn from [Player Input and Pawns](https://docs.unrealengine.com/latest/INT/Programming/Tutorials/PlayerInput/index.html)
    - [MyPawn.h](Source/UE4QuickStart/MyPawn.h), [MyPawn.cpp](Source/UE4QuickStart/MyPawn.cpp)

4. Add a CameraDirector from [Game-Controlled Cameras](https://docs.unrealengine.com/latest/INT/Programming/Tutorials/AutoCamera/index.html)
    - [CameraDirector.h](Source/UE4QuickStart/CameraDirector.h), [CameraDirector.cpp](Source/UE4QuickStart/CameraDirector.cpp)

5. Add a Ray Cast / Line Trace like described in the Wiki
    - [RayTracing.h](Source/UE4QuickStart/RayTracing.h), [RayTracing.cpp](Source/UE4QuickStart/RayTracing.cpp)

6. Add a Pickup base class from [3rd Person Power-Up Game with C++](https://wiki.unrealengine.com/Videos/Player?series=PLZlv_N0_O1gYup-gvJtMsgJqnEB_dGiM4)
    - [Pickup.h](Source/UE4QuickStart/Pickup.h), [Pickup.cpp](Source/UE4QuickStart/Pickup.cpp)
    - [BatteryPickup.h](Source/UE4QuickStart/BatteryPickup.h), [BatteryPickup.cpp](Source/UE4QuickStart/BatteryPickup.cpp)
    - [SpawnVolume.h](Source/UE4QuickStart/SpawnVolume.h), [SpawnVolume.cpp](Source/UE4QuickStart/SpawnVolume.cpp)

7. Add a LocationReporter and a Door from [Udemy UnrealCourse Section 3 Building Escape](https://github.com/UnrealCourse/03_BuildingEscape)
    - [LocationReporterComponent.h](Source/UE4QuickStart/LocationReporterComponent.h), [LocationReporterComponent.cpp](Source/UE4QuickStart/LocationReporterComponent.cpp)
    - [DoorComponent.h](Source/UE4QuickStart/DoorComponent.h), [DoorComponent.cpp](Source/UE4QuickStart/DoorComponent.cpp)

### License:

Copyright 2015-2018 Sebastien Rombauts (sebastien.rombauts@gmail.com)

Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
or copy at http://opensource.org/licenses/MIT)
