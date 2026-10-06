# Keyball61 "german" keymap — setup, build, flash

This fork tracks a custom keymap for a **Keyball61** (split keyboard, RP2040/"sea picro"
controller, PMW3360 trackball on one half, OLED on both halves). The keymap lives at
`keyboards/keyball/keyball61/keymaps/german/` and is a real, committed file — not a symlink
into a synced folder — so cloning this fork is enough to reproduce the build on any machine.

## 1. Clone the fork

```sh
git clone https://github.com/duuwhang/qmk_firmware.git
cd qmk_firmware
git checkout whangboard2
```

## 2. Install the QMK build toolchain (one-time, per machine)

On Debian/Ubuntu:

```sh
./util/qmk_install.sh
```

This installs `gcc-avr`, `gcc-arm-none-eabi`, `avrdude`, `dfu-util`, and related build tools
via `apt`, and sets up a udev rule so flashing doesn't require `sudo`. You'll need
`python3-venv` available too (`sudo apt install python3-venv` if `python3 -m venv` fails with
an `ensurepip` error).

## 3. Create the Python environment (one-time, per machine)

The QMK CLI (`qmk`) runs in its own virtualenv, kept out of git:

```sh
python3 -m venv keyball61_german_env
source keyball61_german_env/bin/activate
pip install -r keyball61_german_env-requirements.txt
```

Activate this env (`source keyball61_german_env/bin/activate`) any time you want to run `qmk`
or `make ... :flash` in a new shell.

## 4. One-time QMK CLI configuration

```sh
qmk config user.keyboard=keyball/keyball61
qmk config user.keymap=german
```

## 5. Build and flash

With the Keyball61 plugged in and in bootloader mode (double-tap reset, or hold the boot
button while plugging in):

```sh
make keyball/keyball61:german:flash -j8
```

This compiles the `german` keymap and flashes it over USB. Plain `make keyball/keyball61:german`
(no `:flash`) just compiles, producing `.build/keyball_keyball61_german.uf2`.

## Notes

- `keyball61_german_env/` is gitignored — only `keyball61_german_env-requirements.txt` is
  tracked, so recreate the venv locally on each machine (step 3).
- Keep `qmk_firmware.whangboard2` rebased on whatever upstream you track for this keyboard;
  the keymap itself has no upstream dependency beyond `keyboards/keyball/keyball61/`.
