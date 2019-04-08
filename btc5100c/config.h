#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEEB
#define PRODUCT_ID      0xB51C
#define DEVICE_VER      0x0001
#define MANUFACTURER    BTC
#define PRODUCT         5100C
#define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 15

/* key matrix pins */
#define MATRIX_ROW_PINS { E7, B0, B1, B2, B3, B4, B5, B6 }
#define MATRIX_COL_PINS { D0, D1, D2, D3, D4, D5, D6, D7, E0, E1, C0, C1, C2, F0, E6 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */
#define BACKLIGHT_PIN B5
#define BACKLIGHT_LEVELS 3


/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

//#define MATRIX_HAS_GHOST