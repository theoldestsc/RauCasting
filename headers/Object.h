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
        Geometry geometry() const;
        int add_point(Point p);
        void paint(std::ofstream& out, Object& parent);
        virtual void shape(){}; // TODO:Make pure virtal
        friend std::ostream& operator << (std::ostream& out, const Object &obj);
    protected:
        std::vector<Point> points;
        Geometry gm;
        RGB rgb;
};

class Rect: public Object
{
    public:
        Rect(size_t width, size_t height, int x, int y, RGB rgb):Object(width, height, x, y, rgb){};
        void shape() override
        {
            for(int y = gm.y(); y < gm.y()+gm.height(); y++)
            {
                for(int x = gm.x(); x < gm.x()+gm.width(); x++)
                    points.emplace_back(Point(x, y));
            }
        };
        ~Rect(){};
};