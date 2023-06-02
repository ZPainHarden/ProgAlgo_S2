#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

// Je ne sais pas pourquoi, une erreur revient lorsque j'essaye de compiler mon code : 'nullptr' is not declared in this scope
// Je ne comprends pas bien pourquoi puisque j'ai commencé à le faire sur les ordis de l'IMAC et je n'avais pas ce soucis...
// En cherchant sur internet j'ai vu que cela venait peut-être d'une mauvaise version de mon compilateur mais je ne veux pas tout casser
// J'ai donc terminé l'exercice (FIFO/LIFO) en ne pouvant pas exécuter le code, j'espère que ça ira


struct Liste{
    Noeud* premier;
    // your code
};

struct DynaTableau{
    int* donnees;
    // your code
    int capacite;
    int size;
};


void initialise(Liste* liste)
{
    liste->premier = nullptr;
}

bool est_vide(const Liste* liste)
{
    if (liste->premier == nullptr){
        return true;
    }
    else {
        return false;
    }
}

void ajoute(Liste* liste, int valeur)
{
    Noeud* newNoeud = new Noeud;
    newNoeud->donnee = valeur;
    newNoeud->suivant = liste->premier;
    liste->premier = newNoeud;

}

void affiche(const Liste* liste)
{
    Noeud* current;
    current = liste->premier;
    while (current != nullptr){
        cout << current->donnee << endl;
        current -> suivant;
    }

}

int recupere(const Liste* liste, int n)
{
    Noeud* current;
    current->donnee = liste->premier;

    // On regarde quand même si la liste est vide avant tout
    if (est_vide(liste)){
        cout << "La liste est vide" <<endl;
    }

    int i = 0;

    while(i<n){
        i++;
        current->suivant;
    }

    return current->donnee;

}

int cherche(const Liste* liste, int valeur)
{
    Noeud* current;
    current->donnee = liste->premier;

    // On regarde quand même si la liste est vide avant tout
    if (est_vide(liste)){
        cout << "La liste est vide" <<endl;
    }

    int index = 0;

    while(current->donnee != valeur){
        index;
        current = current->suivant;
    }

    return index;
}

void stocke(Liste* liste, int n, int valeur)
{
    Noeud* current;
    current->donnee = liste->premier;

    // On regarde quand même si la liste est vide avant tout
    if (est_vide(liste)){
        cout << "La liste est vide" <<endl;
    }

    int index = 0;

    while(current->donnee != valeur){
        index;
        current = current->suivant;
    }

    current->donnee = valeur;

}

void ajoute(DynaTableau* tableau, int valeur)
{
    if (tableau->capacite =< tableau->size){
        tableau->capacite *= 2;

        int* temporaire = new int[tableau->capacite];
        for (int i = 0; tableau->size; i++){
            temporaire[i] = tableau->donnees[i];
        }
        tableau->donnees = temporaire;
    }

    tableau->donnees[tableau->size] = valeur;
    tableau->size += 1;
}



void initialise(DynaTableau* tableau, int capacite)
{
    tableau->capacite = capacite;
    tableau->size = 0;
    tableau->donnees = new int[capacite];
}

bool est_vide(const DynaTableau* liste)
{
    return liste->size == 0;
}

void affiche(const DynaTableau* tableau)
{
    // On regarde quand même si le tableau est vide avant tout
    if (est_vide(tableau)){
        cout << "Le tableau est vide" <<endl;
    }

    for (int i=0; tableau->size; i++){
        cout << tableau->donnees[i]; endl;
    }

}

int recupere(const DynaTableau* tableau, int n)
{
    // On regarde quand même si le tableau est vide avant tout
    if (est_vide(tableau)){
        cout << "Le tableau est vide" <<endl;

    if (tableau->size >= n){
        return tableau->donnees[n];
    }

    return 0;
}

int cherche(const DynaTableau* tableau, int valeur)
{

    // On regarde quand même si le tableau est vide avant tout
    if (est_vide(tableau)){
        cout << "Le tableau est vide" <<endl;

    for(int i=0; i < tableau->size; i++){
        if (tableau->donnees[i] == valeur){
            return i;
        }
    }
    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    if (tableau->size > n){
        tableau->donnees[n] = valeur;
    }
}

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur)
{
    if (est_vide(liste)){
        liste->premier = new Noeud {valeur, nullptr};
    }

    Noeud* current = liste->premier;
    while(current->suivant != nullptr){
        current->suivant;
    }

    current->suivant = new Noeud {valeur, nullptr};

}

//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    int retire = 0;

    if (est_vide(liste) == false){
        Noeud* current = liste->premier;
        retire = current->donnee;
        liste->premier = current->suivant;
        free(current);
    }

    return retire;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur)
{
    Noeud* current = new Noeud;
    current->donnee = valeur;
    current->suivant = liste->premier;
    liste->premier = current;
}

//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste)
{
    int retire = 0;

    if (est_vide(liste == false)){
        Noeud* current = liste->premier;
        retire = current->donnee;
        liste->premier = current->suivant;
        free(current);
    }

    return retire;
}


int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
