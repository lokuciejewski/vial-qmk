# Keyboard converter for IBM model M terminal keyboard

This is a repurpose of the [`ibm_terminal`](../ibm_terminal/) converter port that uses STM32F401 Blackpill instead of the ATMega32u4.

Tested with an IBM model M 122 1394104 terminal keyboard that was used in an IBM InfoView II 3482 terminal.
This conversion is 100% reversible and does not require modifying the keyboard in any way except for removing the old RJ45 cable.

## Features

- Proper `vial` support
- 3 layers for remapping keys
- Optional buzzer
- [3D printed mount](https://github.com/lokuciejewski/m122_blackpill_converter) for the Blackpill (no glue required)  

## Connection

Keyboard | STM32F401 Blackpill
:------- | :---------
Data     |  B8
Clock    |  B9
VCC      |  5V
GND      |  G

A piezo buzzer is recommended to enable audio features if your keyboard does not have lock LEDs. Example connection:

Buzzer   | STM32F401 Blackpill
:------- | :---------
   \+    | A8
   \-    | G

The piezo buzzer runs on `pwm_software` since I could not manage to make it run on `pwm_hardware` driver and STM32F401 Blackpill does not have the DAC.

## Default key map

By default, there are some changes made to make using this board more user-friendly for modern systems:

- `Esc` is bound to the key left of the tilde(`~`) key and also to the `Caps Lock` key
- `Ctrl` keys are bound to `Reset/Quit` (left of the left `Alt`) and `Enter` key (right of the right `Alt`) as where they would be on a modern layout
- `Win/Super` key is bound to the key left of the left `Ctrl`
- `Caps Lock` is bound to the key left of the `Win/Super` key
- Nav cluster above the arrow keys is remapped to match the labels on my board

See [`keymap.c`](./keymaps/vial/keymap.c) for the complete map or just open `vial` to see it

## Build and flash

```sh
git clone git@github.com:lokuciejewski/vial-qmk.git
cd vial-qmk
git submodule update --init --recursive
qmk flash -kb converter/ibm_m122 -km vial
# First time you need to put your Blackpill into the bootloader mode, after that just press
# `Attn` + `ExSel` (your keys may be labeled different, see the explanation below) to enter bootloader mode 
```

On my M122 the keys used to enter the bootloader are labeled `Attn` and `ExSel` but since the IBM changed the labels for almost each terminal, those may be labeled different on your keyboard.

Those are first and third key from the first/leftmost row of the function cluster to the left of the main keyboard area.

See [`keymap.c`](./keymaps/vial/keymap.c) for a more graphical explanation.
