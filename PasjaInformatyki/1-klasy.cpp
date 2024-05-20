#include <iostream>

using namespace std;

class Zwierze
{
public:

    string gatunek;
    string imie;
    int wiek;

    void dodajZwierze()
    {
        cout<<"Dodawanie nowego zwierzęcia"<<endl;
        cout<<"Podaj gatunek: ";
        cin>>this->gatunek;
        cout<<"Podaj imie: ";
        cin>>this->imie;
        cout<<"Podaj wiek: ";
        cin>>this->wiek;
    }

    void dajGlos()
    {
        if(this->gatunek == "kot") cout<<this->imie<<" "<<this->wiek<<" lat kot"<<endl;
        else if(this->gatunek == "koza") cout<<this->imie<<" "<<this->wiek<<" lat koza"<<endl;
        else if(this->gatunek == "krowa") cout<<this->imie<<" "<<this->wiek<<" lat krowa"<<endl;
        else cout<<"Nieznany gatunek"<<endl;
    }
};

class Samochod
{
public:
    string marka;
    string model;
    int rocznik;
    int przebieg;

    void wczytaj()
    {
        cout<<"Dodawanie samochodu"<<endl;
        cout<<"Podaj markę: ";
        cin>>this->marka;
        cout<<"Podaj model: ";
        cin>>this->model;
        cout<<"Podaj rocznik: ";
        cin>>this->rocznik;
        cout<<"Podaj przebieg: ";
        cin>>this->przebieg;
    }

    void wypisz()
    {
        cout<<this->marka<<" "<<this->model<<" "<<this->rocznik<<" "<<this->przebieg<<endl;
    }
};

int main()
{
    /*
    Zwierze z1;

    z1.dodajZwierze();
    z1.dajGlos();
    */

   Samochod s1;
   s1.wczytaj();
   s1.wypisz();

    cout<<"Hello World!"<<endl;
    return 0;
}