# AI with C++
> In this repository, you will be able to find my approach to exercises and improvements that "_Programming Game AI by Example_" suggested.


## Finite State Machine
During the second chapter, the book explains an FST with an example where two agents, Bob (who is a miner), and Elsa (who is the miner's wife) seem to be alive, furthermore, they can interact with each other.


### Modifying the FSM
A new character was introduced, a barfly. This person is going to insult miner Bob in the saloon and then, they get into a fight.
My approach is going to be explained in the next graphs.


#### Miner Bob
![minerbobstates](https://github.com/locus0002/c-plus-plus-ai/blob/master/images/miner.png?raw=true)
> As you can see, a new state was added to the states of Bob. The purpose is to handle the fight against the barfly. Plus, it was mandatory to add new transitions to change among states.


#### Barfly
![minerbobstates](https://github.com/locus0002/c-plus-plus-ai/blob/master/images/barfly.png?raw=true)
> The design of the barfly states and their transitions is shown in the last image. As you can notice, each transition is accompanied by a label that explains briefly how the barfly can change from a current state to another.


Finally, you can see my improvements in the next files.
- [BarFly.cpp](WestWorldWithMessaging/BarFly.cpp)
- [BarFly.h](WestWorldWithMessaging/BarFly.h)
- [BarflyOwnedStates.cpp](WestWorldWithMessaging/BarflyOwnedStates.cpp)
- [BarflyOwnedStates.h](WestWorldWithMessaging/BarflyOwnedStates.h)
- [EntityNames.h](WestWorldWithMessaging/EntityNames.h)
- [main.cpp](WestWorldWithMessaging/main.cpp)
- [MessagesTypes.h](WestWorldWithMessaging/MessagesTypes.h)
- [Miner.h](WestWorldWithMessaging/Miner.h)
- [MinerOwnedStates.cpp](WestWorldWithMessaging/MinerOwnedStates.cpp)
- [MinerOwnedStates.h](WestWorldWithMessaging/MinerOwnedStates.h)


## Steering Behavior - Hide

In the third chapter, the book suggests some improvements to the Hide Algorithm, and my approach implements the next considerations.

- The prey tries to hide when the hunter is in the prey's vision radius (gray circumference) and the prey is in the hunter's vision radius (blue circumference)
- Whether the hunter is not in the vision radius, the prey tries to hide if the last time when the hunter was seen within the elapsed N seconds (N is an initial parameter)
- The possible hiding spots (dark green dots) will be which are on the side or in the back of the hunter. The front area covers 30 degrees on the left side of the hunter's head and 30 degrees on the right side of the same. (60 degrees in total)

<p align="center" >
![hidingaids](https://github.com/locus0002/c-plus-plus-ai/blob/master/images/hide.png?raw=true)
</p>

If you are curious about the code that helped to implement the improvements, here is the list of the functions
- [IsHunterOnVisionRange](https://github.com/locus0002/c-plus-plus-ai/blob/197d36eba96f371791948daa56f225d7eed3e86a/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1476)
- [IsHunterClose](https://github.com/locus0002/c-plus-plus-ai/blob/197d36eba96f371791948daa56f225d7eed3e86a/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1489)
- [IsNotInFront](https://github.com/locus0002/c-plus-plus-ai/blob/197d36eba96f371791948daa56f225d7eed3e86a/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1504)
- [SetHidingDelimiters](https://github.com/locus0002/c-plus-plus-ai/blob/197d36eba96f371791948daa56f225d7eed3e86a/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1530)
- [Hide](https://github.com/locus0002/c-plus-plus-ai/blob/197d36eba96f371791948daa56f225d7eed3e86a/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1383)
- [aids](https://github.com/locus0002/c-plus-plus-ai/blob/197d36eba96f371791948daa56f225d7eed3e86a/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1973)

You can watch it in action, just hit the [here](https://www.linkedin.com/feed/update/urn%3Ali%3Aactivity%3A6749366532184293376/)