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

// Inicializa el conjunto con las 26 letras del abecedario y con cero su número de repeticiones.
void CrearConjunto (ELEMENTO *conjunto) {
   int a;
   for (a=0; a<26; a++, conjunto++) {
      conjunto->letra = a+97;
      conjunto->n_veces = 0;
   }
}

// Recibe el conjunto al cual agregar el caracter recibido.
// Lo busca iterando en el array de caracteres (abecedario).
// Si lo encuentra lo agrega, incrementando el número de repeticiones del caracter.
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

// Muestra por pantalla el conjunto pasado. Lo imprime en dos columnas de 13 elementos cada una.
// Imprime la letra, seguido el número de repeticiones de esta.
void Ver (ELEMENTO *conjunto) {
   int a;
   clrscr();
   for (a=0; a<13; a++, conjunto++) {
      printf("Letra %c, repetida: %d\t", conjunto->letra, conjunto->n_veces);
      conjunto++;
      printf("Letra %c, repetida: %d\n", conjunto->letra, conjunto->n_veces);
   }
}

// Verifica si el caracter recibido pertenece al conjunto recibido.
// Pertenece(devuelve 1) si el caracter introducido está en el conjunto y a la vez aparece por lo menos una vez.
// No pertenece (devuelve 0).
int Pertenece (ELEMENTO *conjunto, char caracter) {
   int a;
   for (a=0; a<26; a++, conjunto++) {
      if ( (conjunto->letra==caracter) && (conjunto->n_veces!=0) )
         return 1;
      else continue;
   }
    return 0;
}

// "Une" los conjuntos con ayuda de un tercer conjunto al cual se le afecta el número de repeticiones.
// Un elemento pertenece a un conjunto si el número de repeticiones es diferente de cero.
// Asigna a número de veces del conjunto auxiliar la suma de el número de veces de los otros dos conjuntos
// con respecto a una letra, así hasta terminar de iterar sobre las 26 letras.
void Union_Conj (const ELEMENTO *conjunto, const ELEMENTO *conjunto2, ELEMENTO *resultado) {
   int a;
   for (a=0; a<26; a++, resultado++, conjunto++, conjunto2++)
      (resultado->n_veces) = (conjunto->n_veces) + (conjunto2->n_veces);
}

// Verifica que tanto en el primer como el segundo conjunto el caracter revisado este por lo menos una vez.
// Si cumple la condición se asigna al número de veces del conjunto resultado la suma de los otros dos.
void Inters_Conj(const ELEMENTO *conjunto, const ELEMENTO *conjunto2, ELEMENTO *resultado) {
   int a;
   for (a=0; a<26; a++, conjunto++, conjunto2++, resultado++) {
      if( ((conjunto->n_veces)>0) && ((conjunto2->n_veces)>0) )
         resultado->n_veces = (conjunto->n_veces) + (conjunto2->n_veces);
   }
}

// Itera a traves de los conjuntos y si el el número de veces del caracter es cero en el conjunto resultado
// le asigna lo del otro conjunto (complemento).
void Comple_Conj(const ELEMENTO *conjunto, const ELEMENTO *conjunto2, ELEMENTO *resultado) {
   int a;
   for (a=0; a<26; a++, resultado++, conjunto++, conjunto2++)
      if ((conjunto->n_veces)==0)
         resultado->n_veces = conjunto2->n_veces;
}

