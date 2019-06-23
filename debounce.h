#include <bool.h>

enum debounce_state {stable_h, to_l, stable_l, to_h};
const size_t threshold = 10;

/*
 * @brief: get instant state of given gpio pin
 *
 * @param: pin, the gpio pin to read
 *
 * @return: pin state
 */
bool readPin(gpio_t pin);
