# MoJojo UT300 Keyboard

<img alt="UT300 MoJojo Keyboard" src="https://bdbo2.thomann.de/thumb/bdb3000/pics/bdbo/11341367.jpg" width="300">

A 1-key foot switch made with a guitar effect pedal.

* Keyboard Maintainer: [Jorand](https://github.com/Jorand)
* Hardware Supported: Beetle USB ATmega32U4
* Hardware Availability: Just plug the pedal switch to pin 9 and GND of your Beetle USB

Make example for these keyboards (after setting up your build environment):

    make mojojo/ut300:default
    or
    qmk compile -kb mojojo/ut300 -km vial

Flashing example for this keyboard:
    
    make mojojo/ut300:default:flash

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (the top left key) and plug in the keyboard.
* **Physical reset button**: Briefly short pads RST and GND on the PCB.
* **Keycode in layout**: Press the key mapped to `RESET`.

See [build environment setup](https://docs.qmk.fm/install-build-tools) then the [make instructions](https://docs.qmk.fm/build-compile-instructions) for more information.