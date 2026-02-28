// Stub for Steam controller parser (requires BLE which we don't use)

#include <stdint.h>
#include <stdbool.h>

struct uni_hid_device_s;

void uni_hid_parser_steam_setup(struct uni_hid_device_s *d) { (void)d; }
void uni_hid_parser_steam_init_report(struct uni_hid_device_s *d) { (void)d; }
void uni_hid_parser_steam_parse_input_report(struct uni_hid_device_s *d, const uint8_t *report, uint16_t len) {
    (void)d; (void)report; (void)len;
}
