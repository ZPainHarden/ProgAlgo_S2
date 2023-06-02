#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
    if (toSort.size() <= 1 ){
        return;
    }
    int pivot = toSort.get(0);

	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes

	// split
    for (int i=1; i<size; i++){
        if (toSort.get(i)<pivot){
            lowerArray[lowerSize] = toSort.get(i);
            lowerSize++;
        }
        else {
            greaterArray[greaterSize] = toSort.get(i);
            greaterSize++;
        }
    }
	// recursiv sort of lowerArray and greaterArray
    recursivQuickSort(lowerArray, lowerSize);
    recursivQuickSort(greaterArray, greaterSize);

    // merge
    for (int i=0; i<lowerSize; i++){
        toSort[i] = lowerArray[i];
    }

    toSort[lowerSize] = pivot;

    for (int j=0; j<greaterSize; j++){
        toSort[lowerSize+j+1] = greaterArray[j];
    }

}

void quickSort(Array& toSort){
	recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(quickSort);
	w->show();

	return a.exec();
}
