#include "component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

force forces[3] = {tension, normal, gravity};
component lift(draw_rope, forces);