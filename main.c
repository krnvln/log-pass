#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "auth.h"

int main(int argc, char *argv[])
{
    printfHello();


    List list;
    list.start=NULL;
    passww *temp;
    char name[50];
    char pass[50];
    fromFile(&list);

   int kol=0;
    while (1)
    {
        printf("Vvedite name: ");
        scanf("%s",name);
        printf("Vvedite pass: ");
        scanf("%s",pass);
        temp=getpw(&list,name,pass);
        if(temp!=NULL)
        {
            printf("\nVi voshli!\nVvedite noviy pass: ");
            scanf("%s", pass);
            strcpy(temp->pw_passwd,pass);
        }
        else
        {
            kol++;
            if(kol==3)
            {
                break;
            }
        }

    }
    toFile(&list);

}
