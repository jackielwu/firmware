#include <bool.h>

typedef enum
{
  stable_h,
  to_l,
  stable_l,
  to_h
} debounce_state_t;

const size_t threshold = 10;
bool pin_state;
/*
 * @brief get stable state of given gpio pin
 *
 * @param: pin, the gpio pin to read
 *
 * @return: pin state after debounce
 */
bool getStablePinState(gpio_t pin);

/*
 * @brief: get instant state of given gpio pin
 *
 * @param: pin, the gpio pin to read
 *
 * @return: pin state
 */
bool readPin(gpio_t pin);
