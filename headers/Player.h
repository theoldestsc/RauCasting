#include <stddef.h>


class Player
{
    public:
        Player(int xpos, int ypos, double angle_view):xpos(xpos),ypos(ypos),angle_view(angle_view){};
        int xpos;
        int ypos;
        double angle_view;
        ~Player(){};
};