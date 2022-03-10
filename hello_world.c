#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/stdio_usb.h"

#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#endif

int main()
{
    stdio_init_all();

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true)
    {
        printf("Hello, world!\n");
        sleep_ms(500);

        gpio_put(LED_PIN, 1);
        sleep_ms(250);

        if (stdio_usb_connected())
        {
            gpio_put(LED_PIN, 0);
            sleep_ms(250);
        }
    }
    return 0;
}
