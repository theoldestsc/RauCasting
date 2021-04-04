#include "Geometry.h"
#include "Point.h"
#include "RGB.h" 
#include <stddef.h>
#include <vector>


class Object
{
    public:
        Object(size_t width, size_t height):geometry(width, height){};
        ~Object(){};
        bool is_collide(int x, int y) const;
        int add_point(Point p){ points.push_back(p);};
        
        void paint(std::ostream& out, RGB rgb);
        friend std::ostream& operator << (std::ostream& out, const Object &obj);
    private:
        std::vector<Point> points;
        Geometry geometry;
};