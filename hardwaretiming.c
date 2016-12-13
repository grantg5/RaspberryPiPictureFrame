#include <Python.h>
#include "system_timer.h"

/*
 * Handles the timing functionality. Given the delay as a parameter
 * uses the built-in timing functionality to delay.
 */ 
static PyObject *hardwaretiming(PyObject *self, PyObject *args) {
    uint32_t *delay;
    //Parses the Python arguments coming in.
    if (!PyArg_ParseTuple(args, "d", &delay))
        return NULL;
    uint32_t delayUs = 1000000 * (*delay);

    uint32_t current_time = sys_timer[SYS_TIMER_CLO];

    // Next, add the delay to the current count.
    // and, put that into the C0 timer register.
    uint32_t target_time = current_time + delayUs;
    sys_timer[SYS_TIMER_C0] = target_time;

    // Clear the M0 timer register.
    sys_timer[SYS_TIMER_CS] |= 1 << 1;

    // Now we spin until the CS register
    // has a 1 in the 0 position, then we know
    // our timer has expired.
    while ((sys_timer[SYS_TIMER_CS] & 1) != 1) {
        //NOOP
    } 

    //Python requires a return statement, so retuning the Python equivlent of none.
    Py_RETURN_NONE;
}
/*
 * Defines the functions in this file for Python.
 */
static PyMethodDef hardwaretiming_funcs[] = {
    {"hardwaretiming", (PyCFunction)hardwaretiming, METH_VARARGS, NULL},
    {NULL}
};

/*
 * Initializes a Python module in this C file.
 */
void inithardwaretiming(void) {
    Py_InitModule4("hardwaretiming", hardwaretiming_funcs, "timing");
}
