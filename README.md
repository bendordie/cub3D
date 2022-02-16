# cub3D

My implementation of a first-person 3D engine based on the Raycating technology used in such legendary projects as Wolfenstein 3D, Doom, Doom 2.

![screenshot](https://camo.githubusercontent.com/afc4e690f505c950cf294b8315070256d817a8192520b54e26996038eb885e33/68747470733a2f2f692e696d6775722e636f6d2f566631484c52452e706e67)


# About

The project is based on the raycasting technology, the principle of which is to "trace" rays from one coordinate, which is a viewpoint, to other objects. The rays are built in 2D plane to calculate the distance between objects, in order to build them later in 3D space.

# Config file

2D plane in this project is a two-dimensional array of 0 and 1, where 0 is empty space, and 1 - the wall. The starting point of view or just the player is denoted by one of the capital letters of the 4 main sides of the world ("N", "E", "S", "W"). The array may also contain so-called sprites - static plane objects through which the walls can be seen (digit 2). This array is stored in a separate configuration file with the extension <code>.cub</code>, examples of which can be found in the folder maps. In this file you will also find other settings for the application such as the ceiling and floor colors in RGB format, paths as texture files for the walls in four different orientations. And of course you need a separate texture for the sprite (indicated by the letter S).

Вы можете вносить в него изменения на свой вкус - другие текстуры, изменить формацию карты, изменить цвета. Но будьте аккуратны, формат строгий: одна линия - один параметр



