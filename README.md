# AI with C++
> In this repository, you will be able to find my approach to exercises and improvements that "_Programming Game AI by Example_" suggested.

## How to run the projects

If you desire to run the __FSM project__, which is inside of the _WestWorldWithMessagin_ folder, follow the next steps.

- Clone the repository
- Open [Visual Studio Code](https://code.visualstudio.com/) (that was my code editor for this exercise)
- Modify the task.json file and the c_cpp_properties.json file ([Here](https://code.visualstudio.com/docs/cpp/config-mingw) you can find a tutorial on how to configure your tasks in VSC)
- Finally, run the project

For the exercises of chapter 3 (__Steering Behaviors__), you have to follow the next steps
- Clone the repository
- Deciding which exercise you want to run
- Switching to the desired commit
    - __Steering behavior hide__ (_3a2abf8fa24762864e4c205b383c9a312714a2c6_)
    - __Leader following__ (_9638631f73991abe2c1c3da05de8d5f9ee6757e0_)
    - __Flock of Sheep__ (_698e41afe0a31f817f3d1f9a03c8f276d8b4db7b_)
- Open the project file (_Steering.sln_) inside of the _Buckland_Chapter3_ folder with Visual Studio 2019 (the reason because I used this IDE, was the simplicity to run the whole project)
- Right-click on the _Steering_ project
- Choose _Properties_
- In the pop-up window select _Configuration Properties_ > _C/C++_ > _General_
- Verifies _Additional Include Directories_ is pointing to the correct path
- Finally, run the project

## Want to know more about my approaches

Here you can find the __explanations__ of the exercises that I implemented

- [FSM](fsm.md)
- [Steering behavior hide](steering_behavior_hide.md)
- [Leader following](leader_following.md)
- [Flock of Sheep](flock_sheep.md)