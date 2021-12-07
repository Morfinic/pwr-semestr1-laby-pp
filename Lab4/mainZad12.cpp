#include <iostream>
using namespace std;
#define maxCharTab 256

void wpisywanieCharTab(char *charTab);
void wyswietlanieCharTab(char *charTab);
int iloscZnakowCharTab(char *charTab);
void zamianaNaDuze(char *charTab, int fromSwitch);
void zamianaNaMale(char *charTab, int fromSwitch);
void histogramCharTab(char *charTab);

int main()
{
    char charTab[maxCharTab] = {'\0'};

    while (true)
    {

        cout << "Menu\n\t1. Wprowadzanie teksty.\n\t2. Wyswietlanie tekstu\n\t"
                "3. Zwrocenie liczby znakow\n\t4. Zamiania wielkosci liter na duze\n\t"
                "5. Zamiana wielkosci liter na male\n\t6. Histogram liter\n\t"
                "0. Wyjscie\n";

        short wyb;
        cout << "Podaj wybor: ";
        cin >> wyb;

        switch (wyb)
        {
        case 0:
            return 0;
            break;
        case 1:
            wpisywanieCharTab(charTab);
            break;
        case 2:
            wyswietlanieCharTab(charTab);
            break;
        case 3:
            cout << "Ilosc znakow w tablicy: " << iloscZnakowCharTab(charTab) << "\n";
            break;
        case 4:
            zamianaNaDuze(charTab, 1);
            break;
        case 5:
            zamianaNaMale(charTab, 1);
            break;
        case 6:
            histogramCharTab(charTab);
            break;
        default:
            cout << "ERROR";
            break;
        }
    }
}

void wpisywanieCharTab(char *charTab)
{
    cout << "Podiaj ciag znakow do wpisania do tablicy: ";
    cin.ignore();
    cin.getline(charTab, maxCharTab);
    cout << endl;
}

void wyswietlanieCharTab(char *charTab)
{
    for (int i = 0; i < maxCharTab; i++)
    {
        if (charTab[i] == '\0')
            break;
        cout << charTab[i];
    }
    cout << endl;
}

int iloscZnakowCharTab(char *charTab)
{
    int cntr = 0;

    for (int i = 0; i < maxCharTab; i++)
    {
        if (charTab[i] == '\0')
            break;
        cntr++;
    }
    return cntr;
}

void zamianaNaDuze(char *charTab, int fromSwitch)
{
    for (int i = 0; i < maxCharTab; i++)
    {
        if (static_cast<int>(charTab[i]) >= 97 && static_cast<int>(charTab[i]) <= 122)
            charTab[i] -= 32;
    }
    if (fromSwitch)
        wyswietlanieCharTab(charTab);
}

void zamianaNaMale(char *charTab, int fromSwitch)
{
    for (int i = 0; i < maxCharTab; i++)
    {
        if (static_cast<int>(charTab[i]) >= 65 && static_cast<int>(charTab[i]) <= 90)
            charTab[i] += 32;
    }
    if (fromSwitch)
        wyswietlanieCharTab(charTab);
}

void histogramCharTab(char *charTab)
{
    char charTabCopy[maxCharTab] = {'\0'};
    unsigned const short charCntrSize = 26;
    int charCntr[charCntrSize] = {0};

    for (int i = 0; i < maxCharTab; i++)
    {
        if (charTab[i] != '\0')
            charTabCopy[i] = charTab[i];
    }

    zamianaNaMale(charTabCopy, 0);

    for (int i = 0; i < maxCharTab; i++)
    {
        if (charTabCopy[i] == '\0')
            break;
        if (static_cast<int>(charTabCopy[i]) >= 97 && static_cast<int>(charTabCopy[i]) <= 122)
        {
            charCntr[static_cast<int>(charTabCopy[i]) % 97]++;
        }
    }

    for (int i = 0; i < charCntrSize; i++)
    {
        if (charCntr[i] == 0)
            continue;
        cout << static_cast<char>(97 + i) << " ";
        for (int j = 0; j < charCntr[i]; j++)
            cout << "#";
        cout << endl;
    }
    cout << endl;
}
