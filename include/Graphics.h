#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_
#include "Core.h"

namespace Clock
{
    void SetPixel(const Point2d &p, const Rgb &rgb);

    void CirclePoint(const Point2d &p, const Point2d &center, const Color &color);
    void DrawCircleBresen(const Point2d &circle_center, double R, const Color &color);
    void DrawLine(const Point2d &start, const Point &end, unsigned width, const Color &color);
}

#endif