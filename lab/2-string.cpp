#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    string text = "Hello World";

    /*
        string::find()
        Zwraca wartość size_t z indexem pierwszego wystąpienia znaku lub ciągu znaków,
        przyjmuje też index od którego ma rozpocząć wyszukiwanie. Po niezalezieniu znaku w ciągu
        zwraca string::npos
    */

    size_t posO = text.find('o'); //Zwraca index pierwszego znalezionego znaku 'o'
    cout << posO << endl;

    size_t posNextO = text.find('o', 5); //Zaczyna szukać od pozycji 5
    cout << posNextO << endl;

    size_t posll = text.find("ll"); //Zwraca index pierwszego znalezionego ciągu "ll"
    cout << posll << endl;

    //Wyszukiwanie wszytkich wystąpień
    size_t position = 0;
    while((position = text.find('o', position+1)) != string::npos) //Tak długo jak znaleziony index jest róźny od string::npos
    {
        cout<<"Znaleziono na pozycji "<<position<<endl; //Wyświetlaj index trafienia
    }

    /*
        string::substr()
        Zwraca fragment ciągu z podanym początkowym indexem i długością ciągu
    */

   string text2 = text.substr(6); //Od pozycji 6 do końca
   cout << text2 << endl;

   string text3 = text.substr(6, 3); //Od pozycji 6, 3 znaki
   cout<< text3 << endl;

   size_t posr = text.find('r');
   string text4 = text.substr(posr); //Od r do końca
   cout << text4 << endl;

   /*
        Wczytywanie i zapis z pliku csv
   */

    fstream file;
    file.open("text.txt",ios::in);

    //cout << file.good() << endl; //1 gdy plik został wczytany

    // typy ios:
    // ios::in
    // ios::out
    // ios::out | ios::app

    string line;
    getline(file, line); //Ignorujemu pierwszą linie

    while(getline(file, line)) //Wczytuje linie dopóki istnieją
    {
        //cout<<line<<endl; //Wyświetl linie
        stringstream ss(line); // Strumień, którego źródłem jest linia
        string str;
    
        getline(ss, str, ','); //Przypisuje do str ciąg do znaku ','
        cout<<str;

        getline(ss, str, ','); //Przypisuje do str kolejny ciąg do znaku ','
        cout<<str<<endl;
    }
    
    return 0;
}