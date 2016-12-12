#include "Python.h"
#include "system_timer.h"

static PyObject * system_timer(PyObject *self, PyObject *args) {
    uint32_t *delay;
    if (!PyArg_ParseTuple(args, "d", &delay))
        return NULL;

    timer_delay_sec(delay);
}

void timer_delay_us(uint32_t delayUs)
{
    // First, get the current count of the timer.
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
}

void timer_delay_ms(uint32_t delayMs)
{
    // scale the microsecond delay appropriately
    timer_delay_us(1000 * delayMs);
}

void timer_delay_sec(uint32_t delaySec)
{
    // scale the microsecond delay appropriately
    timer_delay_us(1000000 * delaySec);
}