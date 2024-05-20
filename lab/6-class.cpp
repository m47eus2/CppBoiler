#include <iostream>
#include <vector>

using namespace std;

//Przeciążenie operatorów
class Point
{
private:
    int x;
    int y;

public:
    Point (){};
    Point(int a, int b) : x(a), y(b)
    {}

    Point operator+(Point p)
    {
        return Point(x+p.x, y+p.y);
    }

    Point operator-(Point p)
    {
        return Point(x-p.x, y-p.y);
    }

    friend ostream& operator<< (ostream &os, Point p)
    {
        os << "[" << p.x <<"," << p.y << "]";
        return os;
    }   

    friend istream& operator>> (istream &is, Point &p)
    {
        cout<<"Podaj x: ";
        is >> p.x;

        cout<<"Podaj y: ";
        is >> p.y;
    }

    friend Point operator* (Point p1, Point p2);
};

//Przeciążenie opratora poza klasą 
Point operator* (Point p1, Point p2)
{
    return Point(p1.x*p2.x, p1.y*p2.y);
}


//Funckje szablonowe

template <typename T>

T addingWithTemplate(T a, T b)
{
    return a+b;
}

template <typename T>

vector<T> createVector(int n)
{
    return vector<T>(n);
}

//Klasa z metodą statyczną

class drone
{
public:
    float size;
    float speed;

    static void fly()
    {
        cout << "Zium" << endl;
    }
};

// Funckje wskaźnikowe

int sum(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int mult(int a, int b)
{
    return a*b;
}

int main()
{
    /*
        Metody statyczne
        do uruchomienia metody nie jest potrzebny objekt klasy
    */

    drone::fly();

    /*
        Wskaźnik do funkcji
    */

    //Utworzenie wskaźnika do funkcji przyjmującej 2 inty
    int (*pointer)(int, int);

    pointer = sum;
    cout << pointer(5,5) << endl;

    pointer = sub;
    cout << pointer(5,5) << endl;

    pointer = mult;
    cout << pointer(5,5) << endl;

    pointer = [](int a, int b){return a/b;};
    cout << pointer(5,5) << endl;
    cout<<endl;
    
    //Funkcje szablonowe
    cout << addingWithTemplate(5,4) << endl;
    cout << addingWithTemplate(5.6, 1.1) << endl << endl;

    vector<int> v1 = createVector<int>(3);

    vector<string> v2 = createVector<string>(3);

    //Przeciążenie operatorów
    Point p1(5,5);
    Point p2(2,2);

    cout<<p1<<endl;
    cout<<p2<<endl<<endl;

    Point p4 = p1+p2;
    cout << p4 << endl;

    Point p5 = p1-p2;
    cout<< p5 << endl;

    Point p6 = p1*p2;
    cout << p6 << endl<<endl;

    Point p7;
    cin>>p7;
    cout<<p7<<endl;

    return 0;
}