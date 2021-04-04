#include "../headers/Geometry.h"

Geometry::Geometry(size_t width, size_t height):w(width), h(height){}

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

std::ostream& operator << (std::ostream& out, const Geometry &geometry)
{
    out << geometry.w << " " << "x" << " " << geometry.h;
    return out;
}

Geometry::~Geometry(){}

