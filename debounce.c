#include "debounce.h"

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
 * @brief: get instant state of given gpio pin
 *
 * @param: pin, the gpio pin to read
 *
 * @return: pin state
 */
bool read_pin(gpio_t pin);


void debounce(gpio_t pin)
{
	size_t counter = 0;
	pin_state = readPin(pin);
	debounce_state_t state = pinstate? stable_h: stable_l;
	while (1) {
		switch (state) {
			counter++;
			case stable_h:
				if (readPin(pin) == true) {
					state = to_l;
					counter = 0;
				}
				break;
			case to_l:
				if (readPin(pin) == false) {
					state = stable_h;
					counter = 0;
				}
				else
					if (counter >= threshold) {
						state = stable_l;
						pin_state = true;
						counter = 0;
					}
				break;
			case stable_l:
				if (readPin(pin) == false) {
					state = to_h;
					counter = 0;
				}
				break;
			case to_h:
				if (readPin(pin) == true) {
					state = stable_l;
					counter = 0;
				}
				else
					if (counter >= threshold) {
						state = stable_h;
						pin_state = false;
						counter = 0;
					}
				break;
		}
	}
}

bool get_stable_pin_state(gpio_t pin)
{
		return pin_state;
}

void init(gpio_t pin)
{
	debounce(pin);
}
