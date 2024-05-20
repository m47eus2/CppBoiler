#include <iostream>

using namespace std;

class Event
{
private:
    int day, month, year;
    int hour, minute;
    string name;

public:
    Event(string n="brak", int d=1, int m=1, int y=2024, int h=12 ,int mins=0)
    {
        name = n;
        day = d;
        month = m;
        year = y;
        hour = h;
        minute = mins;
    }

    ~Event()
    {}

    void load()
    {
        cout<<"Nazwa wydarzenia: ";
        cin>>name;
        cout<<"Dzien: ";
        cin>>day;
        cout<<"Miesiac: ";
        cin>>month;
        cout<<"Rok: ";
        cin>>year;
        cout<<"Godzina";
        cin>>hour;
        cout<<"Minuta";
        cin>>minute;
    }

    void show()
    {
        cout<<endl<<name<<" "<<day<<"."<<month<<"."<<year<<" "<<hour<<":"<<minute<<endl;
    }
};

int main()
{
    Event w1("Apolalipsa Zombie", 6, 8, 2045, 8, 15);
    w1.show();

    Event w2;
    w2.show();
    return 0;
}