#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    
    /*
    pliki
    */

    //Wczytanie wyraz po wyrazie
    fstream file ("inwokacja.txt", ios::in);
    vector<string> words;
    while(!file.eof())
    {
        string word;
        file >> word;
        cout << word << endl;
    }
    cout<<endl;
    file.close();

    //Wczytanie całego pliku
    fstream file2 ("inwokacja.txt", ios::in);
    stringstream ss;
    ss << file2.rdbuf();
    string fullText = ss.str();
    cout<<fullText<<endl<<endl;
    file2.close();

    //Wczytanie linia po lini
    fstream file3 ("inwokacja.txt", ios::in);
    string line;
    while(getline(file3, line))
    {
        cout << line << endl;
    }
    cout<<endl;
    file3.close();

    //Wczytanie rozdzielając linie
    fstream file4 ("text.txt", ios::in);
    line = "";
    while(getline(file4, line))
    {
        stringstream ss(line);
        string str;

        while(getline(ss, str, ','))
        {
            cout << str << endl;
        }
    }
    file4.close();

    //Zapis do pliku
    fstream file5 ("zapis.txt", ios::out);
    for(int i=0; i<101; i++)
    {
        file5 << i << endl;
    }
    file5.close();

    return 0;
}