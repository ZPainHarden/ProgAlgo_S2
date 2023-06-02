#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;


void bubbleSort(Array& toSort){
	// bubbleSort
    for (uint i=0; i < toSort.size(); i++){
        for (uint j=0; j < toSort.size() - 1; j++){
            if (toSort.get(j) > toSort.get(j+1)){
                toSort.swap(j, j+1);
            }
        }
    }


}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 100;
	w = new TestMainWindow(bubbleSort);
	w->show();

	return a.exec();
}
