// Bluepad32 logging implementation for Zephyr

#include "uni_log.h"

#include <stdarg.h>
#include <stdio.h>
#include <zephyr/kernel.h>

void uni_logv(const char *format, va_list args)
{
    vprintf(format, args);
}
