#include <iostream>

using namespace std;

class Prostokat;

class Punkt
{
private:
    string nazwa;
    float x,y;

public:
    Punkt(string="a", float=0.0, float=0.0);
    void wczytaj();

    friend void sedzia (Punkt &pkt, Prostokat &p);
};

class Prostokat
{
private:
    string nazwa;
    float x,y,szerokosc, wysokosc;

public:
    Prostokat(string="brak", float=0, float=0, float=1, float=1);
    void wczytaj();

    friend void sedzia (Punkt &pkt, Prostokat &p);
};