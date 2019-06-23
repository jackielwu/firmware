#include <bool.h>


/*
 * @brief: initialize polling debounce
 *
 * @param: gpio pin
 *
 * @return: void
 */
 void init_polling(gpio_t pin);

/*
 * @brief: get stable state of given gpio pin
 *
 * @param: pin, the gpio pin to read
 *
 * @return: pin state after debounce
 */
bool get_stable_pin_state(gpio_t pin);
