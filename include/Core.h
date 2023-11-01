#ifndef _POINT2D_H_
#define _POINT2D_H_

#define UNFOLD_RGB(rgb) rgb.r, rgb.g, rgb.b

namespace Clock
{
    typedef struct Point2d
    {
        double x, y;
        Point2d(double x, double y) : x(x), y(y) {}
        Point2d() : x(0), y(0) {}
    } Point;

    typedef struct Size
    {
        int width, height;
        Size(int width, int height) : width(width), height(height) {}
        Size() : Size(0, 0) {}
    } Size;

    typedef struct Rgb
    {
        double r, g, b;
        Rgb(double r, double g, double b) : r(r), g(g), b(b) {}
        Rgb() : Rgb(0, 0, 0) {}
    } Rgb, Color, BackgroundColor;

}
#endif