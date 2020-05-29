#include "component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

force forces[3] = {normal, friction, gravity};
component lift(draw_prism, forces);