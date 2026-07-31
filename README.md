# 🧱 Tetris (C++ / raylib)

A classic Tetris game built from scratch in **C++** using the **raylib** graphics library — featuring all 7 standard tetrominoes, rotation, line clearing, scoring, and a next-piece preview.

## Screen Shots


## video Recording Game

📹 [Watch gameplay demo](https://youtu.be/QKUKv6TlsW0)

## 🎮 Features

- Full set of 7 tetrominoes (I, J, L, O, S, T, Z) with accurate rotation states
- Smooth block movement (left, right, down) with collision and boundary detection
- Row-clearing logic with cascading row shifts
- Scoring system (bonus points for clearing 1, 2, or 3+ lines, plus soft-drop points)
- "Next block" preview panel
- Game-over detection and instant restart
- Object-oriented design: separate classes for `Position`, `Block`, `Grid`, and `Game`

## 🛠️ Built With

- **C++**
- **[raylib](https://www.raylib.com/)** — for windowing, input, and 2D rendering

## 📁 Project Structure

```
├── main.cpp        # Game loop, window setup, and UI drawing
├── game.cpp/.h      # Core game logic: input handling, locking, scoring
├── grid.cpp/.h      # The playing field: cell state, row clearing
├── block.cpp/.h     # Base Block class: drawing, movement, rotation
├── blocks.cpp       # The 7 tetromino subclasses (I, J, L, O, S, T, Z)
└── position.cpp/.h  # Simple row/column position helper
```

## 🚀 Getting Started

### Prerequisites

- A C++ compiler (g++ / MSVC / clang)
- [raylib](https://github.com/raysan5/raylib) installed on your system

### Build & Run

**Linux / macOS (g++):**
```bash
g++ main.cpp game.cpp grid.cpp block.cpp blocks.cpp position.cpp -o tetris -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./tetris
```

**Windows (with raylib + MinGW):**
```bash
g++ main.cpp game.cpp grid.cpp block.cpp blocks.cpp position.cpp -o tetris.exe -lraylib -lopengl32 -lgdi32 -lwinmm
tetris.exe
```

> 💡 If you're using an IDE like Visual Studio Code or CLion, set up a raylib project template and add these `.cpp` files to it instead.

## 🕹️ Controls

| Key | Action |
|-----|--------|
| `←` | Move block left |
| `→` | Move block right |
| `↓` | Soft drop (move down) |
| `R` | Rotate block |
| Any key | Restart after game over |

## 📚 What I Learned

This project was a hands-on exercise in:
- Object-oriented programming in C++ (inheritance, polymorphism)
- 2D graphics rendering and game loops with raylib
- Grid-based collision detection
- Game state management (spawning, locking, clearing, scoring)

## 👩‍💻 Author

**Laiba Ahmad**

## 📄 License

This project is open source and available for learning purposes.
