#include <iostream>

using namespace std;

class Punkt
{
    float x,y;
    string nazwa;

public:
    Punkt(string n="S", float a=0, float b=0)
    {
        nazwa = n;
        x = a;
        y = b;
    }
    void wyswietl()
    {
        cout<<"Punkt "<<nazwa<<"("<<x<<", "<<y<<")"<<endl;
    }
};

class Kolo :public Punkt
{
protected:
    float r;
    string nazwa;

public:
    void wyswietl()
    {
        cout<<"Kolo "<<nazwa<<endl;
        Punkt::wyswietl();
        cout<<"Promien: "<<r<<endl;
        cout<<"Pole kola: "<<3.1415*r*r<<endl;
    }
    Kolo(string nk="Kolko", string np="S", float a=0, float b=0, float pr=1) : Punkt(np, a, b)
    {
        nazwa = nk;
        r = pr;
    }
};

class Kula : public Kolo
{
    string nazwa;

public:
    Kula(string nku="Kulka", string nk="Kolko", string np="S", float a=0, float b=0, float pr=1) : Kolo(nk, np, a, b, pr)
    {
        nazwa = nku;
    }
    void wyswietl()
    {
        cout<<"Kula "<<nazwa<<endl;
        Kolo::wyswietl();
        cout<<"Objetosc kuli "<<(4.0/3.0)*3.1415*r*r*r<<endl;
    }
};

int main()
{
    Kolo k1;
    k1.wyswietl();

    Kula ku;
    ku.wyswietl();
    
    return 0;
}