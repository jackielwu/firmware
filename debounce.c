#include "debounce.h"
/*
 * @brief: get stable state of given gpio pin
 * 
 * @param: pin, the gpio pin to read
 * 
 * @return: pin state after debounce
 */

bool getStablePinState(gpio_t pin) {
	size_t counter = 0;
	bool pinstate = readPin(pin);
	enum debounce_state state = pinstate? stable_h: stable_l; 
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
						counter = 0;
					}
				break;	
		}
	}

}


