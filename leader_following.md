# Leader Following

I implemented the "Leader Following Behavior" which is an exercise suggested by the "Programming Game AI by Example" book.

__Note__: I modified the "Offset Pursuit" algorithm to avoid a strange behavior when the leader changed his position suddenly because the game world behaves as a toroid.

<p align="center" >
    <img src="https://github.com/locus0002/c-plus-plus-ai/blob/master/images/leader_following.png?raw=true" />
</p>

If you are curious about the code, here is the list of the functions
- [ValidateOffsetPoint](https://github.com/locus0002/c-plus-plus-ai/blob/791f34870d1b75a3a0e7ab2af5a5d545f6d8e3ba/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1715)
- [OrderFollowers](https://github.com/locus0002/c-plus-plus-ai/blob/791f34870d1b75a3a0e7ab2af5a5d545f6d8e3ba/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1580)
- [AddSortedVehicle](https://github.com/locus0002/c-plus-plus-ai/blob/791f34870d1b75a3a0e7ab2af5a5d545f6d8e3ba/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1618)
- [Modification in OffsetPursuit](https://github.com/locus0002/c-plus-plus-ai/blob/791f34870d1b75a3a0e7ab2af5a5d545f6d8e3ba/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1663)

You can watch it in action, just hit the [link](https://www.linkedin.com/feed/update/urn:li:activity:6754449895190515712/)