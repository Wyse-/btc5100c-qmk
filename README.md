# btc5100c-qmk

## Build Log
[Link to wiki](https://github.com/Wyse-/btc5100c-qmk/wiki/Build-Log).

## Description
This is a [QMK firmware](https://github.com/qmk/qmk_firmware) keyboard/keymap for the [BTC 5100C keyboard](https://geekhack.org/index.php?topic=84303.0).

By default it will to compile to a .hex file meant to be flashed to a [Teensy++ 2.0](https://www.pjrc.com/store/teensypp.html). Although untested it will probably work on any QMK compatible MCU provided you edit the `MCU = at90usb1286` line in the [rules.mk file](https://github.com/Wyse-/btc5100c-qmk/blob/master/btc5100c/rules.mk#L2) with your target MCU before compiling.

## Compiling
Refer to the [How to Compile section in the QMK wiki](https://docs.qmk.fm/#/README?id=how-to-compile).

Clone or download this repository and copy/move the btc5100c folder to `qmk_firmware/keyboards/`, then run `make btc5100c:default`: this will produce a `btc5100c_default.hex` file in `qmk_firmware/.build`, which is what you will flash on your MCU.

## Flashing
If you are flashing on a Teensy you can use [Teensy Loader](https://www.pjrc.com/teensy/loader.html): you will need to put the Teensy in bootloader mode either by pressing the reset button or connecting the RST pin to ground, then flash the compiled `btc5100c_default.hex` file via the GUI/CLI.

## Wiring
Obviously you everything can be wired however you want on the Teensy++ 2.0 (or your own MCU of choice) if you edit the [config.h](https://github.com/Wyse-/btc5100c-qmk/blob/master/btc5100c/config.h) file with your own pins.

By default the wiring is as follows:

**\* Don't forget to wire these with a resistor unless you want to risk burning the LEDs**

| Teensy++ 2.0  | BTC 5100C | Usage            |
| ------------- | --------- | ---------------- |
| F7 - RST      |           | Bootloader mode toggle        |
| F3            | SL        | **Scroll Lock LED toggle \*** |
| F2            | CL        | **Caps Lock LED toggle \***   |
| F1            | NL        | **Num Lock LED toggle \***    |
| 5V            | VCC       | Common 5V to all LEDs         |
| F0            | S14       | Matrix column 14 |
| E6            | S15       | Matrix column 15 |
| E7            | R0        | Matrix row 1     |
| B0            | R1        | Matrix row 2     |
| B1            | R2        | Matrix row 3     |
| B2            | R3        | Matrix row 4     |
| B3            | R4        | Matrix row 5     |
| B4            | R5        | Matrix row 6     |
| B5            | R6        | Matrix row 7     |
| B6            | R7        | Matrix row 8     |
| C2            | S13       | Matrix column 13 |
| C1            | S12       | Matrix column 12 |
| C0            | S11       | Matrix column 11 |
| E1            | S10       | Matrix column 10 |
| E0            | S9        | Matrix column 9  |
| D7            | S8        | Matrix column 8  |
| D6            | S7        | Matrix column 7  |
| D5            | S6        | Matrix column 6  |
| D4            | S5        | Matrix column 5  |
| D3            | S4        | Matrix column 4  |
| D2            | S3        | Matrix column 3  |
| D1            | S2        | Matrix column 2  |
| D0            | S1        | Matrix column 1  |
| B7            | P32       | Fn button        |
| GND           | GND       | Ground           |

## Layout(s)
The default layout (the only one available at the moment) is identical to the one native to the keyboard, meaning you will get all the Fn key extra keybinds (except SysRq, at the moment).

The only addition is that by pressing Fn+Delete you will (provided you wired the F7 pin, or your own, to the RST one) put the Teensy++ 2.0 in bootloader mode: this is needed to re-flash the Teensy without needing to open the keyboard case. This has been implemented as an sure-fire alternative to the [RESET Quantum Keycode](https://github.com/qmk/qmk_firmware/blob/master/docs/quantum_keycodes.md#qmk-keycodes) which was not working for me (probably because of my Teensy++ 2.0 [being a clone](https://github.com/qmk/qmk_firmware/issues/532#issuecomment-239353210)).

Represented visually it looks like this:
![layout visual representation](https://user-images.githubusercontent.com/5454041/56539531-84c3ba00-6566-11e9-92ba-0862f1f4e1c9.png)

## Credits
Thanks to mind_funeral@Geekhack for the BTC 5100C [informative thread](https://geekhack.org/index.php?topic=84303.0) & original layout representation!

The [Orange75 QMK keyboard/keymap](https://github.com/qmk/qmk_firmware/tree/master/keyboards/orange75) was used as a starting point for this one.
