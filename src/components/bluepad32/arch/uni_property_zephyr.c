// Bluepad32 property implementation for Zephyr
// Uses in-memory storage with defaults. Persistence via Zephyr NVS can be added later.

#include "uni_property.h"

#include <string.h>

#include "uni_log.h"

// In-memory property value cache (indexed by uni_property_idx_t)
static uni_property_value_t property_cache[UNI_PROPERTY_IDX_COUNT];
static bool property_cached[UNI_PROPERTY_IDX_COUNT];

void uni_property_set_with_property(const uni_property_t *p, uni_property_value_t value)
{
    if (!p) {
        loge("Cannot set invalid property\n");
        return;
    }

    if (p->flags & UNI_PROPERTY_FLAG_READ_ONLY) {
        loge("Cannot set READ_ONLY property: '%s'\n", p->name);
        return;
    }

    if (p->idx < UNI_PROPERTY_IDX_COUNT) {
        property_cache[p->idx] = value;
        property_cached[p->idx] = true;
    }
}

uni_property_value_t uni_property_get_with_property(const uni_property_t *p)
{
    if (!p) {
        loge("Cannot get invalid property\n");
        uni_property_value_t ret = { .u8 = 0 };
        return ret;
    }

    if (p->idx < UNI_PROPERTY_IDX_COUNT && property_cached[p->idx]) {
        return property_cache[p->idx];
    }

    return p->default_value;
}

void uni_property_init(void)
{
    memset(property_cache, 0, sizeof(property_cache));
    memset(property_cached, 0, sizeof(property_cached));
    logi("Bluepad32: property system initialized (in-memory)\n");
}
