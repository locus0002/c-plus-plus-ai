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