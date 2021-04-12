#include "../headers/Object.h"

Object::Object(size_t width, size_t height, int xpos, int ypos, RGB rgb)
            :gm(width, height, xpos, ypos), rgb(rgb)
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

void Object::paint(std::ofstream& out, Object& parent)
{
    int cur_pos = out.tellp();
    for(Point p : points)
    {
        out.seekp(cur_pos+12*(p.xpos+p.ypos*parent.geometry().width()));
        out << std::setfill('0') << std::setw(3) << rgb.r << " " 
            << std::setfill('0') << std::setw(3) << rgb.g << " " 
            << std::setfill('0') << std::setw(3) << rgb.b << "\n";
    }
}

int Object::add_point(Point p)
{ 
    points.push_back(p);
}

Geometry Object::geometry() const
{
    return this->gm;
}

std::ostream& operator << (std::ostream& out, const Object &obj)
{
    out << "Object(" << obj.gm <<  ")";
    return out;
}