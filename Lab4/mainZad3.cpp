#include <iostream>
using namespace std;

unsigned int maxTabSize = 4;
unsigned int tabElemCntr = 0;

void wyswietlanieCharTab(char *charTab);
void addToTab(char *charTab);

int main()
{
    char *tab = new char[maxTabSize]{'\0'};
    int wyb;

    while (true)
    {
        cout << "MENU\n\t1. Dodaj element na koncu tablicy\n\t2. Usun dowolny element"
                "\n\t0. Exit\nAktualny stan tablicy:\n\tWielkosc: ";
        cout << maxTabSize << "\n\tDostepna liczba elementow: ";
        cout << maxTabSize - tabElemCntr << endl;
        wyswietlanieCharTab(tab);

        cin >> wyb;

        switch (wyb)
        {
        case 0:
            delete[] tab;
            return 0;
            break;
        case 1:
            addToTab(tab);
            break;
        case 2:
            break;
        default:
            cout << "ERROR\n";
            break;
        }
    }
}

void wyswietlanieCharTab(char *charTab)
{
    for (int i = 0; i < maxTabSize; i++)
    {
        if (charTab[i] == '\0')
            break;
        cout << charTab[i];
    }
    cout << endl;
}

void addToTab(char *charTab)
{
    char temp;
    cin >> temp;

    if(maxTabSize == tabElemCntr){
        
    }

    charTab[tabElemCntr] = temp;
    tabElemCntr++;
}
