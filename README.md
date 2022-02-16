# cub3D

My implementation of a first-person 3D engine based on the Raycating technology used in such legendary projects as Wolfenstein 3D, Doom, Doom 2.

![screenshot](https://camo.githubusercontent.com/afc4e690f505c950cf294b8315070256d817a8192520b54e26996038eb885e33/68747470733a2f2f692e696d6775722e636f6d2f566631484c52452e706e67)


# About

The project is based on the raycasting technology, the principle of which is to "trace" rays from one coordinate, which is a viewpoint, to other objects. The rays are built in 2D plane to calculate the distance between objects, in order to build them later in 3D space.

# Config file

2D plane in this project is a two-dimensional array of 0 and 1, where 0 is empty space, and 1 - the wall. The starting point of view or just the player is denoted by one of the capital letters of the 4 main sides of the world ("N", "E", "S", "W"). The array may also contain so-called sprites - static plane objects through which the walls can be seen (digit 2). This array is stored in a separate configuration file with the extension <code>.cub</code>, examples of which can be found in the folder maps. In this file you will also find other settings for the application such as the ceiling and floor colors in RGB format, paths as texture files for the walls in four different orientations. And of course you need a separate texture for the sprite (indicated by the letter S).

You can make changes to it to your taste - other textures, change the formatting of the map, change the colors. But be careful, the format is strict, be guided by the example.


<ul>
	<li>R 800 600       - screeen resolution</li>    
	<li>NO ./img/xp1.xpm - texture for north wall</li>
	<li>S ./img/barrel.xpm - texture for sprite</li>
  <li>C 225,0,0 - ceil color</li>
  <li>F 0,255,0 - floor color</li>
</ul>

The map must be enclosed on all sides by walls:

<div>111110</div>
<div>100001</div>
<div>100001</div>
<div>111111</div>
<div>&nbsp;</div>
<div>This is invalid map cause of zero at the right top corner.</div>

# Getting started

Write make in the console in the root directory of the project. Then ./cub3d maps/map21.cub

It is also possible to take a screenshot in <code>.bmp</code> format. To do this, run the application with the appropriate parameter:
<div><code>./cub3d maps/map21.cub --save</code></div>
<div>&nbsp;</div>
The screenshot will be saved in the root of the project.

