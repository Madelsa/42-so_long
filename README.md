# 42 So_long

So_long is a graphical project at 42 where you will have to create a simple game using the minilibx, a basic library for graphical programming. The project involves creating a game scenario with walls, collectibles, an exit, and a player character. The player has to navigate through the map, collecting items and reaching the exit to win the game. The bonus part of the project allows you to enhance the gameplay or add additional features beyond the mandatory requirements, such as sprite animations.

`NOTE:`This project is only compatible with Macos.

## Table of Contents

- [Description](#description)
- [Preview](#preview)
  -  [Mandatory preview](#mandatory-preview)
  -  [Bonus preview](#bonus-preview)
- [Usage](#usage)
- [Controls](#controls)
- [Map examples](#map-examples)
- [Create your own map](#create-your-own-map)

## Description

So_long is a project that introduces students to the basics of graphical programming and game development. The goal is to create a simple 2D game using the provided graphics library (minilibx).

## Preview

Here's a preview of the game for the mandatory and the bonus parts respectively:

### Mandatory preview
![Mandatory](https://github.com/Madelsa/42-so_long/blob/main/Mandatory.gif)

### Bonus preview
![Bonus](https://github.com/Madelsa/42-so_long/blob/main/Bonus.gif)


## Usage

To play the game:

1. Clone the Repository:
   
   ```bash
   https://github.com/Madelsa/42-so_long.git
   ```
   
2. Change into the project directory:

    ```bash
    cd 42-so_long/mandatory
    ```
    `OR:`
    ```bash
    cd 42-so_long/bonus
    ```

3. Compile the project:

     ```bash
     make
     ```
   
4. Run the game:
   
     ```bash
     ./so_long maps/map1.ber
     ```

## Controls

| Key      | Action           |
| -------- | -----------------|
| W, ↑     | Up               |
| S, ↓     | Down             |
| A, ←     | Left             |
| D, →     | Right            |
| ESC, ⎋   | Close the game   |


## Map examples

Mandatory map example

```text
111111111111
1E10C1001C01
100C110C11C1
1C000CC00001
1011000CC011
1CC10CC000P1
111111111111
```

Bonus map example

```text
111111111111
1E10C1M01C01
10MC110C11C1
1C000CC00001
101100MCC011
1CC10CCM00P1
111111111111
```

## Create your own map

To create your own custom map, you need to abide by the following map rules placed by the project's subject:

1. Map can only contain the following characters:

   1. `0` for an empty space.
   2. `1` for a wall.
   3. `C` for a collectible.
   4. `E` for a map exit.
   5. `P` for the player's starting position.
   6. `M` for a monster (Bonus part).

2. Map must contain `one` Exit (E), `one` Player (P) and `at least one` Collectible (C).
3. Map must be a rectangle
4. Map must be surrounded by walls (`1` for walls).
5. The player must be able to collect all collectibles and exit the map (valid path).
6. Map's file extension must be of type `.ber`. Example: `mymap.ber`. 
