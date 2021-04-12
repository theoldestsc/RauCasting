#include <stddef.h>
#include <iostream>


class Geometry
{
    public:
        Geometry(size_t width, size_t height, int xpos, int ypos);
        Geometry geometry() const;
        size_t width() const;
        size_t height() const;
        int x() const;
        int y() const;
        ~Geometry();
        //Remember about friend
        friend std::ostream& operator << (std::ostream& out, const Geometry &geometry);
    private:
        size_t w;
        size_t h;
        int xpos;
        int ypos;        
};