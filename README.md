## GlClock

### 描述
利用freeglut写的一个时钟，并封装了一些简单的工具。
通过每一定时间间隔获取一次系统时间并刷新画面来实现钟表动态。

### 说明

* `Core` - 定义了一些数据类型，如二维点
* `Graphics` - 定义了一些基本绘制方法
* `Time` - 获取系统时间
* `Window` - 窗口绘制和一些回调函数，如`Update(int value)`和`Display()`
* `EntryPoint` - 程序入口

圆的绘制使用了Bresenham算法，直线是使用的OpenGL的方法（主要是直线的Bresenham条件判断太麻烦了）。

### 运行

在编译运行之前请确保freeglut以及所需构建工具已经安装

Linux或者OSX下直接执行脚本
```shell
sh run.sh
```

Windows下请手动执行
```bat
mkdir
cd build
cmake ..
make
.\..\bin\app.exe
```