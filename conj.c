/* conjunto de caracteres */
#include <stdio.h>
#include <conio.h>
#include "conj.h"

char menu(void);
void pausa(void);

int main(void) {
   ELEMENTO conjunto[26];
   ELEMENTO conjunto2[26];
   ELEMENTO u_i[26];  /* usado para union e interseccion */
   char a, opcion;
   char letra;
   do {
      a = menu();
      switch(a) {
         case '1':
            CrearConjunto(conjunto);
            CrearConjunto(conjunto2);
            CrearConjunto(u_i);
            pausa();
            break;
         case '2':
            printf("Que conjunto el 1 o el 2: "); opcion = getche();
            printf("\n\tIntroduce letra: ");        letra = getche();
            switch(opcion) {
               case '1':
                  Poner(conjunto, letra); break;
               case '2':
                  Poner(conjunto2, letra); break;
               default:
                   printf("Opcion incorrecta\n");
             }
             pausa();
             break;
         case '3':
            printf("Que conjunto el 1 o el 2: ");
            opcion = getche();
            switch(opcion) {
               case '1':
                  Ver(conjunto); break;
               case '2': 
                  Ver(conjunto2); break;
               default:
                  printf("\nOpcion incorrecta\n");
            }
            pausa();
            break;
         case '4':
            printf("Introduce letra: "); fflush(stdout);
            letra = getche();
            printf(" Introduce conjunto: "); fflush(stdout); 
            opcion = getche();
            switch(opcion) {
               case '1':
                  if (Pertenece(conjunto, letra)) printf("\n\tSi pertenece\n");
                  else printf("\n\tNo pertenece\n");
                  break;
               case '2':
                  if (Pertenece(conjunto2, letra)) printf("\n\tSi pertenece\n");
                  else printf("\n\tNo pertenece\n");
                  break;
            }
            pausa();
            break;
         case '5':
            CrearConjunto(u_i);
            Union_Conj(conjunto, conjunto2, u_i);
            Ver(u_i);
            pausa();
            break;
         case '6':
            CrearConjunto(u_i);
            Inters_Conj(conjunto, conjunto2, u_i);
            Ver(u_i);
            pausa();
            break;
         case '7':
            printf("1. Complemento de primer conjunto sobre el segundo\n");
            printf("2. Complemento de segundo conjunto sobre el primero\n");
            opcion = getche();
            CrearConjunto(u_i);
            switch(opcion) {
               case '1':
                  Comple_Conj(conjunto, conjunto2, u_i); Ver(u_i); pausa();
                  break;
               case '2':
                  Comple_Conj(conjunto2, conjunto, u_i); Ver(u_i); pausa();
                  break;
            }
            pausa();
            break;
         case '8':
            break;
      }
   } while (a != '8');
   textbackground(0);
   textcolor(8);
   clrscr();
   system("cls");
   printf("旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커\n");
   printf("�                        Cesar Laso Laso 1쬌 CNAM                            �\n");
   printf("읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸\n");
   return 0;
}


char menu(void) {
   char color=15;
   textbackground(1);textcolor(color);clrscr();
   textbackground(4);textcolor(color);gotoxy(22,3);  cprintf("�袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴�\n");
   textbackground(4);textcolor(color);gotoxy(22,4);  cprintf("�     Conjunto de Caracteres     �\n");
   textbackground(4);textcolor(color);gotoxy(22,5);  cprintf("훤袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴暠\n");
   textbackground(1);textcolor(color);gotoxy(22,6);  cprintf("\n");
   textbackground(4);textcolor(color);gotoxy(22,7);  cprintf("굇굇굇굇굇굇굇굇굇굇굇굇굇굇굇굇�\n");
   textbackground(4);textcolor(color);gotoxy(22,8);  cprintf("�  1. Crear Conjuntos           굅\n");
   textbackground(4);textcolor(color);gotoxy(22,9);  cprintf("�  2. A쨅dir Caracter           굅\n");
   textbackground(4);textcolor(color);gotoxy(22,10); cprintf("�  3. Ver Conjuntos             굅\n");
   textbackground(4);textcolor(color);gotoxy(22,11); cprintf("�  4. Pertenece Caracter?       굅\n");
   textbackground(4);textcolor(color);gotoxy(22,12); cprintf("�  5. Union                     굅\n");
   textbackground(4);textcolor(color);gotoxy(22,13); cprintf("�  6. Interseccion              굅\n");
   textbackground(4);textcolor(color);gotoxy(22,14); cprintf("�  7. Complemento               굅\n");
   textbackground(4);textcolor(color);gotoxy(22,15); cprintf("�  8. Salir                     굅\n");
   textbackground(4);textcolor(color);gotoxy(22,16); cprintf("굇굇굇굇굇굇굇굇굇굇굇굇굇굇굇굇굅\n");
   textbackground(1);textcolor(color);gotoxy(22,17); cprintf(" ");
   textbackground(4);textcolor(color);gotoxy(23,17); cprintf("같같같같같같같같같같같같같같같같�\n");
   printf("\n");
   return getch();
}


void pausa(void) {
   printf("\nPulsa una tecla para continuar\n");
   getch();
}
   

