#ifndef _ENTRYPOINT_H_
#define _ENTRYPOINT_H_

extern void Clock::Display();
extern Clock::Point2d winPos;
extern Clock::Size winSize;
extern Clock::Window::Option winOpt;
extern void Clock::Update(int value);
extern unsigned Clock::speed;
extern void Clock::Config();

int main(int argc, char **argv)
{
    winOpt.argc = &argc;
    winOpt.argv = argv;
    Clock::Window *app = new Clock::Window(winPos, winSize, winOpt);
    app->Looper();
    delete app;
    return 0;
}

#endif