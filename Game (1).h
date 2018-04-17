#ifndef Game_h
#define Game_h
#include <vector>

enum Activity{SEEDING,HARVESTING,MOVING,IDLE};

class Tractor{
private:
    int x;
    int y;
    unsigned short size;
    Activity activity;
    
public:
    Tractor();
    Tractor(int x_val,int y_val,unsigned short size_val,Activity activity_val);
    int get_x() const;
    void set_x(int);
    int get_y() const;
    void set_y(int);
    unsigned short get_Size() const;
    void set_Size(unsigned short);
    Activity get_Activity() const;
    void set_Activity(Activity);
};

class Game{
private:
    unsigned int map_size;
    std::vector <Tractor> all;
    std::vector <int> selected;
    
public:
    Game(unsigned int new_size);
    unsigned int get_mapSize();
    void set_mapSize();
    int GetTractor( int x, int y );
    void SelectTractor( int x, int y );
    void SelectTractors( int x1, int y1, int x2, int y2 );
    void AddTractor( Tractor new_unit);
    bool MoveTractor( int i, int new_x, int new_y );
    void AssignTractorsActivity(Activity new_activity);
    void PrintTractor( int i );
    void PrintSelectedTractors();
    void PrintAllTractors();
};


#endif

