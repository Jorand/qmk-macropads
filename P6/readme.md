# MoJojo P6 macropad

A hand wired 1x2 macropad with 3 layers toggle by a 3 way switch.

* Keyboard Maintainer: [Jorand](https://github.com/Jorand)
* Hardware Supported: Pro Micro ATmega32U4 
* Hardware Availability: Custom wierd Arduino Pro Micro

## Pinout

|           | DIP 0 | DIP1 | BTN 0 | LED 0 | BTN 1 | LED 1 |
| --------- | ----- | ---- | ----- | ----- | ----- | ----- |
| Pro Micro | 10    | 16   | 14    | 15    | A0    | A1    |
| QMK pin   | B6    | B2   | B3    | B1    | F7    | F6    |

### Compiling the Firmware

Make example for these keyboards (after setting up your build environment):

    make mojojo/p6:vial
    or
    qmk compile -kb mojojo/p6 -km vial

Flashing example for this keyboard:
    
    make mojojo/p6:vial:flash

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (the top left key) and plug in the keyboard.
* **Physical reset button**: Briefly short pads RST and GND on the PCB.
* **Keycode in layout**: Press the key mapped to `RESET`.

See [build environment setup](https://docs.qmk.fm/install-build-tools) then the [make instructions](https://docs.qmk.fm/build-compile-instructions) for more information.