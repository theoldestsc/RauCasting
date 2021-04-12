#include <stddef.h>
#include <string>
#include <fstream>
#include <vector>
#include "Object.h"
#include <sstream>

class Painter
{
        
    public:
        Painter(size_t width, size_t height);
        Object create_rectangle(int width, int height, int xpos, int ypos, RGB rgb);
        int render_imagePPM(std::string&& filename);
        Geometry geometry() const;
        ~Painter();
    private:
        const Geometry gm;
        Rect parent;
        std::vector<Object> objects;
    protected:
};