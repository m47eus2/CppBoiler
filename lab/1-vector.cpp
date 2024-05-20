#include <iostream>
#include <vector>

using namespace std;

//Funkcja nie modyfikująca wektora przyjmuje referencje z const aby uniknąc kopiowania
void display(const vector<int> &v)
{
    for(auto &i : v)
        cout<<i<<" ";
    cout<<endl;
}

//Funkcja modyfikująca wektor musi przyjmować referencje
void add(vector <int> &v, int x)
{
    v.emplace_back(x);
}

int main()
{
    /*
        Tworzenie wektora
    */

    vector<int> v1; //Pusty wektor
    vector<int> v2(5); //5 elementowy wektor o domyślnych wartościach
    vector<int> v3(10 ,5); //10 elementowy wektor o wartościach 5

    vector<int> v4 = {1,2,3,4,5}; //Lista inicjalizyjna
    
    vector<vector<int>> matrix; //Lista dwuwymiarowa

    /*
        Wyświetlenie wektora
    */

    //Przejście przez wektor
    for(int i=0; i < v4.size() ; i++)
    {
        cout<<v4[i]<<" ";
    }
    cout<<endl;

    //Pętla typu range-based
    for(auto &i : v4)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    //Pętla wykorzystująca iterator
    for(vector<int>::iterator it = v4.begin(); it != v4.end(); it++)
    {
        cout<< *it <<" ";
    }
    cout<<endl;

    /*
        Modyfikacja wektora
    */
    
    v4.emplace_back(6); //Dodanie wartości na końcu wektora
    v4.resize(10); //Zmienia rozmiar wektora na 10
    v2.clear(); //Usuwa wszystkie elementy

    /*
        Kopiowanie wektora
    */

   vector<int> v5 = v4; //Kopia wektora

   /*
        Dostęp do wektora z funkcji
   */

    //Dostęp read only
    display(v4);

    //Modyfikacja w funkcji
    add(v4, 11);

    //Wyświetlenie
    display(v4);

    return 0;
}