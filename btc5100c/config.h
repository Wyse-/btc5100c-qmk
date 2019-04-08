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

/* led pins */
#define NUM_LOCK_LED_PIN F1
#define CAPS_LOCK_LED_PIN F2
#define SCROLL_LOCK_LED_PIN F3

/* fn key pin */
#define FN_KEY_PIN B7

/* pin wired to reset pin */
#define RESET_PIN F7

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

//#define MATRIX_HAS_GHOST