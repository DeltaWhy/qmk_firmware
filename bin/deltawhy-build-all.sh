#!/bin/sh
set -eu

# cd to qmk root
cd "$(dirname "$(realpath -- "$0")")"
cd ..

qmk compile -kb fingerpunch/luakeeb -km deltawhy -e CONVERT_TO=stemcell -e STMC_US=yes
qmk compile -kb fingerpunch/vulpes_minora/rp2040zero -km deltawhy
qmk json2c keyboards/input_club/ergodox_infinity/keymaps/deltawhy/deltawhy.json -o keyboards/input_club/ergodox_infinity/keymaps/deltawhy/keymap_gen.c
qmk compile -kb input_club/ergodox_infinity -km deltawhy
qmk compile -kb klor/2040 -km deltawhy
qmk compile -kb hazel/bad_wings -km deltawhy
qmk compile -kb dragonfruit02 -km deltawhy
