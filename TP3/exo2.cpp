#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;

/**
 * @brief define indexMin and indexMax as the first and the last index of toSearch
 * @param array array of int to process
 * @param toSearch value to find
 * @param indexMin first index of the value to find
 * @param indexMax last index of the value to find
 */
void binarySearchAll(Array& array, int toSearch, int& indexMin, int& indexMax)
{
	// do not use increments, use two different binary search loop

    int start = 0;
    int end = array.size();
    int mid = (start + end)/2;
    indexMin = -1;
    indexMax = -1;


    // Même code que exo précédent
    while (start<end){

        mid = (start + end)/2;

        if (toSearch > array.get(mid)){
            start = mid + 1;
        }

        else if (toSearch < array.get(mid)){
            end = mid;
        }

         // J'ai juste rajouté ça pour trouver l'indexMin
        else {
            indexMin = mid;
            // Attention, ne pas oublier cette ligne pour bien trouver l'index min
            end = mid - 1;
        }

    }

    // Si l'indexMin n'a pas été trouvé (donc aucune ocurrence de la valeur toSearch dans le tableau), on retourne -1
    if (indexMin == -1){
        return;
    }

    // Il faut maintenant trouver indiceMax
    // Globalement on reprend la même boucle while légèrement modifiée pour trouver le max et pas le min

    start = indexMin; // Le fait de partir de indexMin permet de se débarasser de la moitié inférieure du tableau
    end = array.size(); // on redéfini également end

    while (start<end){

        mid = (start + end)/2;

        if (toSearch > array.get(mid)){
            start = mid + 1;
        }

        else if (toSearch < array.get(mid)){
            end = mid;
        }

        // On modifie ici pour trouver indexMax
        else {
           indexMax = mid;
           // toujours bien penser à incrémenter pour trouver le bon indexMax
           start = mid + 1;
       }

    }

    return;
}
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchAllWindow(binarySearchAll);
	w->show();

	return a.exec();
}
