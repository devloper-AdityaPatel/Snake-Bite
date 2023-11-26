
#ifndef OBJECT
#define OBJECT

/* ----object datatype for mapp */
struct object
{
    int row;
    int col;
    unsigned short int objCode;
};

typedef struct object object;

/* ----definition end---- */
#endif


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