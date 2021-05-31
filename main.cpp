/*
    Nome del progetto:Calcolatrice
    Autore:Pasquale Fetto
    Data:15/04/2021
*/

#include <iostream>
#include "Calcolatrice.h"
#include <math.h>

using namespace std;

int main()
{
    int x,y,z;
    float c;
    cout << "Calcolatrice Fettopoli semplice." << endl;
    do{
    cout << "Inserisci un numero compreso tra 1 e 4 per scegliere la tua operazione.(0 per uscire)" << endl;
    cout <<"1)Somma fra interi" << endl;
    cout <<"2)Differenza fra interi" << endl;
    cout <<"3)Prodotto fra interi" << endl;
    cout <<"4)Quoziente fra interi" << endl;
    cout <<"5)Radice Quadrata" << endl;
    cin >> z;
    if(z==1)
    {
        cout <<"Hai scelto la somma fra interi!!!" << endl;
        cout <<"Inserisci due numeri da sommare." <<endl;
        cin >> x >> y;
    }
    else if (z==2)
    {
        cout <<"Hai scelto la differenza!!!" << endl;
        cout <<"Inserisci due numeri da sottrarre." <<endl;
        cin >> x >> y;
    }
    else if (z==3)
    {
        cout <<"Hai scelto il prodotto!!!" << endl;
        cout <<"Inserisci due numeri da moltiplicare." <<endl;
        cin >> x >> y;
    }
    else if (z==4)
    {
        cout <<"Hai scelto il quoziente!!!" << endl;
        cout <<"Inserisci due numeri da dividere." <<endl;
        cin >> x >> y;
    }
    else if(z==5)
    {
        cout <<"Hai scelto la radice quadrata!!!" << endl;
        cout <<"Inserisci il numero di cui calcolare la radice." <<endl;
        cin >> c;
    }
    Calcolatrice calcolatrice1(x,y,c);
    switch(z)
    {
        case 0:
        cout <<"Arrivederci!!!!" << endl;
        exit(0);
        case 1:
        cout <<"Il risultato della somma e':" <<calcolatrice1.somma() <<"." <<endl;
        break;
        case 2:
        cout <<"Il risultato della sottrazione e':" <<calcolatrice1.differenza() <<"." <<endl;
        break;
        case 3:
        cout <<"Il risultato del prodotto e':" <<calcolatrice1.prodotto() <<"." <<endl;
        break;
        case 4:
        cout <<"Il risultato del quoziente e':" <<calcolatrice1.quoziente() <<"." <<endl;
        break;
        case 5:
        cout <<"La radice quadrata di " << c <<" e'" <<calcolatrice1.radice() <<"." <<endl;
        break;
    }
    }while(z!=0);
    return 0;
}
