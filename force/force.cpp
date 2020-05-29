#include "force.hpp"
#include <cmath>

force::force(double*(*equation)(angle, int), double str) {
    calc_force = equation;
    strength = str;
}

int force::exert(ball target, int actor_ID) {
    int f_num;
    for(int i = 0; i < sizeof(acts_on[actor_ID].type->coefficients)/sizeof(int); i++) {
        if(acts_on[actor_ID].type->forces == this) {
            f_num = i;
            break;
        }
    }
    double* force_exerted = (*calc_force)(acts_on[actor_ID].core.rotation, acts_on[actor_ID].type->coefficients[f_num]));
    target.accelerate(force_exerted);
    return cbrt(force_exerted[0]*force_exerted[0] + force_exerted[1]*force_exerted[1] + force_exerted[2]*force_exerted[2]);
}

void force::bind_object(component::component_type actor, component actor_type, int* actor_ID, int coefficient) {

}