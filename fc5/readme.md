# MoJojo FC5 Keyboards

<img alt="fc5 MoJojo Keyboard" src="https://fr.yamaha.com/fr/files/FC5_540x540_735x735_e57feecd8ec4f010c15e563740a6e7f9.jpg" width="300">

A 1-key foot switch made with a piano sustain pedal.

* Keyboard Maintainer: [Jorand](https://github.com/Jorand)
* Hardware Supported: Pro Micro ATmega32U4
* Hardware Availability: Just plug the pedal switch to pin 2 and GND of your Pro Micro

Make example for these keyboards (after setting up your build environment):

    make mojojo/fc5:default
    or
    qmk compile -kb mojojo/fc5 -km vial

Flashing example for this keyboard:
    
    make mojojo/fc5:default:flash

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (the top left key) and plug in the keyboard.
* **Physical reset button**: Briefly short pads RST and GND on the PCB.
* **Keycode in layout**: Press the key mapped to `RESET`.

See [build environment setup](https://docs.qmk.fm/install-build-tools) then the [make instructions](https://docs.qmk.fm/build-compile-instructions) for more information.