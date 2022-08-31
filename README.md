# Sokoban

Sokoban (warehouse keeper in Japanese) is a type of transport puzzle, in which
the player pushes boxes or crates around in a warehouse, trying to get them to
storage locations.

The game is played on a board of squares, where each square is a floor or
a wall. Some floor squares contain boxes, and some floor squares are marked as
storage locations. 

The player is confined to the board, and may move
horizontally or vertically onto empty squares (never through walls or boxes).
The player can also move into a box, which pushes it into the square beyond.
Boxes may not be pushed into other boxes or walls, and they cannot be pulled.

The puzzle is solved when all boxes are at storage locations.

This project contains two different versions, one using the ncurses library and the other the CSFML library.

## Ncurses Sokoban

<img src="https://i.postimg.cc/1t3jLpkq/ncurses-sokoban.png" alt="alt text">

## CSFML Sokoban

<img src="https://i.postimg.cc/vmzKqPNy/csfml-sokoban.png" alt="alt text">

### Linux Installer

Clone the repository:

    git clone https://github.com/MayaHill/Sokoban-21-February-7-March.git

Install CSFML

    sudo apt-get install libcsfml-dev libcsfml-doc

To compile (Ncurses):

    make
    
To compile (CSFML):

    cd csfml/
    make

## How to play

    ./my_sokoban -h

## Launch the game

    ./my_sokoban [map file]
    
    (Example: ./my_sokoban maps/map.txt)

Check you are in the csfml/ folder before trying to launch the CSFML version.
