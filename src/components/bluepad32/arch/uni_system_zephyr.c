// Bluepad32 system implementation for Zephyr

#include "uni_system.h"

#include <zephyr/sys/reboot.h>

void uni_system_reboot(void)
{
    sys_reboot(SYS_REBOOT_COLD);
}
