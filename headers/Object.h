#include "Geometry.h"
#include "RGB.h" 
#include "Point.h"
#include <stddef.h>
#include <vector>
#include <iomanip>


class Object
{
    //TODO: Parent field
    public:
        Object(size_t width, size_t height);
        ~Object(){};
        bool is_collide(int x, int y) const;
        int add_point(Point p);
        void paint(std::ofstream& out, RGB rgb);
        friend std::ostream& operator << (std::ostream& out, const Object &obj);
    private:
        std::vector<Point> points;
        Geometry geometry;
};

class Rect: public Object
{
    public:
        Rect(size_t width, size_t height):Object(width, height){};
        ~Rect(){};
};