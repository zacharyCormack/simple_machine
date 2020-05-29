#include "component.hpp"
#include "forces.hpp"
#include "shaders.hpp"

force forces[2] = {normal, gravity};
component lift(draw_prism, forces);