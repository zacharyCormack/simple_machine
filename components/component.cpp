#include "component.hpp"
#include "prism.hpp"
#include "program.hpp"

component::component(program draw, force* forces_to_bind, int* coefficients_to_bind, void(*react)(int)) {
    forces = forces_to_bind;
    coefficients = coefficients_to_bind;
    drawer = draw;
    receive_force = react;
}

component::component_type component::make_instance(prism base, int variation) {
    component_type instance(base, variation, forces, this);
    return instance;
}

component::component_type::component_type(prism base, int variation, component component_type) {
	core = base;
	variation_val = variation;
    type = &component_type;
    acting_forces = type->forces;
    for(int i = 0; i < sizeof(type->forces)/sizeof(force); i++) {
        type->forces[i].bind_object(*this, *type, &ID, type->coefficients[i]);
    }
}

void component::component_type::act_on(ball target) {
    for(int i = 0; i < sizeof(acting_forces) / sizeof(force); i++) {
         (type->receive_force)(acting_forces[i].exert(target, ID));
    }
}