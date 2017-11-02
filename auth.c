#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "auth.h"

void printfHello(){
   printf("hello\n");
}

char key[]="udas12";
void encryption(char *s_encrypt)
{
    char *s_decrypt=(char *) malloc(150);
    for (unsigned int i=0; i<strlen(s_encrypt); i++)
    {
        s_decrypt[i] = s_encrypt[i] ^ key[i % strlen(key)];
    }
    s_decrypt[strlen(s_encrypt)]='\0';
    strcpy(s_encrypt,s_decrypt);
}
void decryption(char *s_decrypt
{
    char * s_encrypt=(char *) malloc(150);//
    for(unsigned int i=0; i<strlen(s_decrypt); i++)  //
        s_encrypt[i] = s_decrypt[i] ^ key[i%strlen(key)];  //
    s_encrypt[strlen(s_decrypt)]='\0';//
    strcpy(s_decrypt,s_encrypt); //
}

void add(List *list,  passww *node) {
    if (list->start != NULL) {/
        passww *currentNode = list->start;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = node;
    } else {
        list->start = node;
    }
    node->next = NULL;
}

void fromFile(List *list)
{
    FILE *f;
    char str[150];
    char *name;
    char *pass;
    char *realname;
    f=fopen("1.txt","r");
    while(fgets(str,150,f)!= NULL)
    {
        name=strtok(str,":\n");
        pass=strtok(NULL,":\n");
        realname=strtok(NULL,":\n");
        passww *newNode = (passww *) malloc(sizeof(passww));
        newNode->pw_name=(char *) malloc(strlen(name));
        newNode->pw_passwd=(char *) malloc(strlen(pass));
        newNode->pw_realname=(char *) malloc(strlen(realname));
        decryption(name);
        decryption(pass);
        decryption(realname);
        strcpy(newNode->pw_name,name);
        strcpy(newNode->pw_passwd,pass);
        strcpy(newNode->pw_realname,realname);
        add(list,newNode);

    }
    fclose(f);
}
void addstring(List *list,char *name,char *pass,char *realName)
{
    passww *newNode = (passww *) malloc(sizeof(passww));
    newNode->pw_name=(char *) malloc(strlen(name));
    newNode->pw_passwd=(char *) malloc(strlen(pass));
    newNode->pw_realname=(char *) malloc(strlen(realName));
    strcpy(newNode->pw_name,name);
    strcpy(newNode->pw_passwd,pass);
    strcpy(newNode->pw_realname,realName);
    add(list,newNode);
}

passww * getpw(List *list,	char *name,char *pass)
{
    passww *currentNode = list->start;
    while (currentNode != NULL)
    {
        if ((!strcmp(currentNode->pw_name,name))&&(!strcmp(currentNode->pw_passwd,pass)))
        {
            printf("%s %s %s",currentNode->pw_name, currentNode->pw_passwd,currentNode->pw_realname);
            return currentNode;
        }
        currentNode = currentNode->next;
    }
    return NULL;
}

void  toFile(List *list)
{
    FILE *f;
    f=fopen("1.txt","w");
    passww *currentNode = list->start;
    while (currentNode != NULL)
    {
        encryption(currentNode->pw_name);
        encryption(currentNode->pw_passwd);
        encryption(currentNode->pw_realname);
        fprintf(f,"%s:%s:%s\n",currentNode->pw_name,currentNode->pw_passwd,currentNode->pw_realname);
        currentNode = currentNode->next;//
    }
    fclose(f);
}
