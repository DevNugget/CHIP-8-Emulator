# CHIP-8-Emulator
CHIP 8 emulator written in C++

# Compiling The Emulator Yourself
If you would like to compile the emulator yourself, follow the steps mentioned below.

1. Clone this repository to your computer.
  `git clone https://github.com/DevNugget/CHIP-8-Emulator`
2. Download SDL3-devel-3.2.8-mingw.zip from the [SDL GitHub repository](https://github.com/libsdl-org/SDL/releases/tag/release-3.2.8)
3. Extract the contents from the SDL3-devel-3.2.8-mingw.zip file.
4. Copy the `include` and `lib` folders that were inside the SDL3-devel-3.2.8-mingw.zip into the `src` folder located inside the cloned repository folder. (replace any files if needed)
5. Open the main directory of the cloned repository folder in a terminal and run `make`. Try `mingw32-make` if `make` did not work.
6. You should now have an executable called `chip8.exe`.
