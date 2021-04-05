#include "../headers/Painter.h"

Painter::Painter(size_t width, size_t height)
            :gm(width, height)
{
    pixels.resize(height, std::vector<RGB>(width));
}

Painter::~Painter(){}

Geometry Painter::geometry() const
{
    return gm.geometry();
}

const std::vector<std::vector<RGB>>* Painter::image_data() const
{
    return &pixels;
}

const std::vector<Object>* Painter::get_objects() const
{
    return &objects;
}

void Painter::set_brush(int r, int g, int b)
{
    rgb.r = r;
    rgb.g = g;
    rgb.b = b;
}

void Painter::set_brush(RGB rgb)    
{
    rgb = rgb;
}

int Painter::render_image(std::string&& filename)
{
    std::ofstream ofs(filename);
    ofs << "P3\n" << this->gm.width() << " " << this->gm.height() << "\n" << "255\n"; 
    for(std::vector<RGB> v : pixels)
    {
        for(RGB rgb : v)
        {
            ofs << rgb.r << " " << rgb.g << " " << rgb.b << "\n";
        }
    }
        
        
    ofs.close();

    return 0;
}

int Painter::render_imageobj(std::string&& filename)
{
    std::ofstream ofs(filename);
    
    std::stringstream title;
    title << "P3\n" << this->gm.width() << " " << this->gm.height() << "\n" << "255\n";
    ofs << title.str(); 
    for(Object obj : objects)
    {
        obj.paint(ofs, rgb);
    }
    ofs.close();

    return 0;
}

Object Painter::create_rectangle(int width, int height, int xpos, int ypos)
{
    int offset_by_pos = xpos * ypos;
    int offset_by_size = width * height;
    Object rect(width, height);

    for(int y = ypos; y < ypos+height; y++)
    {
        for(int x = xpos; x < xpos+width; x++)
        {
            rect.add_point(Point(x, y));
        }
    }
    objects.push_back(rect);
 
    return rect;
}



Object Painter::draw_rectangle(int width, int height, int xpos, int ypos)
{
    int offset_by_pos = xpos * ypos;
    int offset_by_size = width * height;
    Object rect(width, height);

    for(int y = ypos; y < ypos+height; y++)
    {
        for(int x = xpos; x < xpos+width; x++)
        {
            rect.add_point(Point(x, y));
            pixels[y][x].r = rgb.r;
            pixels[y][x].g = rgb.g;
            pixels[y][x].b = rgb.b;
        }
    }
    objects.push_back(rect);
 
    return rect;
}

Object Painter::draw_point(int xpos, int ypos, int thinckness)
{
    /*
        TODO:Check input data in every function in class
        TODO:Add custom exeptions
    */
    return this->draw_rectangle(thinckness, thinckness, xpos-thinckness/2, ypos-thinckness/2);
}

int Painter::draw_line(int xstart, int ystart, int xend, int yend, int thinckness)
{
    
}
