# simple_machine
A simple machine illustration framework built with OpenGL
This C++ project uses classes to represent forces and components in the simple machine.
Here are some explanations of the somewhat counterintuitive *but clever* ideas.
## Component
A `Component` is a type of simple machine.
The 3 main properties are `Program drawer`, for drawing, `void(*react)(double*)` and `double* coefficients` which that allows it to move.
`void(*react)(double*)` is a function pointer allowing different components to behave differently.
The `coefficients` is used to describe how the component reacts to different forces.
A "Gravity coefficient" is just mass. A "friction coefficient" is the coefficient of friction. All "Normal coefficients" are 1, because the normal force doesn't discriminate.
A `Component::Instance` represents an object, and has a `prism core`, and `line velocity`, representing it's motion.
It also has a `Component* type` property, a pointer to it's parent class. It moves based on it's type's `react` function.
## Force
The `Force` class has an interesting `double*(*equation)(angle, double)` property, but also a double* `exert(Component::Instance, Component::Instance)` method.
`equation` is just the equation for the force.
`exert` uses `equation` to calculate force, and then exerts the force on the objects.
## Use
If you just want to use this to animate a simple machine, only edit the `main.cpp` file. It's where all every `Component::Instance` is created.
Just by changing where the components are positioned, you can totally change the machine.
