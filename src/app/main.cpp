#include "GL/freeglut.h"
#include "Util.h"
#include <cmath>
#include <iostream>
#define WIDTH 1000
#define HEIGHT 800
#define RADIUS 200
#define PI 4.0 * atan(1.0)

Clock::Size winSize(WIDTH, HEIGHT);
Clock::Point2d winPos(100, 100);
Clock::Window::Option winOpt = {
    GLUT_SINGLE | GLUT_RGB,
    NULL,
    NULL,
    "Clock",
    Clock::Color(1, 1, 1),
};

unsigned Clock::speed = 200;

void DrawScale(const Clock::Point &center, const Clock::Color &color)
{

    Clock::Point2d start, end;
    for (int i = 0; i < 60; i++)
    {
        // 让3 6 9 12这几个刻度长一点
        int len = (i % 5) ? RADIUS / 20 : RADIUS / 9.5;
        start.x = center.x + (RADIUS - len) * cos(PI / 30 * i);
        start.y = center.y + (RADIUS - len) * sin(PI / 30 * i);
        end.x = center.x + RADIUS * cos(PI / 30 * i);
        end.y = center.y + RADIUS * sin(PI / 30 * i);
        glColor3f(UNFOLD_RGB(color));
        glBegin(GL_LINES);
        glVertex2d(start.x, start.y);
        glVertex2d(end.x, end.y);
        glEnd();
        // DrawLine(start, end);
    }
}

void DrawPointer()
{
    Clock::Time time;

    double h_deg = -PI / 2 + PI / 6 * (time.GetHour() % 12) + PI * time.GetMin() / 360 + PI * time.GetSec() / 6 / 3600;
    double h_x = WIDTH / 2 + (RADIUS - 80) * cos(h_deg);
    double h_y = HEIGHT / 2 + (RADIUS - 80) * sin(h_deg);

    double m_deg = -PI / 2 + PI * time.GetMin() / 30 + PI * time.GetSec() / 1800;
    double m_x = WIDTH / 2 + (RADIUS - 50) * cos(m_deg);
    double m_y = HEIGHT / 2 + (RADIUS - 50) * sin(m_deg);

    double s_deg = -PI / 2 + 2 * PI / 60 * time.GetSec();
    double s_x = WIDTH / 2 + (RADIUS - 10) * cos(s_deg);
    double s_y = HEIGHT / 2 + (RADIUS - 10) * sin(s_deg);

    // printf("%d:%d:%d\n", time.GetHour(), time.GetMin(), time.GetSec());

    DrawLine({WIDTH / 2, HEIGHT / 2},
             {h_x, h_y},
             5,
             Clock::Color(1, 1, 0));
    DrawLine({WIDTH / 2, HEIGHT / 2},
             {m_x, m_y},
             3,
             Clock::Color(0, 0, 1));
    DrawLine({WIDTH / 2, HEIGHT / 2},
             {s_x, s_y},
             1,
             Clock::Color(1, 0, 0));
}

void DrawClock()
{
    DrawCircleBresen({WIDTH / 2, HEIGHT / 2}, RADIUS, Clock::Color(0, 0, 1));
    DrawScale({WIDTH / 2, HEIGHT / 2}, Clock::Color(1, 0, 0));
}

/************************************************/

void Clock::Config()
{
}

void Clock::Display()
{
    DrawClock();
    DrawPointer();
}

void Clock::Update(int value)
{
    glClear(GL_COLOR_BUFFER_BIT);
}