#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>


// El primer número triangular >= n l'estratègia de força bruta
int forca_bruta(unsigned int numero){

    unsigned int t, i;

    i=1;
    t = 0;
    while(t < numero){
        t += i;
        i++;
    }

    return t;
}


//Comprovar si un numero es enter o no
bool es_enter(float n_float){

    unsigned int n_enter;
    float resta;
    bool es_en = false;

    n_enter = n_float;
    resta = n_float - n_enter;

    if(resta > 0){
        es_en = false;
    } else {
        es_en = true;
    }

    return es_en;
}


//El primer número triangular >= n amb l'estratègia òptima
int optima(unsigned int numero){

    unsigned int n_enter, n_t;
    float n_float;
    n_float= (((sqrt((8*numero)+1))-1)/2); // la solucio de l'equacio
    n_enter = n_float;

    if(es_enter(n_float)){
        n_t = numero;
    } else {

        n_enter = n_enter + 1;
        n_t = n_enter*(n_enter+1)/2;
    }

    return n_t;
}


// Generador de la taula dels numeros triangulars fins MAX
void genera_taula(int max, int taula[]){

    int i, k;
    k=0; i=1;

    while(i<=max)
    {
        k = k+i;
        taula[i-1]= k;
        i++;
    }

}


// Cerca el primer número triangular >= n de la taula
int cerca_taula(unsigned int numero,int max ,int taula[]){

    unsigned int i, n_t;

    bool trubat;
    i=0;
    while ((i<max) && (!trubat))
    {
        if (numero <= taula[i])
        {
            trubat =true;
            n_t = taula[i];
        }

        i++;
    }

    return n_t;
}


// El primer número triangular >= n amb l'estratègia de taula
int genera_cerca_taula(unsigned int numero){

    unsigned int max, n_t;
    max = 50000;

    int taula[max];

    genera_taula(max, taula);
    if(numero <= 1250025000){
        n_t = cerca_taula(numero, max, taula);
    } else {

        n_t = -1;
        printf("Has escrit un nombre massa gran. \n");
    }

    return n_t;
}


// força bruta per saber si un nombre és triangular o no
bool es_triangular_fb(unsigned int n){

    unsigned int t, i;

    i=1;
    t = 0;
    while(t < n){
        t += i;
        i++;
    }


    return  n == t;

}


//'Optima', per saber si un nombre és triangular o no
bool es_triangular_op(unsigned int n){

    unsigned int es_triangular = false;
    float n_float;
    n_float= (((sqrt((8*n)+1))-1)/2);

    if(es_enter(n_float)){
        es_triangular = true;
    }

    return es_triangular;
}


//'Taula', per saber si un nombre és triangular o no
bool es_triangular_tau(unsigned int n, int taula[]){

    unsigned int i;
    int max = 50000;

    bool triangular = false;
    i=0;
    while ((i<max) && (!triangular ))
    {
        if (n == taula[i])
        {
            triangular =true;
        }
        i++;
    }

    return triangular;

}

//Temps d'execució de les tres estratègies
void temps_execucio(int n_vegades, unsigned int numero){

    int temps_inicial, temps_final, temps_total, i, n_t;
    int max = 50000;
    int taula[max];
    float temps_mitj;

    // Forca Bruta  //////////////////////////////////////
    temps_inicial = time(NULL);

    for(i = 0; i<n_vegades; i++){
        n_t = forca_bruta(numero);
    }

    temps_final = time(NULL);

    temps_total = temps_final - temps_inicial;
    temps_mitj = (float) temps_total / n_vegades;

    printf("\t\t |Forca bruta|\n Numero Triangular >=%d : %d \t N. Vegades: %d  \t Temps Total : %d S \t temps Mitj : %f S \n\n\n",numero ,n_t, n_vegades,temps_total, temps_mitj);
    //////////////////////////////////////////////////////////

    // Optima ///////////////////////////////////////////////
    temps_inicial = time(NULL);

    for(i = 0; i<n_vegades; i++){
        n_t = optima(numero);
    }

    temps_final = time(NULL);

    temps_total = temps_final - temps_inicial;
    temps_mitj = (float) temps_total / n_vegades;

    printf("\t\t |Optima|\n Numero Triangular >=%d : %d \t N. Vegades: %d  \t Temps Total : %d S \t temps Mitj : %f S \n\n\n",numero ,n_t ,n_vegades,temps_total, temps_mitj);
    /////////////////////////////////////////////////////////

    // Taula ///////////////////////////////////////////////
    temps_inicial = time(NULL);

    max = 50000;

    genera_taula(50000, taula);

    for(i = 0; i<n_vegades; i++){
        cerca_taula(numero, max, taula);
    }

    temps_final = time(NULL);

    temps_total = temps_final - temps_inicial;
    temps_mitj = (float) temps_total / n_vegades;

    printf("\t\t |Taula|\n Numero Triangular >=%d : %d \t N. Vegades: %d \t Temps Total : %d S \t temps Mitj : %f S \n\n\n",numero ,n_t ,n_vegades ,temps_total, temps_mitj);
    /////////////////////////////////////////////////////////

}
