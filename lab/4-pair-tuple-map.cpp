#include <iostream>
#include <map>

using namespace std;

int main()
{
    
    /*
        pair -> wzorzec struktury o druch polach .first, .second
    */

    //Tworzenie
    pair<string, double> exchange;
    exchange = {"EUR", 4.5};

    pair<string, double> exchange2("USD", 4.10);

    //Odwołanie
    cout << exchange.first << " " << exchange.second << endl;

    /*
        map
        Przechowuje pare jako unikalny klucz i wartość
        map<key_type, value_type> name;
    */

    //Tworzenie
    map<string, int> word_rate;

    //Modyfikacja
    word_rate.emplace("the", 1); // Dodaje słowo the i przyporzątkowuje mu 1
    
    word_rate["the"] = 2; // Nadpisuje wartość słowa "the", jeśli klucz nie istnieje zostanie utworzony w wartością domyślną

    cout << word_rate["the"] << endl; // Odczyt wartości dla klucza "the"
    cout << word_rate["and"] << endl; // Nie istnieje klucz, element zostanie utworzony z wartością domyślną

    //Odczyt bez dodawania klucza w przypadku nie znalezienia go
    
    string toFind = "and";
    auto search = word_rate.find(toFind);
    if(search != word_rate.end())
        cout << word_rate[toFind] << endl;
    else
        cout << "Element nieznaleziony" << endl;

    //Iterowanie przez mapę -> mapa jest defaultowo posortowana roznąco (według wartości klucza)

    //Za pomocą iteratorów
    for(auto it = word_rate.begin(); it != word_rate.end(); it++)
        cout << it->first << " " << it->second << endl;
    cout<<endl;

    // Pętla for-range
    for(auto &i : word_rate)
        cout << i.first << " " << i.second << endl;

    return 0;
}