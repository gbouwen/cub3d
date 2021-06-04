# cub3d
The aim of this project to create a 3D, Wolfenstein-like maze using ray-casting.  
This is a graphical project, and is intended to make you explore practical applications of mathematics,  
without having to understand the specifics.  
In this project, the user gives a `.cub` file as an argument to the program.  
The program will then use this file to obtain all need information and the program will generate a maze.  

### Requirements
- You must use the `MiniLibX`. MiniLibX is a graphical library provided by 42 network.  
- The management of your window must remain smooth: changing to another window, minimizing, etc.  
- Display different wall textures, that vary depending on which side the wall is facing (North, South, East, West).  
- Your program must be able to display an item (sprite) instead of a wall.  
- Your program must be able to set the floor color and ceiling color.  
- If the second argument is `--save`, the program will save its first rendered image in `.bmp` format.  
- If no second argument is given, the program displays the image in a window and respects the following rules:
  - The left and right arrow key of the keyboard must allow you to look left and right in the maze.
  - The W, A, S, and D keys must allow you to move the point of view through the maze.
  - Pressing ESC must close the window and quit the program cleanly.
  - Click on the red cross on the window's frame must close the window and quit the program cleanly.
  - If the declared screen size in the map is greater than the display resolution, the window size  
    will be set depending on the current display resolution.  
- Your program must take as a first argument a scene description file with the `.cub` extension:
  - The map must be composed of only 4 possible characters:  
    0 for empty space, 1 for a wall, 2 for an item, N/S/E/W for the player's starting position and spawning orientation.
  - The `.cub` file also has a list of identifiers, which have to be included. These are:  
    Resolution, North/South/East/West Texture, Sprite Texture, Floor Color, Ceiling color
  - If any misconfiguration is encountered in the file, the program must exit properly and return an error message.

### Screenshot
![ScreenShot](/img/cub1.png)
