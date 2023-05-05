# Copyright 2019 Manna Harbour
# https://github.com/manna-harbour/miryoku
# generated -*- buffer-read-only: t -*-

MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
AUTO_SHIFT_ENABLE = yes # Auto Shift
BOOTMAGIC_ENABLE = yes
CASEMODES_ENABLE = yes
TAP_DANCE_ENABLE = yes
# CAPS_WORD_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
# OLED_ENABLE = yes
# OLED_DRIVER = SSD1306
# POINTING_DEVICE_ENABLE = yes
# POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
# RGBLIGHT_ENABLE = yes
ENCODER_ENABLE = yes
CONVERT_TO = stemcell
STMC_US = yes

SRC += users/sadekbaroudi/casemodes.c # keymap

include users/manna-harbour_miryoku/post_rules.mk
