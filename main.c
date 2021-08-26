#include <stdio.h>
#include <stdlib.h>
#include"TDAatleta.h"
#include"lista_atleta.h"
#define MAXI 500
void cargaratleta(lista_atleta *, int);
atleta buscaratleta(lista_atleta*, int);
void mostraratleta(lista_atleta, int);
void mostraratletaporpais(lista_atleta, int);
void modificaratletapuntaje(lista_atleta *, int);
void mostrarranking(lista_atleta, int);
void asignarmedalla(lista_atleta *, int);
void modificaratletaestado(lista_atleta *, int);
void eliminaratleta(lista_atleta *);
void mostrartipo(lista_atleta, int);
void recursivo(lista_atleta, atleta, int, int);
void cargararchivo(lista_atleta, int);
void precarga(lista_atleta *);
void mostrarclasificacion(lista_atleta);
int main()
{
    //system("color 3f");
    int cantidad, numero, aux, aux2, country, num, depor, num2, num3, clase, country2;
    lista_atleta d;
    atleta a;
    init_lista(&d);
    do
    {
        printf("----------------------------------------------------\n");
        printf("|<1> Cargar atletas                                 |\n");
        printf("|<2> Mostrar atleta por numero                      |\n");
        printf("|<3> Mostrar atletas por pais                       |\n");
        printf("|<4> Modificar puntaje de un atleta                 |\n");
        printf("|<5> Mostrar ranking en un deporte determinado      |\n");
        printf("|<6> Asignar medallas                               |\n");
        printf("|<7> Modificar estado de un atleta                  |\n");
        printf("|<8> Eliminar atletas eliminados                    |\n");
        printf("|<9> Mostrar altetas por tipo de medalla            |\n");
        printf("|<10> Mostrar atleta con mayor cantidad de medallas |\n");
        printf("|<11> Guardar en archivo atletas de un pais         |\n");
        printf("|<12> Cargar atletas por archivo (sin medallas)     |\n");
        printf("|<13> Mostrar atletas clasificados                  |\n");
        printf("|<14> Salir                                         |\n");
        printf("----------------------------------------------------\n");
        while (!scanf("%d", &aux))
        {
            printf ("Ingrese un numero\n");
            fflush(stdin);
        }
        while(aux<0 || aux>14)
        {
            printf("----------------------------------------------------\n");
            printf("|<1> Cargar atletas                                 |\n");
            printf("|<2> Mostrar atleta por numero                      |\n");
            printf("|<3> Mostrar atletas por pais                       |\n");
            printf("|<4> Modificar puntaje de un atleta                 |\n");
            printf("|<5> Mostrar ranking en un deporte determinado      |\n");
            printf("|<6> Asignar medallas                               |\n");
            printf("|<7> Modificar estado de un atleta                  |\n");
            printf("|<8> Eliminar atletas eliminados                    |\n");
            printf("|<9> Mostrar altetas por tipo de medalla            |\n");
            printf("|<10> Mostrar atleta con mayor cantidad de medallas |\n");
            printf("|<11> Guardar en archivo atletas de un pais         |\n");
            printf("|<12> Cargar atletas por archivo (sin medallas)     |\n");
            printf("|<13> Mostrar atletas clasificados                  |\n");
            printf("|<14> Salir                                         |\n");
            printf("----------------------------------------------------\n");
            while (!scanf("%d", &aux))
            {
                printf ("Ingrese un numero\n");
                fflush(stdin);
            }
        }
        switch(aux)
        {
        case 1:
            {
                printf("Ingrese la cantidad de atletas que desea cargar\n");
                while (!scanf("%d", &cantidad))
                {
                    printf ("Ingrese un numero\n");
                    fflush(stdin);
                }
                while(cantidad<0 || cantidad>500)
                {
                    printf("Ingrese de nuevo la cantidad a cargar\n");
                    while (!scanf("%d", &cantidad))
                    {
                        printf ("Ingrese un numero\n");
                        fflush(stdin);
                    }
                }
                cargaratleta(&d, cantidad);
            }
            break;
        case 2:
            {
                if ((isempty(d))==1)
                {
                    printf("No se puede mostrar atleta en una lista vacia\n");
                    break;
                }
                else
                {
                    printf("Ingrese el numero del atleta que desea mostrar\n");
                    while (!scanf("%d", &numero))
                    {
                        printf ("Ingrese un numero\n");
                        fflush(stdin);
                    }
                    while(numero<0 || numero>500)
                    {
                        printf("Ingrese de nuevo el numero del atleta\n");
                        while (!scanf("%d", &numero))
                        {
                            printf ("Ingrese un numero\n");
                            fflush(stdin);
                        }
                    }
                mostraratleta(d, numero);
                }
            }
            break;
        case 3:
            {
                if ((isempty(d))==1)
                {
                    printf("No se puede mostrar atleta en una lista vacia\n");
                    break;
                }
                else
                {
                    printf("Ingrese el pais que desea mostrar\n");
                    printf("<1> Argentina\n");
                    printf("<2> Brasil\n");
                    printf("<3> Chile\n");
                    printf("<4> Bolivia\n");
                    printf("<5> Mexico\n");
                    printf("<6> Colombia\n");
                    printf("<7> Venezuela\n");
                    printf("<8> Peru\n");
                    printf("<9> Uruguay\n");
                    printf("<10> Paraguay\n");
                    while (!scanf("%d", &country))
                    {
                        printf ("Ingrese un numero\n");
                        fflush(stdin);
                    }
                    while(country<0 || country>10)
                    {
                        printf("ingrese de nuevo el pais que desea mostrar\n");
                        printf("<1> Argentina\n");
                        printf("<2> Brasil\n");
                        printf("<3> Chile\n");
                        printf("<4> Bolivia\n");
                        printf("<5> Mexico\n");
                        printf("<6> Colombia\n");
                        printf("<7> Venezuela\n");
                        printf("<8> Peru\n");
                        printf("<9> Uruguay\n");
                        printf("<10> Paraguay\n");
                        while (!scanf("%d", &country))
                        {
                            printf ("Ingrese un numero\n");
                            fflush(stdin);
                        }
                    }
                mostraratletaporpais(d, country);
                }
            }
            break;
        case 4:
            {
                if ((isempty(d))==1)
                {
                    printf("No se puede modificar atleta en una lista vacia\n");
                    break;
                }
                else
                {
                    printf("Ingrese el atleta al que se le quiere modificar el puntaje\n");
                    while (!scanf("%d", &num))
                    {
                        printf ("Ingrese un numero\n");
                        fflush(stdin);
                    }
                    while(num<0 || num>500)
                    {
                        printf("Ingrese de nuevo el atleta al que se le quiere modificar el puntaje\n");
                        while (!scanf("%d", &num))
                        {
                            printf ("Ingrese un numero\n");
                            fflush(stdin);
                        }
                    }
                modificaratletapuntaje(&d, num);
                }
            }
            break;
        case 5:
            {
                if ((isempty(d))==1)
                {
                    printf("No se puede mostrar ranking en una lista vacia\n");
                    break;
                }
                else
                {
                printf("Ingrese el deporte del cual quiere mostrar el ranking\n");
                printf("<1> Natacion\n");
                printf("<2> Escalada deportiva\n");
                printf("<3> Atletismo\n");
                printf("<4> Tenis individual\n");
                printf("<5> Tenis de mesa\n");
                printf("<6> Gimnasia ritmica\n");
                printf("<7> Tiro con arco individual\n");
                printf("<8> Golf individual\n");
                printf("<9> Judo\n");
                printf("<10> Karate\n");
                while (!scanf("%d", &depor))
                {
                    printf ("Ingrese un numero\n");
                    fflush(stdin);
                }
                while(depor<0 || depor>10)
                {
                    printf("Ingrese de nuevo el deporte del cual quiere mostrar el ranking\n");
                    printf("<1> Natacion\n");
                    printf("<2> Escalada deportiva\n");
                    printf("<3> Atletismo\n");
                    printf("<4> Tenis individual\n");
                    printf("<5> Tenis de mesa\n");
                    printf("<6> Gimnasia ritmica\n");
                    printf("<7> Tiro con arco individual\n");
                    printf("<8> Golf individual\n");
                    printf("<9> Judo\n");
                    printf("<10> Karate\n");
                    while (!scanf("%d", &depor))
                    {
                        printf ("Ingrese un numero\n");
                        fflush(stdin);
                    }
                }
                mostrarranking(d, depor);
                }
            }
            break;
        case 6:
             {
                if ((isempty(d))==1)
                {
                    printf("No se puede asignar medallas en una lista vacia\n");
                    break;
                }
                else
                {
                    printf("Ingrese el numero del atleta al que quiere asignarle medallas\n");
                    while (!scanf("%d", &num2))
                    {
                        printf ("Ingrese un numero\n");
                        fflush(stdin);
                    }
                    while(num2<0 || num2>500)
                    {
                        printf("Ingrese de nuevo el numero del atleta al que quiere asignarle medalla\n");
                        while (!scanf("%d", &num2))
                        {
                            printf ("Ingrese un numero\n");
                            fflush(stdin);
                        }
                    }
                        asignarmedalla(&d, num2);
                    }
                }
            break;
        case 7:
             {
                if ((isempty(d))==1)
                {
                    printf("No se puede modificar atleta en una lista vacia\n");
                    break;
                }
                else
                {
                    printf("Ingrese el numero del atleta al que quiere modificar el estado\n");
                    while (!scanf("%d", &num3))
                    {
                        printf ("Ingrese un numero\n");
                        fflush(stdin);
                    }
                    while(num3<0 || num3>500)
                    {
                        printf("Ingrese el numero del atleta que quiere modificar el estado\n");
                        while (!scanf("%d", &num3))
                        {
                            printf ("Ingrese un numero\n");
                            fflush(stdin);
                        }
                    }
                    modificaratletaestado(&d, num3);
                }
             }
            break;
        case 8:
            {
                if ((isempty(d))==1)
                {
                    printf("No se puede eliminar en una lista vacia\n");
                    break;
                }
                else
                {
                    printf ("Seguro que desea eliminar todos los atletas cuyo estado es eliminado?\n");
                    printf ("<1> Si\n");
                    printf ("<2> No\n");
                    while (!scanf("%d", &aux2))
                    {
                        printf ("Ingrese un numero\n");
                        fflush(stdin);
                    }
                    while (aux2<1 || aux2>2)
                    {
                        printf ("Valor ingresado incorrecto\n");
                        printf ("Seguro que desea eliminar todos los atletas cuyo estado es eliminado?\n");
                        printf ("<1> Si\n");
                        printf ("<2> No\n");
                        while (!scanf("%d", &aux2))
                        {
                            printf ("Ingrese un numero\n");
                            fflush(stdin);
                        }
                    }
                    if (aux2==1)
                    eliminaratleta(&d);
                }
             }
            break;
        case 9:
             {
                if ((isempty(d))==1)
                {
                    printf("No se puede mostrar medallas en una lista vacia\n");
                    break;
                }
                else
                {
                    printf("Ingrese el tipo de medalla que desea mostrar\n");
                    printf("<1> Oro\n");
                    printf("<2> Plata\n");
                    printf("<3> Bronce\n");
                     while (!scanf("%d", &clase))
                    {
                        printf ("Ingrese un numero\n");
                        fflush(stdin);
                    }
                    while(clase<1 || clase>3)
                    {
                        printf("Ingrese de nuevo el tipo de medalla que desea mostrar\n");
                        printf("<1> Oro\n");
                        printf("<2> Plata\n");
                        printf("<3> Bronce\n");
                        while (!scanf("%d", &clase))
                        {
                            printf ("Ingrese un numero\n");
                            fflush(stdin);
                        }
                    }
                    mostrartipo(d, clase);
                }
             }
            break;
        case 10:
              {
                if ((isempty(d))==1)
                {
                    printf("No se puede mostrar medallas en una lista vacia\n");
                    break;
                }
                else
                {
                    reset (&d);
                    recursivo(d, a, 0, 0);
                }
               }
            break;
        case 11:
            {
                if ((isempty(d))==1)
                {
                    printf("No se puede almacenar desde una lista vacia\n");
                    break;
                }
                else
                {
                printf("Ingrese el pais que desea almacenar en un archivo\n");
                printf("<1> Argentina\n");
                printf("<2> Brasil\n");
                printf("<3> Chile\n");
                printf("<4> Bolivia\n");
                printf("<5> Mexico\n");
                printf("<6> Colombia\n");
                printf("<7> Venezuela\n");
                printf("<8> Peru\n");
                printf("<9> Uruguay\n");
                printf("<10> Paraguay\n");
                while (!scanf("%d", &country2))
                {
                    printf ("Ingrese un numero\n");
                    fflush(stdin);
                }
                while(country2<0 || country2>10)
                {
                    printf("ingrese de nuevo el pais que desea alamcenar en un archivo\n");
                    printf("<1> Argentina\n");
                    printf("<2> Brasil\n");
                    printf("<3> Chile\n");
                    printf("<4> Bolivia\n");
                    printf("<5> Mexico\n");
                    printf("<6> Colombia\n");
                    printf("<7> Venezuela\n");
                    printf("<8> Peru\n");
                    printf("<9> Uruguay\n");
                    printf("<10> Paraguay\n");
                   while (!scanf("%d", &country2))
                    {
                        printf ("Ingrese un numero\n");
                        fflush(stdin);
                    }
                }
                cargararchivo(d, country2);
                }
            }
            break;
        case 12:
            {
                if ((isfull(d))==1)
                {
                    printf ("No se puede realizar precarga, lista esta llena\n");
                    break;
                }
                else
                {
                    precarga(&d);
                }
            }
            break;
        case 13:
            {
                if ((isempty(d))==1)
                {
                    printf("No se puede mostrar clasificados en una lista vacia\n");
                    break;
                }
                else
                {
                mostrarclasificacion(d);
                }
            }
            break;
        case 14:
            {
                exit(14);
            }
            break;
        }
    }
    while(aux>0 && aux<14);
    return 0;
}
void cargaratleta(lista_atleta *l, int cant)
{
    int i, nacionalidad, sport, tienemedalla, c[3], clase, est;
    float puntos;
    char nya[MAXI];
    atleta d;
    for(i=0; i<3; i++)
    {
        c[i]=0;
    }
    for(i=0; i<cant; i++)
    {
        fflush(stdin);
        init(&d);
        printf("\n***********\nCREANDO EL ATLETA NUMERO %d\n", mostrarnatleta(d));
        printf("Ingrese el nombre y el apellido\n");
        scanf("%[^\n]s", nya);
        printf("Ingrese el pais\n");
        printf("<1> Argentina\n");
        printf("<2> Brasil\n");
        printf("<3> Chile\n");
        printf("<4> Bolivia\n");
        printf("<5> Mexico\n");
        printf("<6> Colombia\n");
        printf("<7> Venezuela\n");
        printf("<8> Peru\n");
        printf("<9> Uruguay\n");
        printf("<10> Paraguay\n");
        while (!scanf("%d", &nacionalidad))
        {
            printf ("Ingrese un numero\n");
            fflush(stdin);
        }
        while(nacionalidad<1 || nacionalidad>10)
        {
            printf("Ingrese de nuevo el pais\n");
            printf("<1> Argentina\n");
            printf("<2> Brasil\n");
            printf("<3> Chile\n");
            printf("<4> Bolivia\n");
            printf("<5> Mexico\n");
            printf("<6> Colombia\n");
            printf("<7> Venezuela\n");
            printf("<8> Peru\n");
            printf("<9> Uruguay\n");
            printf("<10> Paraguay\n");
            while (!scanf("%d", &nacionalidad))
            {
                printf ("Ingrese un numero\n");
                fflush(stdin);
            }
        }
        printf("Ingrese el deporte\n");
        printf("<1> Natacion\n");
        printf("<2> Escalada deportiva\n");
        printf("<3> Atletismo\n");
        printf("<4> Tenis individual\n");
        printf("<5> Tenis de mesa\n");
        printf("<6> Gimnasia ritmica\n");
        printf("<7> Tiro con arco individual\n");
        printf("<8> Golf individual\n");
        printf("<9> Judo\n");
        printf("<10> Karate\n");
        while (!scanf("%d", &sport))
        {
            printf ("Ingrese un numero\n");
            fflush(stdin);
        }
        while(sport<1 || sport>10)
        {
            printf("Ingrese de nuevo el deporte\n");
            printf("<1> Natacion\n");
            printf("<2> Escalada deportiva\n");
            printf("<3> Atletismo\n");
            printf("<4> Tenis individual\n");
            printf("<5> Tenis de mesa\n");
            printf("<6> Gimnasia ritmica\n");
            printf("<7> Tiro con arco individual\n");
            printf("<8> Golf individual\n");
            printf("<9> Judo\n");
            printf("<10> Karate\n");
            while (!scanf("%d", &sport))
            {
                printf ("Ingrese un numero\n");
                fflush(stdin);
            }
        }
        printf("Ingrese el puntaje\n");
        while (!scanf("%f", &puntos))
        {
            printf ("Ingrese un numero\n");
            fflush(stdin);
        }
        while(puntos<0)
        {
            printf("Ingrese de nuevo el puntaje\n");
            while (!scanf("%f", &puntos))
            {
            printf ("Ingrese un numero\n");
            fflush(stdin);
            }
        }
         printf("Ingrese si posee medalla\n");
        printf("<1> si posee medalla\n");
        printf("<2> no posse medalla\n");
        while (!scanf("%d", &tienemedalla))
        {
            printf ("Ingrese un numero\n");
            fflush(stdin);
        }
        while(tienemedalla<1 || tienemedalla>2)
        {
            printf("ingrese de nuevo si posee medalla\n");
            printf("<1> si posee medalla\n");
            printf("<2> no posse medalla\n");
            while (!scanf("%d", &tienemedalla))
            {
            printf ("Ingrese un numero\n");
            fflush(stdin);
            }
        }
        if(tienemedalla==1)
        {
            do
            {
                printf("Ingrese el tipo de medalla\n");
                printf("<1> Oro\n");
                printf("<2> Plata\n");
                printf("<3> Bronce\n");
                printf("<4> Salir de la carga de medallas\n");
                while (!scanf("%d", &clase))
                {
                    printf ("Ingrese un numero\n");
                    fflush(stdin);
                }
                while(clase<1 || clase>4)
                {
                    printf("Ingrese de nuevo el tipo de medalla\n");
                    printf("<1> Oro\n");
                    printf("<2> Plata\n");
                    printf("<3> Bronce\n");
                    printf("<4> Salir de la carga de medallas\n");
                    while (!scanf("%d", &clase))
                    {
                        printf ("Ingrese un numero\n");
                        fflush(stdin);
                    }
                }
                 switch(clase)
                {
                case 1:
                    {
                        printf("Ingrese la cantidad de medallas de Oro\n");
                        while (!scanf("%d", &c[0]))
                        {
                            printf ("Ingrese un numero\n");
                            fflush(stdin);
                        }
                        while ((c[0])<1)
                        {
                            printf("Cantidad ingresada incorrecta. Ingrese la cantidad de medallas de Oro\n");
                            while (!scanf("%d", &c[0]))
                            {
                                printf ("Ingrese un numero\n");
                                fflush(stdin);
                            }
                        }
                    }
                    break;
                case 2:
                    {
                        printf("Ingrese la cantidad de medallas de Plata\n");
                        while (!scanf("%d", &c[1]))
                        {
                            printf ("Ingrese un numero\n");
                            fflush(stdin);
                        }
                        while ((c[1])<1)
                        {
                            printf("Cantidad ingresada incorrecta. Ingrese la cantidad de medallas de Plata\n");
                            while (!scanf("%d", &c[1]))
                            {
                                printf ("Ingrese un numero\n");
                                fflush(stdin);
                            }
                        }
                    }
                    break;
                case 3:
                    {
                        printf("Ingrese la cantidad de medallas de Bronce\n");
                        while (!scanf("%d", &c[2]))
                        {
                            printf ("Ingrese un numero\n");
                            fflush(stdin);
                        }
                        while ((c[2])<1)
                        {
                            printf("Cantidad ingresada incorrecta. Ingrese la cantidad de medallas de Bronce\n");
                            while (!scanf("%d", &c[2]))
                            {
                                printf ("Ingrese un numero\n");
                                fflush(stdin);
                            }
                        }
                    }
                    break;
                }
            }
            while(clase>0 && clase<4);
        }
        printf("Ingrese el estado del atleta\n");
        printf("<1> Clasificado\n");
        printf("<2> Eliminado\n");
        while (!scanf("%d", &est))
        {
            printf ("Ingrese un numero\n");
            fflush(stdin);
        }
        while(est<1 || est>2)
        {
            printf("Ingrese de nuevo el estado del atleta\n");
            printf("<1> Clasificado\n");
            printf("<2> Eliminado\n");
            while (!scanf("%d", &est))
            {
                printf ("Ingrese un numero\n");
                fflush(stdin);
            }
        }
        cargarnombreyapellido(&d, nya);
        cargarpais(&d, nacionalidad);
        cargardeporte(&d, sport);
        cargarposeemedalla(&d, tienemedalla);
        cargarpuntaje(&d, puntos);
        cargarmedalla(&d, c);
        cargarestado(&d, est);
        insertar(&(*l), d);
        fowards(&(*l));
        printf("ATLETA CARGADO EXITOSAMENTE\n");
    }
}
atleta buscaratleta(lista_atleta *l, int n)
{
    atleta a;
    reset(&(*l));
    while(isOos(*l)==0)
    {
        a=copiar(*l);
        if(n==mostrarnatleta(a))
        {
            return a;
            fowards(&(*l));
        }
        else
        {
            fowards(&(*l));
        }
    }
}
void mostraratleta(lista_atleta l, int n)
{
    atleta a;
    a=buscaratleta(&l, n);
    if(mostrarnatleta(a)==n)
    {
        printf("El numero de atleta es: %d\n", mostrarnatleta(a));
        printf("El nombre y apellido es: %s\n", mostrarnombreyapellido(a));
        switch(mostrarpais(a))
         {
            case 1:
            {
                printf("El atleta es de Argentina\n");
            }
            break;
            case 2:
            {
                printf("El atleta es de Brasil\n");
            }
            break;
            case 3:
            {
                printf("El atleta es de Chile\n");
            }
            break;
            case 4:
            {
                printf("El atleta es de Bolivia\n");
            }
            break;
            case 5:
            {
                printf("El atleta es de Mexico\n");
            }
            break;
            case 6:
            {
                printf("El atleta es de Colombia\n");
            }
            break;
            case 7:
            {
                printf("El atleta es de Venezuela\n");
            }
            break;
            case 8:
            {
                printf("El atleta es de Peru\n");
            }
            break;
            case 9:
            {
                printf("El atleta es de Uruguay\n");
            }
            break;
            case 10:
            {
                printf("El atleta es de Paraguay\n");
            }
            break;
        }
        switch(mostrardeporte(a))
        {
        case 1:
        {
            printf("El deporte es Natacion\n");
        }
        break;
        case 2:
            {
                printf("El deporte es Escalada deportiva\n");
            }
            break;
        case 3:
        {
            printf("El deporte es Atletismo\n");
        }
        break;
        case 4:
        {
            printf("El deporte es Tenis individual\n");
        }
        break;
        case 5:
        {
            printf("El deporte es Tenis de mesa\n");
        }
        break;
        case 6:
        {
            printf("El deporte es Gimnasia ritmica\n");
        }
        break;
        case 7:
        {
            printf("El deporte es Tiro con arco individual\n");
        }
        break;
        case 8:
        {
            printf("El deporte es Golf individual\n");
        }
        break;
        case 9:
        {
            printf("El deporte es Judo\n");
        }
        break;
        case 10:
        {
            printf("El deporte es Karate\n");
        }
        break;
    }
        printf("El puntaje es: %f\n", mostrarpuntaje(a));
        if(mostrarposeemedallas(a)==1)
        {
            printf("Posee medalla\n");
            printf("La cantidad de medalla de oro es: %d\n", mostrarmedalla(a).cantidad[0]);
            printf("La cantidad de medalla de plata es: %d\n", mostrarmedalla(a).cantidad[1]);
            printf("La cantidad de medalla de bronce es: %d\n", mostrarmedalla(a).cantidad[2]);

        }
        else
        {
            printf("No posee medalla\n");
        }
        if(mostrarestado(a)==1)
        {
            printf("El deportista esta clasificado\n");
        }
        else
        {
            printf("El deportista esta eliminado\n");
        }
        printf("ATLETA MOSTRADO EXITOSAMENTE\n");
    }
    else
    {
        printf("No se encontro el atleta\n");
    }
}
void mostraratletaporpais(lista_atleta l, int p)
{
    atleta a;
    reset(&l);
    switch(p)
        {
            case 1:
            {
                printf("Mostrando los atletas de Argentina\n");
            }
            break;
            case 2:
            {
                printf("Mostrando los atletas de Brasil\n");
            }
            break;
            case 3:
            {
                printf("Mostrando los atletas de Chile\n");
            }
            break;
            case 4:
            {
                printf("Mostrando los atletas de Bolivia\n");
            }
            break;
            case 5:
            {
                printf("Mostrando los atletas de Mexico\n");
            }
            break;
            case 6:
            {
                printf("Mostrando los atletas de Colombia\n");
            }
            break;
            case 7:
            {
                printf("Mostrando los atletas de Venezuela\n");
            }
            break;
            case 8:
            {
                printf("Mostrando los atletas de Peru\n");
            }
            break;
            case 9:
            {
                printf("Mostrando los atletas de Uruguay\n");
            }
            break;
            case 10:
            {
                printf("Mostrando los atletas de Paraguay\n");
            }
            break;
        }
    while(isOos(l)==0)
    {
        a=copiar(l);
        if(mostrarpais(a)==p)
        {
            mostraratleta(l, mostrarnatleta(a));
            fowards(&l);
        }
        else
        {
            fowards(&l);
        }
    }
}
void modificaratletapuntaje(lista_atleta *l, int n)
{
    atleta d;
    float point;
    reset(&(*l));
    d=buscaratleta(&(*l), n);
    printf("Ingrese nuevo puntaje\n");
    while (!scanf("%f", &point))
        {
            printf ("Ingrese un numero\n");
            fflush(stdin);
        }
    while(point<0)
    {
        printf("No se puede ingresar puntaje negativo. Ingrese nuevo puntaje\n");
        while (!scanf("%f", &point))
        {
            printf ("Ingrese un numero\n");
            fflush(stdin);
        }
    }
    modificarpuntaje(&d, point);
    supress(&(*l));
    insertar(&(*l), d);
    printf ("Puntaje modificado exitosamente\n");
}
void mostrarranking(lista_atleta l, int sport)
{
    atleta a;
    int i=0;
    int j, k, aux_n_atl;
    float aux_punt;
    float punt [MAXI];
    int numatl [MAXI];
    punt[0]=-1;//servira para controlar si se cargo algo o el arreglo quedo sin tocar
    reset(&l);
    while (isOos(l)==0)
    {
        a=copiar(l);
        if (mostrardeporte(a)==sport)
        {
            punt[i]=mostrarpuntaje(a);
            numatl[i]=mostrarnatleta(a);
            fowards(&l);
            i++;
        }
        else
        {
            fowards(&l);
        }
    }//hasta aca llene dos arreglos, uno con puntajes y otro con los numeros de atleta
   if ((punt[0])==-1)
        printf ("No hay ranking disponible para deporte solicitado\n");
    else
    {
        for (j=0; j<i; j++)
        {
            for (k=j+1; k<i; k++)
            {
                if (punt[j]<punt[k])
                {
                    aux_punt=punt[j];
                    aux_n_atl=numatl[j];
                    punt[j]=punt[k];
                    numatl[j]=numatl[k];
                    punt[k]=aux_punt;
                    numatl[k]=aux_punt;
                }
            }
        }
    printf("numero de atleta | nombre de atleta | puntaje\n");
    printf("______________________________________________\n");
    for (j=0; j<i; j++)
    {
        printf("        %d       |         %s       |     %f  \n", numatl[j],mostrarnombreyapellido(buscaratleta(&l, numatl[j])), punt[j]);
    }
   }
}
void asignarmedalla(lista_atleta *l, int n)
{
    atleta a;
    int clase, med[3]; med[1]=0; med[2]=0; med[3]=0;
    reset(&(*l));
    a=buscaratleta(&(*l), n);
    if(mostrarnatleta(a)==n)
    {
        do
        {
            printf("Ingrese el tipo de medalla\n");
            printf("<1> Oro\n");
            printf("<2> Plata\n");
            printf("<3> Bronce\n");
            printf("<4> Salir del modificar medallas\n");
            while (!scanf("%d", &clase))
            {
                printf ("Ingrese un numero\n");
                fflush(stdin);
            }
            while(clase<1 || clase >4)
            {
                printf("Ingrese de nuevo el tipo de medalla\n");
                printf("<1> Oro\n");
                printf("<2> Plata\n");
                printf("<3> Bronce\n");
                printf("<4> Salir del modificar medallas\n");
                while (!scanf("%d", &clase))
                {
                    printf ("Ingrese un numero\n");
                    fflush(stdin);
                }
            }
            switch(clase)
            {
            case 1:
                {
                    printf("Ingrese la cantidad de medallas de oro que quiere asignar\n");
                    while (!scanf("%d", &med[0]))
                    {
                        printf ("Ingrese un numero\n");
                        fflush(stdin);
                    }
                    while(med[0]<0)
                    {
                        printf("ingrese de nuevo la cantidad de medallas de oro que quiere asignar\n");
                        while (!scanf("%d", &med[0]))
                        {
                            printf ("Ingrese un numero\n");
                            fflush(stdin);
                        }
                    }
                }
                break;
            case 2:
                {
                    printf("Ingrese la cantidad de medallas de plata que quiere asignar\n");
                    while (!scanf("%d", &med[1]))
                    {
                        printf ("Ingrese un numero\n");
                        fflush(stdin);
                    }
                    while(med[1]<0)
                    {
                        printf("Ingrese de nuevo la cantidad de medallas de plata que quiere asignar\n");
                        while (!scanf("%d", &med[1]))
                        {
                            printf ("Ingrese un numero\n");
                            fflush(stdin);
                        }
                    }
                }
                break;
            case 3:
                {
                    printf("Ingrese la cantidad de medallas de bronce que quiere asignar\n");
                    while (!scanf("%d", &med[2]))
                    {
                        printf ("Ingrese un numero\n");
                        fflush(stdin);
                    }
                    while(med[2]<0)
                    {
                        printf("Ingrese de nuevo la cantidad de medallas de bronce que quiere asignar\n");
                        while (!scanf("%d", &med[2]))
                        {
                            printf ("Ingrese un numero\n");
                            fflush(stdin);
                        }
                    }
                }
                    break;
                }
            }
         while(clase>1 && clase<4);
         modificarposeemedalla(&a, 1);
         modificarmedallas(&a, med);
         supress(&(*l));
         insertar(&(*l), a);
         printf("MEDALLAS ASIGNADAS EXITOSAMENTE\n");
    }
}
void modificaratletaestado(lista_atleta *l, int n)
{
    int est;
    atleta a;
    a=buscaratleta(&(*l), n);
    printf("Ingrese el nuevo estado del atleta\n");
    printf("<1> clasificado\n");
    printf("<2> eliminado\n");
    while (!scanf("%d", &est))
    {
        printf ("Ingrese un numero\n");
        fflush(stdin);
    }
    while(est<0 || est>2)
    {
        printf("Ingrese de nuevo el estado del atleta\n");
        while (!scanf("%d", &est))
        {
            printf ("Ingrese un numero\n");
            fflush(stdin);
        }
    }
    modificarestado(&a, est);
    supress(&(*l));
    insertar(&(*l), a);
    printf ("Estado del atleta modificado exitosamente\n");
}
void eliminaratleta(lista_atleta *l)
{
    atleta d;
    reset(&(*l));
    while(isOos(*l)==0)
    {
        d=copiar(*l);
        if(mostrarestado(d)==2)
        {
            supress(&(*l));
            fowards(&(*l));
        }
        else
        {
            fowards (&(*l));
        }
    }
    printf ("Eliminacion exitosa\n");
}
void mostrartipo(lista_atleta l, int color)
{
    atleta d;
    reset (&l);
    while(isOos(l)==0)
    {
        d=copiar(l);
        if(color==1)
        {
            printf("El atleta: %d tiene %d medallas de oro\n",mostrarnatleta(d), mostrarmedalla(d).cantidad[0]);
            fowards(&l);
        }
        else
        {
            if(color==2)
            {
                printf("El atleta: %d tiene %d medallas de plata\n",mostrarnatleta(d), mostrarmedalla(d).cantidad[1]);
                fowards(&l);
            }
            else
            {
                printf("El atleta: %d tiene %d medallas de bronce\n", mostrarnatleta(d), mostrarmedalla(d).cantidad[2]);
                fowards(&l);
            }
        }
    }
}
void recursivo (lista_atleta l, atleta a, int aux1, int aux2)
{
	if (isOos(l)==1)
	{
		mostraratleta (l, aux2);
	}
	else
	{
		a=copiar(l);
		if (((mostrarmedalla(a).cantidad[0])+(mostrarmedalla(a).cantidad[1])+(mostrarmedalla(a).cantidad[2]))>aux1)
		{
			aux1=(mostrarmedalla(a).cantidad[0])+(mostrarmedalla(a).cantidad[1])+(mostrarmedalla(a).cantidad[2]);
			aux2=mostrarnatleta(a);
			fowards (&l);
			recursivo(l, a, aux1, aux2);
		}
		else
		{
		fowards (&l);
		recursivo(l, a, aux1, aux2);
		}
	}
}
void cargararchivo(lista_atleta d, int nacion)
{
    atleta a;
    FILE *archivo;
    reset(&d);
    archivo=fopen("atletapais.txt", "a+");
    if(archivo==NULL)
    {
        printf("Error, el archivo no existe");
        printf("<1> Salir");
        exit(1);
    }
    else
    {
        while(isOos(d)==0)
        {
            a=copiar(d);
            if(mostrarpais(a)==nacion)
            {
                fprintf(archivo, "%d\n", mostrarnatleta(a));
                fprintf(archivo, "%s\n", mostrarnombreyapellido(a));
                fprintf(archivo, "%d\n", mostrarpais(a));
                fprintf(archivo, "%d\n", mostrardeporte(a));
                fprintf(archivo, "%f\n", mostrarpuntaje(a));
                fprintf(archivo, "%d\n", mostrarposeemedallas(a));
                fprintf(archivo, "%d\n%d\n%d\n", mostrarmedalla(a).cantidad[0],mostrarmedalla(a).cantidad[1], mostrarmedalla(a).cantidad[2]);
                fprintf(archivo, "%d\n", mostrarestado(a));
                fowards(&d);
            }
            else
            {
                fowards(&d);
            }
        }
    }
}
void precarga(lista_atleta *l)
{
    int nacion, sport, est, posee;
    char nya[MAXI];
    float point;
    atleta d;
    FILE *archivo;
    archivo=fopen("precarga.txt", "r");
    if(archivo==NULL)
    {
        printf("Error, el archivo no existe\n");
        printf("<1> salir\n");
        exit(1);
    }
    else
    {
        rewind(archivo);
        while(feof(archivo)==0)
        {
            init(&d);
            fscanf(archivo, "%s", nya);
            fscanf(archivo, "%d", &nacion);
            fscanf(archivo, "%d", &sport);
            fscanf(archivo, "%f", &point);
            fscanf(archivo, "%d", &posee);
            fscanf(archivo, "%d", &est);
            cargarnombreyapellido(&d, nya);
            cargarpais(&d, nacion);
            cargardeporte(&d, sport);
            cargarpuntaje(&d, point);
            cargarposeemedalla(&d, posee);
            cargarestado(&d, est);
            insertar((&(*l)), d);
        }
        printf("cargado exitosamente\n");
    }
    fclose(archivo);
}
void mostrarclasificacion(lista_atleta l)
{
    atleta d;
    reset(&l);
    while(isOos(l)==0)
    {
        d=copiar(l);
        if(mostrarestado(d)==1)
        {
            mostraratleta(l, (mostrarnatleta(d)));
            fowards(&l);
        }
        else
        {
            fowards(&l);
        }
    }
}
