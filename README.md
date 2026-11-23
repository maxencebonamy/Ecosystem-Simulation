# Ecosystem Simulation

A cellular automaton simulating plants, preys and predators on a grid.

The simulation runs in an SFML window. Each cell of the grid is empty or holds a plant, a prey or a predator, and the three populations evolve according to simple random rules.

## Table of contents

- [Ecosystem Simulation](#ecosystem-simulation)
	- [Table of contents](#table-of-contents)
	- [How it works](#how-it-works)
	- [Tech stack](#tech-stack)
	- [Repository structure](#repository-structure)
	- [Prerequisites](#prerequisites)
	- [Installation](#installation)
	- [Configuration](#configuration)
	- [Running locally](#running-locally)
	- [License](#license)

## How it works

1. **Initialization**: the grid is filled randomly with plants (1%), preys (2%) and predators (2%). The rest of the cells are empty.
2. **Plants**: a plant can spread to an adjacent empty cell.
3. **Preys**: a prey eats an adjacent plant and takes its cell, and may leave a copy of itself behind. A prey that does not eat can die.
4. **Predators**: a predator eats an adjacent prey in the same way. A predator that does not eat can die.
5. **Controls**: the simulation starts paused. A left click toggles the pause, a right click prints the share of plants, preys and predators in the terminal.

Each cell looks at its eight neighbours, and every transition is drawn at random.

## Tech stack

| Layer | Technologies |
| --- | --- |
| Language | C++17 |
| Rendering and window | SFML 2 (`system`, `window`, `graphics`) |
| Build | CMake 3.10 or later |

## Repository structure

```
.
├── src/
│   ├── main.cpp         Window, event loop
│   ├── config.cpp       Simulation constants
│   ├── config.hpp       Declarations of the constants
│   ├── display/         Grid: rules, update and rendering
│   └── vector/          2D vector class
├── res/                 Window icon
├── lib/SFML/            SFML 2.5 headers and binaries for Windows (MinGW 32)
├── CMakeLists.txt
└── LICENSE
```

All `.cpp` and `.hpp` files under `src/` are picked up by CMake automatically. The program loads `res/icon.png` with a relative path, so it must be started from the repository root.

## Prerequisites

- A C++17 compiler
- [CMake](https://cmake.org/) 3.10 or later
- [SFML](https://www.sfml-dev.org/) 2.x
  - macOS: `brew install sfml@2` (the CMake file looks in `/opt/homebrew/opt/sfml@2` and `/usr/local/opt/sfml@2`)
  - Windows with MinGW 32: the SFML copy in `lib/SFML` is used
  - other systems: install SFML 2 from your package manager

## Installation

```bash
git clone git@github.com:maxencebonamy/Ecosystem-Simulation.git
cd Ecosystem-Simulation
```

Configure and build:

```bash
cmake -S . -B build
cmake --build build
```

## Configuration

There is no environment file. The parameters are constants in [`src/config.cpp`](src/config.cpp); rebuild after changing them.

| Variable | Description | Example |
| --- | --- | --- |
| `WINDOW_SIZE` | Window dimensions, in pixels | `{ 1280, 720 }` |
| `WINDOW_TITLE` | Window title | `"Ecosystem Simulation"` |
| `WINDOW_FPS` | Frame rate limit | `60` |
| `WINDOW_COLOR` | Background color | `{ 4, 8, 41 }` |
| `CELL_SIZE` | Side length of a cell, in pixels | `5` |
| `PLANT_RATE` | Share of plants at start | `0.01` |
| `PLANT_COLOR` | Color of plant cells | `{ 3, 206, 14 }` |
| `PREY_RATE` | Share of preys at start | `0.02` |
| `PREY_COLOR` | Color of prey cells | `{ 254, 255, 255 }` |
| `PREDATOR_RATE` | Share of predators at start | `0.02` |
| `PREDATOR_COLOR` | Color of predator cells | `{ 246, 30, 11 }` |

## Running locally

From the repository root:

```bash
./build/EcosystemSimulation
```

- Left click: start or pause the simulation
- Right click: print the share of each population in the terminal

## License

This project is licensed under the [MIT License](LICENSE).
