#include <fstream>

class RGB
{
    public:
        int r = 0;
        int g = 0;
        int b = 0;
        RGB() = default;
        RGB(int r, int g, int b):r(r), g(g), b(b){};
        friend std::ostream& operator << (std::ostream& out, const RGB &rgb)
        {
            out << rgb.r << " " <<  rgb.g << " " << rgb.b;
        }
};