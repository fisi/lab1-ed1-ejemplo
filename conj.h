#include <stdio.h>
#include <conio.h>

typedef struct {
   char letra;
   int n_veces;
} ELEMENTO;

/* ------------------ prototipos de conjcar.h ------------------- */
void CrearConjunto (ELEMENTO *conjunto);
   /* Crea el conjunto pasado como parametro a vacio */
void Poner (ELEMENTO *conjunto, char caracter);
   /* inserta una letra pasada como el parametro caracter al conjunto
      pasado como parametro llamado conjunto */
void Ver (ELEMENTO *conjunto);
   /* saca por pantalla los datos del conjunto pasado como
      parametro */
int Pertenece (ELEMENTO *conjunto, char caracter);
   /* devuelve 1 si el caracter pasado como parametro pertenece
      al conjunto pasado como parametro */
void Union_Conj (const ELEMENTO *conjunto, const ELEMENTO *conjunto2, ELEMENTO *resultado);
   /* crea la union de los conjuntos pasados como 2 primeros
      parametros en el conjunto pasado como 3 parametro */
void Inters_Conj(const ELEMENTO *conjunto, const ELEMENTO *conjunto2, ELEMENTO *resultado);
   /* crea la interseccion de los conjuntos pasados como 2 primeros
      parametros en el conjunto pasado como 3 parametro */
void Comple_Conj(const ELEMENTO *conjunto, const ELEMENTO *conjunto2, ELEMENTO *resultado);
   /* crea el complementario respecto del conjunto pasado como 1 parametro
      respecto al conjunto pasado como 2 parametro y lo crea
      en el conjunto pasado como 3 parametro */
/* ------------------ prototipos de conjcar.h ------------------- */


void CrearConjunto (ELEMENTO *conjunto) {
   int a;
   for (a=0; a<26; a++, conjunto++) {
      conjunto->letra = a+97;
      conjunto->n_veces = 0;
   }
}

void Poner (ELEMENTO *conjunto, char caracter) {
   int a;
   for (a=0; a<26; a++) {
      if (conjunto->letra == caracter) {
         (conjunto->n_veces)++;
         break;
      }
      else conjunto++;
   }
}

void Ver (ELEMENTO *conjunto) {
   int a;
   clrscr();
   for (a=0; a<13; a++, conjunto++) {
      printf("Letra %c, repetida: %d\t", conjunto->letra, conjunto->n_veces);
      conjunto++;
      printf("Letra %c, repetida: %d\n", conjunto->letra, conjunto->n_veces);
   }
}

int Pertenece (ELEMENTO *conjunto, char caracter) {
   int a;
   for (a=0; a<26; a++, conjunto++) {
      if ( (conjunto->letra==caracter) && (conjunto->n_veces!=0) )
         return 1;
      else continue;
   }
    return 0;
}

void Union_Conj (const ELEMENTO *conjunto, const ELEMENTO *conjunto2, ELEMENTO *resultado) {
   int a;
   for (a=0; a<26; a++, resultado++, conjunto++, conjunto2++)
      (resultado->n_veces) = (conjunto->n_veces) + (conjunto2->n_veces);
}

void Inters_Conj(const ELEMENTO *conjunto, const ELEMENTO *conjunto2, ELEMENTO *resultado) {
   int a;
   for (a=0; a<26; a++, conjunto++, conjunto2++, resultado++) { 
      if( ((conjunto->n_veces)>0) && ((conjunto2->n_veces)>0) )
         resultado->n_veces = (conjunto->n_veces) + (conjunto2->n_veces);
   }
}

void Comple_Conj(const ELEMENTO *conjunto, const ELEMENTO *conjunto2, ELEMENTO *resultado) {
   int a;
   for (a=0; a<26; a++, resultado++, conjunto++, conjunto2++)
      if ((conjunto->n_veces)==0)
         resultado->n_veces = conjunto2->n_veces;
}   