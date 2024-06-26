# Snake-Bite
it is command line based simple game designed in c programming language

# Use createmetadata.c for creating new maps.

# Use displaymap.c to view already create map.

# Use readmetadata.c to read sparse matrix of map.


To play the game:
1. convert playgame.c into object file.
2. run command - "playgame.exe [mapname.exetension]" into command terminal
3. enter keys to move player :
    * 'w' - to move upward
    * 'a' - to move left
    * 's' - to move down
    * 'd' - to move right
    * 'u' - to undo your last move




/* OBJECT Description
 *
 *
 * (<object row>, <object col>) is rerpersenting the location of object in map
 * <object code> : it repersents the object type integer value  
 * 
 * <object code> 
 *  0 : The player(P)
 *  1 : snake (~)
 *  2 : vertical walls (|)
 *  3 : horizontal walls(-)
 *  4 : corners (*)
 *  5 : hurdle(=)
 *  6 : target(X)
 *  7 : moveable area(' ')
 *  */
