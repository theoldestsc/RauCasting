#include <stddef.h>
#include <string>
#include <fstream>
#include <vector>
#include "Object.h"


class Painter
{
        
    public:
        Painter(size_t width, size_t height);
        int render_image(std::string&& filename);
        Object draw_rectangle(int width, int height, int xpos, int ypos);
        Object draw_point(int xpos, int ypos, int thinckness);
        int draw_line(int xstart, int ystart, int xend, int yend, int thinckness);
        void set_brush(int r, int g, int b);
        void set_brush(RGB rgb);
        Geometry geometry() const;
        const std::vector<std::vector<RGB>>* image_data() const;
        const std::vector<Object>* get_objects() const;
        ~Painter();
    private:
        const Geometry gm;
        RGB rgb;
        std::vector<Object> objects;
        std::vector<std::vector<RGB>> pixels;
    protected:
};