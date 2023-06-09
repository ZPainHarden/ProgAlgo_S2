#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

void merge(Array& first, Array& second, Array& result);

void splitAndMerge(Array& origin)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
    if (origin.size()<=1){
        return;
    }
	// initialisation
	Array& first = w->newArray(origin.size()/2);
	Array& second = w->newArray(origin.size()-first.size());
	
	// split
    for (int i=0; i<first.size(); i++){
        first[i] = origin[i];
    }

    for (int j=0; j<second.size(); j++){
        second[j] = origin[first.size() + j];
    }

	// recursiv splitAndMerge of lowerArray and greaterArray
    splitAndMerge(first);
    splitAndMerge(second);

	// merge
    merge(first, second, origin);
}

void merge(Array& first, Array& second, Array& result)
{
    uint indiceF = 0;
    uint indiceS = 0;
    for (uint i=0; i < result.size(); i++){

        if (indiceF >= first.size()){
            result[i] = second[indiceS];
            indiceS++;
        }

        else if (indiceS >= second.size()){
            result[i] = first[indiceF];
            indiceF++;
        }

        else if (first[indiceF] < second[indiceS]){
            result[i] = first[indiceF];
            indiceF++;
        }
        else {
            result[i] = second[indiceS];
            indiceS++;
        }
    }
}

void mergeSort(Array& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}
