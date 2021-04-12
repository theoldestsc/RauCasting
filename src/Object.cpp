#include "../headers/Object.h"

Object::Object(size_t width, size_t height, int xpos, int ypos, RGB rgb)
            :geometry(width, height, xpos, ypos), rgb(rgb)
{
    points.reserve(width*height);
}

bool Object::is_collide(int x, int y) const
{
    for(Point p : points)
    {
        if(p.xpos == x && p.ypos == y)
            return true;
    }
    return false;
}

void Object::paint(std::ofstream& out, size_t title)
{
    out.seekp(0, out.end);
    //int length = 15;//out.tellp();
    for(Point p : points)
    {
        out.seekp(title+12*(p.xpos+p.ypos*100));//TODO: width
        out << std::setfill('0') << std::setw(3) << rgb.r << " " 
            << std::setfill('0') << std::setw(3) << rgb.g << " " 
            << std::setfill('0') << std::setw(3) << rgb.b << "\n";
    }
}

int Object::add_point(Point p)
{ 
    points.push_back(p);
}


std::ostream& operator << (std::ostream& out, const Object &obj)
{
    out << "Object(" << obj.geometry <<  ")";
    return out;
}