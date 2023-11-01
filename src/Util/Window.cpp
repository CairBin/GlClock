#include "Window.h"
#include "GL/freeglut.h"
#include <vector>
#include <iostream>

namespace Clock
{

    Window::Window(const Point2d &leftTop, const Size &size, const Option &opt)
    {
        this->opt = opt;
        glutInit(opt.argc, opt.argv);
        glutInitDisplayMode(opt.displayMode);
        glutInitWindowPosition(leftTop.x, leftTop.y);
        glutInitWindowSize(size.width, size.height);
        glutCreateWindow(opt.title.c_str());
        glClearColor(1, 1, 1, 1);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, size.width, size.height, 0, -1, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glViewport(0, 0, size.width, size.height); // 指定视口大小
        glutDisplayFunc(Window::DisplayFunc);
        glutTimerFunc(speed, Window::UpdateFunc, 1);
    }

    void Window::DisplayFunc()
    {
        Display();
        glFlush();
    }

    void Window::UpdateFunc(int value)
    {
        Update(value);
        glutPostRedisplay();
        glutTimerFunc(speed, Window::UpdateFunc, 1);
    }

    void Window::Looper()
    {
        glutMainLoop();
    }
    Window::~Window()
    {
    }
}