#include <iostream>
#include "przyjaciele.h"

using namespace std;

void sedzia(Punkt &pkt, Prostokat &p)
{
    if((pkt.x >= p.x)&&(pkt.x <= pkt.x + p.szerokosc)&&(pkt.y >= p.y)&&(pkt.y <= p.y+p.wysokosc))
        cout<<"Punkt "<<pkt.nazwa<<" nalezy do prostokata "<<p.nazwa<<endl;
    else
        cout<<"Punkt "<<pkt.nazwa<<" nie nalezy do prostokata "<<p.nazwa<<endl;
}

int main()
{
    Punkt pkt1("A", 3, 17);

    Prostokat p1("Prostokat", 0, 0, 6, 4);

    sedzia(pkt1, p1);

    return 0;
}