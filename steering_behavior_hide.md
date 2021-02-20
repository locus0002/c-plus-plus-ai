# Steering Behavior - Hide

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