Phil Tsao

This is an implementation of a simple framework for “Little Farm” which is a real-time strategy game.
There are two files, a header file with declarations, Game.h, and the implementation file, Game.cpp.

I.
I implemented:
 Game(unsigned int new_size) the default constructor that initializes an empty Game object for the map of new_size.
int GetTractor(int x, int y) returns the index in all-vector of the tractor that occupies location (x,y)
void SelectTractor(int x, int y)selects the tractor located on (x,y).
void SelectTractors(int x1, int y1, int x2, int y2) selects all tractors located in the rectangular defined by (x1,y1) and (x2,y2).
void AddTractor(Tractor new_unit) adds the new tractor to all-vector.
bool MoveTractor(int i, int new_x, int new_y)moves the tractor number i to the new coordinates if it is possible and returns true value to signal the success. If moving is not possible, leave the tractor at initial position and return false value. 
void AssignTractorsActivity(Activity new_activity)sets the new_activity for all selected tractors.
void PrintTractor(int i) prints the tractor number i from the all-vector. In other words, print all fields of that unit.
void PrintSelctedTractors() prints selected units.
void PrintAllTractors() prints all units.

