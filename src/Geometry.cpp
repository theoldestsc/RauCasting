#include "../headers/Geometry.h"

Geometry::Geometry(size_t width, size_t height, int x, int y):w(width), h(height), xpos(x), ypos(y){}

Geometry Geometry::geometry() const
{
    return *this;
}

size_t Geometry::width() const
{
    return this->w;
}

size_t Geometry::height() const
{
    return this->h;
}

int Geometry::x() const
{
    return this->xpos;
}

int Geometry::y() const
{
    return this->ypos;
}

std::ostream& operator << (std::ostream& out, const Geometry &geometry)
{
    out << "(" << geometry.xpos << "," << geometry.ypos << ") " 
        << geometry.w << " " << "x" << " " << geometry.h;
    return out;
}

Geometry::~Geometry(){}

