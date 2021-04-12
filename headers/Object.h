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
        Object(size_t width, size_t height, int xpos, int ypos, RGB rgb);
        ~Object(){};
        bool is_collide(int x, int y) const;
        int add_point(Point p);
        void paint(std::ofstream& out, size_t len);
        virtual void shape(){};
        friend std::ostream& operator << (std::ostream& out, const Object &obj);
    protected:
        std::vector<Point> points;
        Geometry geometry;
        RGB rgb;
};

class Rect: public Object
{
    public:
        Rect(size_t width, size_t height, int x, int y, RGB rgb):Object(width, height, x, y, rgb){};
        void shape() override
        {
            for(int y = geometry.y(); y < geometry.y()+geometry.height(); y++)
            {
                for(int x = geometry.x(); x < geometry.x()+geometry.width(); x++)
                    points.emplace_back(Point(y, x));
            }
        };
        ~Rect(){};
};