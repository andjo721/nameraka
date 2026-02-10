# https://github.com/andjo721/nameraka

MOUSEKEY_ENABLE = yes   # Mouse keys
EXTRAKEY_ENABLE = yes  # Audio control and System control

# OS Detection - automatically detect macOS vs Linux at runtime
OS_DETECTION_ENABLE = yes
AUTO_SHIFT_ENABLE = no # Auto Shift
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
KEY_OVERRIDE_ENABLE = no
COMBO_ENABLE = yes

DEBOUNCE_TYPE = sym_defer_pk

# DYNAMIC_TAPPING_TERM_ENABLE = yes

LTO_ENABLE = yes
NKRO_ENABLE = yes

EXTRAFLAGS += -flto -s -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables -mrelax -Os  -ffunction-sections -fdata-sections -Wl,--gc-sections

# Disable LED functionality (I don't use leds on my keyboards)
RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no

OLED_DRIVER_ENABLE = no
OLED_ENABLE = no
RGB_MATRIX_ENABLE = no
WS2812_ENABLE = no

BOOTMAGIC_ENABLE = no

AVR_USE_MINIMAL_PRINTF = yes
# INTROSPECTION_KEYMAP_C = andjo-nameraka.c # keymaps

include keyboards/crkbd/keymaps/nameraka/custom_rules.mk

include keyboards/crkbd/keymaps/nameraka/post_rules.mk

# SRC += features/layer_lock.c

COMMAND_ENABLE = no
