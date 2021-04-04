#include "../headers/Object.h"


bool Object::is_collide(int x, int y) const
{
    for(Point p : points)
    {
        if(p.xpos == x && p.ypos == y)
            return true;
    }
    return false;
}

void Object::paint(std::ostream& out, RGB rgb)
{
    for(Point p : points)
    {
        out.seekp(p.xpos*p.ypos);
        out << rgb;
    }
}


std::ostream& operator << (std::ostream& out, const Object &obj)
{
    out << "Object(" << obj.geometry <<  ")";
}