#ifndef TDAATLETA_H_INCLUDED
#define TDAATLETA_H_INCLUDED
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct m
{
    int cantidad[3];
    int tipo;
}medalla;
typedef struct a
{
    int numerodeatleta;
    char nombreyapellido[500];
    int pais;
    int deporte;
    float puntaje;
    int poseemedalla;
    medalla cant;
    int estado;
}atleta;
int init(atleta *p)
{
    (*p).numerodeatleta=rand()%500+1;
}
void cargarnombreyapellido(atleta *p, char name[])
{
    strcpy((*p).nombreyapellido, name);
}
void cargarpais(atleta *p, int c)
{
    (*p).pais=c;
}
void cargardeporte(atleta *p, int d)
{
    (*p).deporte=d;
}
void cargarpuntaje(atleta *p, float point)
{
    (*p).puntaje=point;
}
void cargarposeemedalla(atleta *p, int n)
{
    (*p).poseemedalla=n;
}
void cargarmedalla(atleta *p, int m[])
{
    int i;
    for(i=0; i<3; i++)
    {
        (*p).cant.cantidad[i]=m[i];
    }
}
void cargarestado(atleta *p, int e)
{
    (*p).estado=e;
}
void modificarpuntaje(atleta *p, float point)
{
    (*p).puntaje=(*p).puntaje + point;
}
void modificarposeemedalla(atleta *p, int n)
{
    (*p).poseemedalla=n;
}
void modificarmedallas(atleta *p, int m[])
{
    int i;
    for(i=0; i<3; i++)
    {
        (*p).cant.cantidad[i]= m[i];
    }
}
void modificarestado(atleta *p, int e)
{
    (*p).estado=e;
}
int mostrarnatleta(atleta p)
{
    return p.numerodeatleta;
}
char* mostrarnombreyapellido(atleta p)
{
    char *ptr;
    ptr=(char*)malloc(sizeof(char)*1000);
    if(ptr!= NULL)
    {
        strcpy(ptr, p.nombreyapellido);
    }
    return ptr;
}
int mostrarpais(atleta p)
{
    return p.pais;
}
int mostrardeporte(atleta p)
{
    return p.deporte;
}
float mostrarpuntaje(atleta p)
{
    return p.puntaje;
}
int mostrarposeemedallas(atleta p)
{
    return p.poseemedalla;
}
medalla mostrarmedalla(atleta p)
{
    return p.cant;
}
int mostrarestado(atleta p)
{
    return p.estado;
}
#endif // TDAATLETA_H_INCLUDED

