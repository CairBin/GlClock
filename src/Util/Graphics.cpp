#include "Graphics.h"
#include "GL/freeglut.h"

namespace Clock
{
    void SetPixel(const Point2d &p, const Rgb &rgb)
    {
        glColor3f(UNFOLD_RGB(rgb));
        glBegin(GL_POINTS);
        glVertex2d(p.x, p.y);
        glEnd();
    }

    void CirclePoint(const Point2d &p,
                     const Point2d &center, const Color &color)
    {
        int x = p.x;
        int y = p.y;
        int ox = center.x, oy = center.y;
        glColor3f(UNFOLD_RGB(color));
        glBegin(GL_POINTS);
        glVertex2d(x + ox, y + oy);
        glVertex2d(y + ox, x + oy);
        glVertex2d(-y + ox, x + oy);
        glVertex2d(-x + ox, y + oy);
        glVertex2d(-x + ox, -y + oy);
        glVertex2d(-y + ox, -x + oy);
        glVertex2d(y + ox, -x + oy);
        glVertex2d(x + ox, -y + oy);
        glEnd();
        glLineWidth(1);
    }

    void DrawCircleBresen(const Point2d &circle_center,
                          double R, const Color &color)
    {
        Point2d p;
        p.x = 0, p.y = R;
        int d = 1 - R;
        while (p.x <= p.y)
        {
            CirclePoint(p, circle_center, color);
            if (d <= 0)
                d += 2 * p.x + 3;
            else
            {
                d += 2 * (p.x - p.y) + 5;
                p.y--;
            }

            p.x++;
        }
    }

    void DrawLine(const Point2d &start, const Point &end, unsigned width, const Color &color)
    {
        glColor3f(UNFOLD_RGB(color));
        glLineWidth(width);
        glBegin(GL_LINES);
        glVertex2d(start.x, start.y);
        glVertex2d(end.x, end.y);
        glEnd();
        glLineWidth(1);
    }
}