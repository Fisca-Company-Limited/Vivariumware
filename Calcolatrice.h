/*
    Nome del progetto:Calcolatrice
    Autore:Pasquale Fetto
    Data:15/04/2021
*/
#ifndef CALCOLATRICE_H_INCLUDED
#define CALCOLATRICE_H_INCLUDED

using namespace std;

//DICHIARAZIONE DELLA CLASSE
class Calcolatrice
{
    public:
    int x;
    int y;
    float z;
    Calcolatrice(int,int,float);
    ~Calcolatrice();
    int somma();
    int differenza();
    int prodotto();
    int quoziente();
    float radice();
};

#endif // CALCOLATRICE_H_INCLUDED
