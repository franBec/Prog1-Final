#ifndef LISTA_ATLETA_H_INCLUDED
#define LISTA_ATLETA_H_INCLUDED
#include"TDAatleta.h"
typedef struct nodo
{
    atleta vipd;
    struct nodo *ps;
}nodo;
typedef struct
{
    nodo *acc, *cur, *curaux;
}lista_atleta;
void init_lista(lista_atleta *a)
{
    (*a).acc=NULL;
    (*a).cur=NULL;
    (*a).curaux=NULL;
}
int isOos(lista_atleta a)
{
    if(a.cur==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(lista_atleta a)
{
    if(a.acc==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(lista_atleta a)
{
    nodo *nuevo;
    nuevo=(nodo*)malloc(sizeof(nodo));
    if(nuevo==NULL)
    {
        return 1;
    }
    else
    {
        free(nuevo);
        return 0;
    }
}
void fowards(lista_atleta *a)
{
     (*a).cur=(*(*a).cur).ps;
     (*a).curaux=(*a).cur;
}
void reset(lista_atleta *a)
{
    (*a).cur=(*a).acc;
    (*a).curaux=(*a).acc;
}
void insertar(lista_atleta *a, atleta e)
{
    nodo *nuevo;
    nuevo=(nodo*)malloc(sizeof(nodo));
    (*nuevo).vipd=e;
    if((*a).acc==(*a).cur)
    {
        (*a).acc=nuevo;
        (*nuevo).ps=(*a).cur;
        (*a).cur=(*a).acc;
    }
    else
    {
        (*a).curaux->ps=nuevo;
        (*nuevo).ps=(*a).cur;
        (*a).cur=nuevo;
    }
}
void supress(lista_atleta *a)
{
    if((*a).acc==(*a).cur)
    {
        (*a).acc=(*a).cur->ps;
        free((void*)(*a).cur);
        (*a).cur=(*a).acc;
        (*a).curaux=(*a).acc;
    }
    else
    {
        (*a).curaux->ps=(*a).cur->ps;
        free((void*)(*a).cur);
        (*a).cur=(*a).cur->ps;
    }
}
atleta copiar(lista_atleta a)
{
    return a.cur->vipd;
}


#endif // LISTA_ATLETA_H_INCLUDED
