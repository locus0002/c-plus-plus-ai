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
    <img src="https://github.com/locus0002/c-plus-plus-ai/blob/master/images/hide.png?raw=true" />
</p>

If you are curious about the code that helped to implement the improvements, here is the list of the functions
- [IsHunterOnVisionRange](https://github.com/locus0002/c-plus-plus-ai/blob/197d36eba96f371791948daa56f225d7eed3e86a/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1476)
- [IsHunterClose](https://github.com/locus0002/c-plus-plus-ai/blob/197d36eba96f371791948daa56f225d7eed3e86a/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1489)
- [IsNotInFront](https://github.com/locus0002/c-plus-plus-ai/blob/197d36eba96f371791948daa56f225d7eed3e86a/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1504)
- [SetHidingDelimiters](https://github.com/locus0002/c-plus-plus-ai/blob/197d36eba96f371791948daa56f225d7eed3e86a/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1530)
- [Hide](https://github.com/locus0002/c-plus-plus-ai/blob/197d36eba96f371791948daa56f225d7eed3e86a/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1383)
- [aids](https://github.com/locus0002/c-plus-plus-ai/blob/197d36eba96f371791948daa56f225d7eed3e86a/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1973)

You can watch it in action, just hit the [link](https://www.linkedin.com/feed/update/urn%3Ali%3Aactivity%3A6749366532184293376/)

## Leader Following

I implemented the "Leader Following Behavior" which is an exercise suggested by the "Programming Game AI by Example" book.
Note: I modified the "Offset Pursuit" algorithm to avoid a strange behavior when the leader changed his position suddenly because the game world behaves as a toroid.

<p align="center" >
    <img src="https://github.com/locus0002/c-plus-plus-ai/blob/master/images/leader_following.png?raw=true" />
</p>

If you are curious about the code, here is the list of the functions
- [ValidateOffsetPoint]()
- [OrderFollowers]()
- [AddSortedVehicle]()
- [Modification in OffsetPursuit]()

You can watch it in action, just hit the [link](https://www.linkedin.com/feed/update/urn:li:activity:6754449895190515712/)

## Steering Behavior - Flock Of Sheep
> I implemented a simulation of the behavior of a herding dog and a flock of sheeps

### Herding Dog (Triangle)

- The moves of this agent are controlled by a user (keyboard inputs)

### The flock of Sheep (Black Dots)

- These agents have a combination of behaviors
- The agents can form groups if these are enough close to each of them
- If some agent of a group identifies the herding dog because this one is in the range of the vision of the agent (sheep), the agent will try to stay away from the herding dog
- If some agent of a group identifies that some of their neighbors (sheep) are running away, the agent will start to follow them
- The agents (sheep) that already saw the herding dog, will try to stay in the last position where the herding dog guided them, otherwise, the agents (sheep) can walk around

### Before
<p align="center" >
    <img src="https://github.com/locus0002/c-plus-plus-ai/blob/master/images/flock_sheep1.png?raw=true" />
</p>

### After
<p align="center" >
    <img src="https://github.com/locus0002/c-plus-plus-ai/blob/master/images/flock_sheep2.png?raw=true" />
</p>

If you are curious about the code, here is the list of the modifications and new implementations
- [MoveStraight]()
- [Modification in Flee Behavior]()
- The class [Vehicle.cpp]() and [Vehicle.h]() was modified to add new features that help to implement the "flock of sheep behavior"
- Control by the keyboard Steering
- [TurnDirection]()

You can watch it in action, just hit the [link](https://www.linkedin.com/feed/update/urn:li:activity:6759507835865878529/)