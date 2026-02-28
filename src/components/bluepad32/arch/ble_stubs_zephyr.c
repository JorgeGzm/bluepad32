// Stubs for BLE functions and libc assert referenced by Bluepad32 parsers
// BLE stubs are never called at runtime (DS4 uses BR/EDR only)

#include <stdint.h>
#include <zephyr/kernel.h>

// Bluepad32 parsers call assert() without including <assert.h>,
// so the compiler generates a call to the 'assert' symbol directly
void assert(int expression)
{
    if (!expression) {
        printk("ASSERT FAILED\n");
        k_panic();
    }
}

void att_server_request_can_send_now_event(uint16_t con_handle)
{
    (void)con_handle;
}

uint8_t hids_client_send_write_report(uint16_t hids_cid, uint8_t report_id,
                                       uint8_t report_type,
                                       const uint8_t *report, uint8_t report_len)
{
    (void)hids_cid;
    (void)report_id;
    (void)report_type;
    (void)report;
    (void)report_len;
    return 0;
}
