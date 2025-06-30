#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/auxdisplay.h>
#include <string.h>

int main(void)
{
    const struct device *lcd = DEVICE_DT_GET(DT_NODELABEL(hd44780));

    if (!device_is_ready(lcd)) {
        printk("LCD device not ready!\n");
        return;
    }

    display_blanking_off(lcd);

    struct display_buffer_descriptor desc = {
        .buf_size = 20,
        .width = 20,
        .height = 1,
        .pitch = 20,
    };

    char *msg = "Hello Zephyr LCD";

    display_write(lcd, 0, &desc, msg);

    while (1) {
        k_sleep(K_SECONDS(1));
    }

    return 0;
}
