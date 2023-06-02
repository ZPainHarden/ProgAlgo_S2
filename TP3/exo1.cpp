#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;

int binarySearch(Array& array, int toSearch)
{
    // Ce code est vraiment la traduction de l'algorithme du pdf du TP3
    int start = 0;
    int end = array.size();

    while (start<end){

        int mid = (start+end)/2;

        // On se débarasse de la partie basse du tableau
        if (toSearch > array.get(mid)){
            start = mid + 1;
        }

        // On se débarrasse de la partie haute du tableau
        else if (toSearch < array.get(mid)){
            end = mid;
        }

        else {
            return mid;
        }

    }

	return -1;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchWindow(binarySearch);
	w->show();

	return a.exec();
}
