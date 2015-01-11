#ifndef _PUSH_BUTTON_H_
#define _PUSH_BUTTON_H_

#include "hw/Button.h"

/** a push button
It can be pressed for a time t to trigger an LONG_PRESS event
It also have a default value when not pressed */
class PushButton : public Button{
public:
    /** Create a Push Button
    @param gpio_pin read from this pin
    @param pull_resistor <0 is pull down, >0 is pull up, 0 is no pull 
    @param value when button is not pressed */
    PushButton(int gpio_n, std::shared_ptr<module> c, int no_press_value, int pull_resistor=0)
        : Button(gpio_n, c, pull_resistor), no_press_value(no_press_value)
    {
        m_last_read = no_press_value;
    }
    ~PushButton();
    virtual int process_read(int v);
    
protected:
    const int no_press_value;
};

#endif
