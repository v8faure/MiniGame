# MiniGame
Project so_long from Ecole42(School21)
![image](https://user-images.githubusercontent.com/104635140/167306867-25debdc2-3cd9-4238-8b14-5e186453146a.png)

This is a small graphic project to learn how to work with windows and handle events.
Example of the result you can see in attached picture.
This is a map bounded by a wall. Using the WASD buttons or arrows, you can move the character along it. If you collect all collectibles, the exit will open. If you move to it, the window will close. If you touch the enemies, the window will close. Same if you press ESC.

If you want to try it, clone repository.
On linux in comandline use make. On MacOS make macos
For execute make exe.

The program reads the map layout from files of the type .ber
Rules:
  - the map must be rectangularж
  - 0(zero) - floor;
  - 1 - wall, the map must be surrond 1;
  - P - player, must be only 1;
  - E - exit,  must be only 1;
  - C - collectibles;
  - F - foe.

If you want you can use your own images. 
  - size 64*64;
  - type xpm;
