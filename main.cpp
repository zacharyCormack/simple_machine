#include "forces.hpp"
#include "components.hpp"
#include "shaders.hpp"
#include "Machine.hpp"

int main() {
    /* make objects */
    Machine machine();
    /* bind objects */
    bool window_should_close = false;
    while(!window_should_close) {
        machine.iterate();
        /* potentially, pan */
        machine.draw();
        /* check if window should close */
        window_should_close = true;//to stop an endless repeat
    }
}