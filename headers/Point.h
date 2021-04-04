struct Point
{
    int xpos;
    int ypos;
    Point(int x, int y):xpos(x), ypos(y){};
    friend std::ostream& operator << (std::ostream& out, const Point &point)
    { 
        out << point.xpos << " " << point.ypos;
        return out;
    }
};
