#ifndef _WINDOW_H_
#define _WINDOW_H_
#include "Core.h"
#include <string>
#include <functional>
namespace Clock
{
    void Display();
    void Update(int value);
    void Config();
    extern unsigned speed;
    class Window
    {
    public:
        typedef struct Option
        {
            unsigned int displayMode;
            int *argc;
            char **argv;
            std::string title;
            BackgroundColor color;
        } Option;

    private:
        Option opt;

    public:
        Window(const Point2d &leftTop, const Size &size, const Option &opt);
        ~Window();
        void Looper();

    private:
        static void DisplayFunc();
        static void UpdateFunc(int value);
    };

}

#endif