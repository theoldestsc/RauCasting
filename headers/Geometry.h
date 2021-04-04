#include <stddef.h>
#include <iostream>


class Geometry
{
    public:
        Geometry(size_t width, size_t height);
        Geometry geometry() const;
        size_t width() const;
        size_t height() const;
        ~Geometry();
        //Remember about friend
        friend std::ostream& operator << (std::ostream& out, const Geometry &geometry);
    private:
        size_t w;
        size_t h; 
};