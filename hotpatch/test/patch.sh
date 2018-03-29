#!/bin/bash
gcc -E patch.c -o patch.i
sleep 2
gcc -S patch.i -o patch.s
cat patch.s
sleep 2
gcc -c patch.s -o patch.o
readelf -a patch.o > patch.elf
sleep 2
gcc patch.o -o patch
