# Snake Game
A simple Snake Game developed using **C** and **SDL2** on Linux. This project features a graphical window, keyboard control using arrow keys, score display, start menu, and game over screen.

## Features
- Smooth snake movement
- Start menu and game over screen
- Score tracking
- Keyboard controls using arrow keys
- Window-based rendering with SDL2

# Technologies Used
- C Language
- SDL2 (Simple DirectMedia Layer)
- SDL2_ttf for text rendering
- Makefile for building the project

## Requirements
- SDL2
- SDL2_ttf
- GCC or Clang

Install on Debian/Ubuntu:
sudo apt install libsdl2-dev libsdl2-ttf-dev

Build and Run
make
./snake

Project Structure
SnakeGame/
├── src/              # Source files
├── include/          # Header files
├── assets/           # Fonts, images
├── Makefile          # Build file
└── README.md         # Project documentation

Controls
    ← ↑ ↓ → : Move snake
    Enter : Start game
    Esc : Exit
