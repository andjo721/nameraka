# https://github.com/andjo721/nameraka

MOUSEKEY_ENABLE = no   # Mouse keys
EXTRAKEY_ENABLE = yes  # Audio control and System control
AUTO_SHIFT_ENABLE = no # Auto Shift
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
COMBO_ENABLE = yes

DYNAMIC_TAPPING_TERM_ENABLE = yes

LTO_ENABLE = yes
NKRO_ENABLE = yes

# Disable LED functionality (I don't use leds on my keyboards)
RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no

# INTROSPECTION_KEYMAP_C = andjo-nameraka.c # keymaps

include keyboards/crkbd/keymaps/nameraka/custom_rules.mk

include keyboards/crkbd/keymaps/nameraka/post_rules.mk

# SRC += features/layer_lock.c

COMMAND_ENABLE = no
