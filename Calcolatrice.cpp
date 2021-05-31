/*
    Nome del progetto:Calcolatrice
    Autore:Pasquale Fetto
    Data:15/04/2021
*/
#include <iostream>
#include <math.h>
#include "Calcolatrice.h"

using namespace std;

Calcolatrice::Calcolatrice(int a,int b,float c)
{
   x=a;
   y=b;
   z=c;
}

Calcolatrice::~Calcolatrice()
{
    cout << "Fine operazione" <<endl;
    cout << endl;
}

int Calcolatrice::somma()
{
    return x+y;
}

int Calcolatrice::differenza()
{
    return x-y;
}


int Calcolatrice::prodotto()
{
    return x*y;
}

int Calcolatrice::quoziente()
{
    return x/y;
}

float Calcolatrice::radice()
{
    return sqrt(z);
}
