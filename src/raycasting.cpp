#include <iostream>
#include <string>
#include "../headers/Painter.h"
#include "../headers/Player.h"
#include <cmath>
#define PI 3.14159265

/*TODO: */

int draw_map(Painter& canvas)
{
    Painter test(100, 100);
    //test.set_brush(0,255,0);
    //test.set_brush(0,0,0);
    test.create_rectangle(100, 100, 0, 0, RGB(255, 0, 0));
    test.create_rectangle(50, 50, 0, 0 ,  RGB(0, 0, 255));
    
    test.render_imagePPM("test.ppm");
    
    /*canvas.set_brush(100,180,120);
    canvas.draw_rectangle(5,5,40,5);
    canvas.set_brush(100,190,120);
    canvas.draw_rectangle(5,5,40,10);
    canvas.set_brush(100,180,140);
    canvas.draw_rectangle(5,5,45,15);
    canvas.set_brush(100,180,180);
    canvas.draw_rectangle(5,5,50,20);
    canvas.set_brush(150,180,120);
    canvas.draw_rectangle(15,5,55,25);
    canvas.set_brush(180,185,120);
    canvas.draw_rectangle(5,25,55,30);
    canvas.set_brush(200,185,120);
    canvas.draw_rectangle(5, canvas.geometry().height(), 0, 0);
    canvas.set_brush(180,185,120);
    canvas.draw_rectangle(canvas.geometry().width(), 5, 0, canvas.geometry().height()-5);
    canvas.draw_rectangle(5, canvas.geometry().height(), canvas.geometry().width()-5, 0);
    canvas.draw_rectangle(canvas.geometry().width(), 5, 0, 0);

    canvas.render_image("output.ppm");*/
    
    return 0;
}

int main()
{
    Painter painter(100, 100);
    Player gamer(20, 20, 30);
    draw_map(painter);
    //painter.set_brush(255,255,255);
    std::vector<Point> points;
    /*for(int c = 0; ; c+=1)
    {
        int x = gamer.xpos + c*cos(gamer.angle_view*PI/180);
        int y = gamer.xpos + c*sin(gamer.angle_view*PI/180); 
        std::cout << x << " " << y << " " << c <<std::endl;
        bool flag = true;
        for(Object obj : *painter.get_objects())
        {
            if(obj.is_collide(x, y))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            points.push_back(Point(x,y));
        }
        else
            break;
        /*if(y != painter.geometry().height() && x != painter.geometry().width()){
        }*/
    /*}
    for(Point p : points)
            painter.draw_point(p.xpos, p.xpos, 1);
        painter.render_image("output.ppm");*/
    
    //Geometry gm(100,100);
    //Geometry obj = gm.geometry();
    //std::cout << obj;
    //img.draw_rectangle(5,5,0,0);
    //img.render_image("output.ppm");
}