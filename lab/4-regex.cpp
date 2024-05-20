#include <iostream>
#include <vector>
#include <regex>

using namespace std;

int main()
{
    /*
    Regex
    */

    string text1 = "61-312";
    string text2 = "a6-413";
    string text3 = "Moj kod pocztowy to 61-867 albo 65-987 nie pamietam";

    //regex_match -> czy ciąg jest zgodny ze wzorcem

    regex re(R"(\d{2}-\d{3})");
    smatch m;

    cout << regex_match(text1, m, re) << endl;
    cout << regex_match(text2, m, re) << endl << endl;

    //regex_search -> wyszukuje w ciągu pierwszy podciąg zgodny ze wzorcem
    
    cout << regex_search(text3, m, re) << endl; 
    //Cała funcja zwróci 1 gdy podciąg zostanie znaleziony. Do m zostaną wprowadzone zmiany:
    // m.empty() -> false
    // m.size() -> liczba istniejących grup dopasowań
    // m.prefix() -> podciąg poprzedzający dopasowanie
    // m.suffix() -> podciąg następujący po dopasowaniu
    // m[0] -> text dopasowania
    // m[n] -> text n grupy dopasowanie
    // m[n].matched() -> true/false -> czy n grupa została dopasowana

    cout << m[0] << endl;
    cout << m.prefix() << endl;
    cout << m.suffix() << endl << endl;

    //Wyszukiwanie wszystkich pasujących podciągów

    while(regex_search(text3, m, re))
    {
        cout << m[0] << endl; //Wyświetlenioe pasującego podciągu
        text3 = m.suffix(); //Usunięcie z napisu przeszukanej części
    }
    cout<<endl;

    //Wyświetlanie tylko dopasowanych
    vector<string> lines = {"PO12345", "PO 12345", "PZ973ND", "WE20456"};

    regex reg(R"((PO|PZ)\s?\w{5})");
    smatch m2;

    for(auto &i : lines)
    {
        if(regex_match(i, m2, reg))
            cout << i << endl;
    }

    return 0;
}