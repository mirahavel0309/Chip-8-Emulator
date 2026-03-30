#include "Chip8.h"
#include <iostream>

int main() {
    Chip8 myChip8;

    if (!myChip8.LoadROM("test.ch8")) {
        return -1;
    }

	// main emulation loop
    while (true) {
        myChip8.Cycle();
    }

    return 0;
}