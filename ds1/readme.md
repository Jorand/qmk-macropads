# MoJojo DS1 Keyboards

![MoJojo Keyboards](https://static.roland.com/assets/images/products/gallery/ds1_D_gal.jpg)

A 1-key foot switch made with a guitar distortion pedal.

Keyboard Maintainer: [Jorand](https://github.com/Jorand)
Hardware Supported: Pro Micro ATmega32U4
Hardware Availability: Just plug the pedal switch to pin 2 and GND of your Pro Micro

Make example for these keyboards (after setting up your build environment):

    make mojojo/ds1:default

Flashing example for this keyboard:
    
    make mojojo/ds1:default:flash

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (the top left key) and plug in the keyboard.
* **Physical reset button**: Briefly short pads RST and GND on the PCB.
* **Keycode in layout**: Press the key mapped to `RESET`.

See [build environment setup](https://docs.qmk.fm/install-build-tools) then the [make instructions](https://docs.qmk.fm/build-compile-instructions) for more information.