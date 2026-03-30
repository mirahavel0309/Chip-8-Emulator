#include "Chip8.h"
#include <cstring>
#include <fstream>

Chip8::Chip8() {
    // Standard entry point for most Chip-8 programs
    pc = 0x200;
    index = 0;
    sp = 0;
    delayTimer = 0;
    soundTimer = 0;

    // Clear all memory and registers
    memset(memory, 0, sizeof(memory));
    memset(v, 0, sizeof(v));
    memset(display, 0, sizeof(display));
    memset(stack, 0, sizeof(stack));

    // TODO: Load font data (0-F) into memory (typically starting at 0x50)
    for (int i = 0; i < 80; ++i) {
        memory[0x50 + i] = fontset[i];
	}
}

bool Chip8::LoadROM(const char* filename)
{
	// Open the ROM file in binary mode and move the file pointer to the end to get its size
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

	// Check if the file was successfully opened
	std::streamsize size = file.tellg();

    if (size <= 0 || size > (4096 - 0x200)) {
        return false; // ROM too large to fit in memory
	}

	file.seekg(0, std::ios::beg);
	file.read((char*)(memory + 0x200), size);

	return true;
}

void Chip8::Cycle()
{
    
}
