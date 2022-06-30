# MoJojo piano sustain pedal Keyboards

<img alt="Yamaha FC5 piano sustain pedal" src="https://bdbo2.thomann.de/thumb/bdb3000/pics/bdbo/12425092.jpg" width="300">

This project use an Yamaha FC5 piano sustain pedal as a qmk foot switch.

* Keyboard Maintainer: [MoJojo](https://github.com/Jorand)
* Hardware Supported: Pro Micro ATmega32U4 or Beetle USB ATmega32U4
* Hardware Availability: Just plug the pedal signal to pin 9 and GND of your Beetle USB. If the pedal is Normally Closed connect the shield to vcc and the signal to pin 9, put a 10k resitor between pin 9 and GND.

Make example for these keyboards (after setting up your build environment):

    make mojojo/pianoz:default
    or
    qmk compile -kb mojojo/pianoz -km vial

Flashing example for this keyboard:
    
    make mojojo/pianoz:default:flash

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (the top left key) and plug in the keyboard.
* **Physical reset button**: Briefly short pads RST and GND on the PCB.
* **Keycode in layout**: Press the key mapped to `RESET`.

See [build environment setup](https://docs.qmk.fm/install-build-tools) then the [make instructions](https://docs.qmk.fm/build-compile-instructions) for more information.