# Space Impact
Space Impact is a 2D arcade shooter inspired by the classic mobile game of the same name. I created a single level with a boss at the end to showcase the use of Raylib and an POO design.
This project was developed as an **assignment for the Graphic Programing course** at the **Universitat Oberta de Catalunya (UOC)**.

## Game Overview
You control a spaceship that must survive an enemy wave and then defeat a boss.
You start with 3 lives, and if you make contact with an enemy or a projectile you lose one live.

### Controls
Use WASD or ARROWS to move/
Use SPACEBAR to shoot.

### Main features:
- State machine controlled game flow
- POO
- Randomized enemy spawn with also random spawn position
- Boss spawns after a set time
- Boss can shoot projectiles
- Collision detection for bullets, enemies and player
- Player invulnerability after getting hit
- Enemies (except boss) get destroyed on touch.
- Sound for impacts, and shoots.
- UI elements, like score and player's health

## Installation

### Supported Platforms
Quickstart supports the main 3 desktop platforms:
* Windows
* Linux
* MacOS

### VSCode Users (all platforms)
*Note* You must have a compiler toolchain installed in addition to vscode.

* Download the quickstart
* Rename the folder to your game name
* Open the folder in VSCode
* Run the build task ( CTRL+SHIFT+B or F5 )
* You are good to go


### Microsoft Visual Studio
* Run `build-VisualStudio2022.bat`
* double click the `.sln` file that is generated
* develop your game
* you are good to go

### Linux Users
* CD into the build folder
* run `./premake5 gmake`
* CD back to the root
* run `make`
* you are good to go

### MacOS Users
* CD into the build folder
* run `./premake5.osx gmake`
* CD back to the root
* run `make`
* you are good to go

### Output files
The built code will be in the bin dir
