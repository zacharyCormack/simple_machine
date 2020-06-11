# simple_machine
![LOGO](http://www.zacharycormack.net/wp-content/uploads/2019/01/Logo2-1-300x179.png "zacharycormack.net")

> The use of this software is dictated by the __LICENSE__ file.

A simple machine illustration framework built with _OpenGL_
This C++ project uses classes to represent forces and components in the simple machine.
Here are some explanations of the somewhat counterintuitive *but clever* ideas.

## Component
A `Component` represents a type of ***simple machine***.
The 3 main properties are `Program drawer`, for drawing, and `void(*move)(double*)` and `double* coefficients`, which allow it to move.
`void(*move)(double*)` is a *function pointer* allowing different components to behave differently.
The `coefficients` is used to describe how the component reacts to different forces.
A *"Gravity coefficient"* is just **mass**. A *"friction coefficient"* is the coefficient of friction. All *"Normal coefficients"* are 1, because the normal force doesn't discriminate.
A `Component::Instance` represents an object, and has a `prism core`, and `line velocity`, representing it's motion.
It also has a `Component* type` property, a pointer to it's parent class. It moves based on it's type's `move` function pointer.

## Advanced Motion
In some components, the `move` function is **quite** complex.
For instance, a `rope`. A rope's core contains it's length, but also can account for if either end is tilted.
This is so that objects can sway, and be pulled back, important for being realistic and **cruical** for a pendulum.

## Machine
The `Machine` class controls all the components and binds them together.
In it's `iterate` method, it checks collisions, moves objects, and triggers force calculations.
The way forces are applied is complex. The most powerful force is the normal force. All forces will exert *up to* their maximum power, *but can stop before it.*
This means each force must be checked to see if it should stop each little bit they apply.
Of course, `gravity` doesn't stop until it must, but `friction`, `tension`, and `normal` forces all stop if they pull, push, or grind the object to a relative halt.
The `normal` force doesn't really have a maximum, though it's technical value is just the maximum value for a `double`.

## Force
The `Force` class has an interesting `double*(*equation)(angle, double)` property, but also a `double* exert(Component::Instance, Component::Instance)` method.
The `equation` is just the equation for the force.
The `exert` method uses the `equation` to calculate force, and then exerts the force on the objects.

## Colours
In the `Machine` class, there is a colour scheme property.
All `void(*bind_vertices)(prism)` functions have their first input as an integer representing which colour in the palette is used.
This way, changing the colour palette of a machine is *very easy*, and the same component types can be used in different machines with different palettes.

## Use
If you just want to use this to animate a simple machine, only edit the `main.cpp` file. It's where all every `Component::Instance` is created.
Just by changing the components, you can change the shape of the machine. You can also change the colour palette set in the main file.

## Notice
This project is currently incomplete. That means that it is currently not usable, but can still be contributed to. It can still be worked on after completion.
