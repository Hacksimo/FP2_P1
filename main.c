#include <stdio.h>
#include <stdlib.h>
#define MAX 50000
#include "procediments.h"

int main()
{
    unsigned int nombre, n_vegades = 10000000;
    int taula[MAX];

    printf("Escriu el nombre que vulguis comprobar : ");
    scanf("%d", &nombre);

    genera_taula(MAX, taula);


    // Forca bruta
    if(es_triangular_fb(nombre)){
        printf("Forca bruta : %d es triangular.\n", nombre);
    } else {
        printf("Forca bruta : %d no es triangular.\n", nombre);
    }

    // Optima
    if(es_triangular_op(nombre)){
        printf("Optima : %d es triangular.\n", nombre);
    } else {
        printf("Optima : %d no es triangular.\n", nombre);
    }

    // Taula
    if(es_triangular_tau(nombre, taula)){
        printf("Taula : %d es triangular.\n\n\n", nombre);
    } else {
        printf("Taula : %d no es triangular.\n\n\n", nombre);
    }

    //Temps d'execució de les tres estratègies
    temps_execucio(n_vegades, nombre);

    return 0;
}
