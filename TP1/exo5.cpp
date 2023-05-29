#include "tp1.h"
#include <QApplication>
#include <time.h>

int isMandelbrot(Point z, int n, Point point){
    // recursiv Mandelbrot
    // check n
    if(n==0){
        return 1;
    }
    // check length of z
    // if Mandelbrot, return 1 or n (check the difference)
    if(z.length()>2)
    // otherwise, process the square of z and recall
    // isMandebrot
    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MandelbrotWindow(isMandelbrot);
    w->show();

    a.exec();
}



