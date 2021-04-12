#include "../headers/Painter.h"

Painter::Painter(size_t width, size_t height)
            :gm(width, height, 0, 0), parent(width, height, 0, 0, RGB(0, 0, 0))
{
    parent.shape();
    objects.push_back(parent);
}

Painter::~Painter(){}

Geometry Painter::geometry() const
{
    return gm.geometry();
}

int Painter::render_imagePPM(std::string&& filename)
{
    std::ofstream ofs(filename);
    
    std::stringstream title;
    title << "P3\n" << this->gm.width() << " " << this->gm.height() << "\n" << "255\n";
    ofs << title.str();
    
    size_t len = title.str().length();
    for(Object obj : objects)
    {
        ofs.seekp(len);
        obj.paint(ofs, parent);
    }
    ofs.close();

    return 0;
}

Object Painter::create_rectangle(int width, int height, int xpos, int ypos, RGB rgb)
{
    int offset_by_pos = xpos * ypos;
    int offset_by_size = width * height;
    Rect rect(width, height, xpos, ypos, rgb);
    rect.shape();
    objects.push_back(rect);
    return rect;
}



/*Object Painter::draw_point(int xpos, int ypos, int thinckness)
{
    /*
        TODO:Check input data in every function in class
        TODO:Add custom exeptions
    */
    /*return this->draw_rectangle(thinckness, thinckness, xpos-thinckness/2, ypos-thinckness/2);
}*/

/*int Painter::draw_line(int xstart, int ystart, int xend, int yend, int thinckness)
{
    
}*/
