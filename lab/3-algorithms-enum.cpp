#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Drone
{
public:
    string name;
    float speed;
    float flyTime;
    float inchSize;

    Drone(string name_arg, float speed_arg, float flyTime_arg, float inchSize_arg) : 
    name(name_arg), speed(speed_arg), flyTime(flyTime_arg), inchSize(inchSize_arg)
    {}
};

enum Color
{
    White,
    Black,
    Red,
    Green,
    Blue
};

int main()
{
    /*
        enum
    */
    Color color = Color::White;
    switch(color)
    {
        case Color::White:
            cout<<"Color is white"<<endl;
            break;
        case Color::Black:
            cout<<"Color is Black"<<endl;
    }

    /*
        lambda
        [capture](arguments){function}
    */

    //Wyrażenie lambda przypisane do zmiennej
    auto add = [](int a, int b){return a+b;};
    cout << add(3,4) << endl;

    //Wyrażenie lambda z przechwyceniem przypisane do zmiennej
    int m = 5;
    auto mult = [m](int a){return a*m;};
    cout << mult(3) << endl;

    /*
        algorithm
    */

    vector<Drone> drones;

    drones.push_back(Drone("phantom3",60,40,8));
    drones.push_back(Drone("phantom4",90,45,8));
    drones.push_back(Drone("mini3",70,50,4));
    drones.push_back(Drone("nazgul",180,8,5));
    drones.push_back(Drone("cinelog",120,5,3.5));
    drones.push_back(Drone("chimera7",180,20,7));
    drones.push_back(Drone("helion10",170,30,10));

    //all_of -> czy wszystkie elementy spełniają warunek
    cout << all_of(drones.begin(), drones.end(), [](Drone drone){return drone.inchSize > 3;}) << endl;

    //any_of -> czy jakikolwiek element spełnia warunek
    cout << any_of(drones.begin(), drones.end(), [](Drone drone){return drone.speed > 170;}) << endl;

    //none_of -> czy żaden obiekt nie spełnia warunku
    cout << none_of(drones.begin(), drones.end(), [](Drone drone){return drone.speed > 190;}) << endl;

    //count_if -> zlicz jeżeli obiekt spełnia warunek
    cout << count_if(drones.begin(), drones.end(), [](Drone drone){return drone.inchSize > 5;}) << endl;

    //erase + remove_if -> usuwa wszystkie elementy nie spełniające warunku, remove_if zwraca iterator pierwszego elementu do usunięcia
    drones.erase(remove_if(drones.begin(), drones.end(), [](Drone drone){return drone.speed < 100;}), drones.end());

    for(auto &i : drones)
        cout << i.name << endl;
    
    return 0;
}