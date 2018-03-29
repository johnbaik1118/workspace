#!/bin/bash
gcc -E target.c -o target.i
sleep 2
gcc -S target.i -o target.s
cat target.s
sleep 2
gcc -c target.s -o target.o
readelf -a target.o > target.elf
sleep 2
gcc target.o -o target
