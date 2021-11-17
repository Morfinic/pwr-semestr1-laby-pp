#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
#define tabMax 20

void tabWpisz(int *tab);
void tabNat(int *tab);
void tabRand(int *tab, int min, int max);
int tabSuma(int *tab);
int tabMaxElem(int *tab);
void tabPrint(int *tab);
void tabBubbleSort(int *tab);
int tabBinSearch(int *tab, int l, int r, int lookNum);

int main()
{
    int tab[tabMax] = {0};
    int *tabPointer = tab;
    int wyb;

    while (1)
    {
        cout << "\nMenu, zaleca sie rozpoczac od wypelnienia tablicy.\n"
                "\t1. User enter\n\t2. Naturalne enter\n\t3. Random fill"
                "\n\t4. Tab suma\n\t5. Tab max\n\t6. Tab print\n\t7. Bubble sort"
                "\n\t8. Binary search\n\t0. Exit\n";

        cin >> wyb;
        switch (wyb)
        {
        case 0:
            return 0;
            break;
        case 1:
            tabWpisz(tabPointer);
            break;
        case 2:
            tabNat(tabPointer);
            break;
        case 3:
            int min, max;
            cout << "Podaj min i max\n";
            cin >> min >> max;
            tabRand(tabPointer, min, max);
            break;
        case 4:
            cout << "Suma: " << tabSuma(tabPointer) << "\n";
            break;
        case 5:
            cout << "Max elem: " << tabMaxElem(tabPointer) << "\n";
            break;
        case 6:
            tabPrint(tabPointer);
            break;
        case 7:
            tabBubbleSort(tabPointer);
            break;
        case 8:
            int lookNum;
            cout << "Wpisz szukana liczbe: \n";
            tabBubbleSort(tabPointer);
            cin >> lookNum;
            cout << "Zwraca indeks tablicy na którym znajduję się liczba, -1 oznacza ze nie ma tej liczby w tablicy\n"
                    "tablica zostanie najpierw posortowana\n"
                    "Indeks: "
                 << tabBinSearch(tabPointer, 0, tabMax - 1, lookNum) << "\n";
            break;
        default:
            cout << "ERROR\n";
            break;
        }
    }

    return 0;
}

void tabWpisz(int *tab)
{
    int temp;
    for (int i = 0; i < tabMax; i++)
    {
        cin >> temp;
        tab[i] = temp;
    }
}

void tabNat(int *tab)
{
    for (int i = 0; i < tabMax; i++)
    {
        tab[i] = i + 1;
    }
}

void tabRand(int *tab, int min, int max)
{
    srand(time(NULL));
    for (int i = 0; i < tabMax; i++)
    {
        tab[i] = rand() % (max - min + 1);
    }
}

int tabSuma(int *tab)
{
    int sumaTemp(0);
    for (int i = 0; i < tabMax; i++)
    {
        sumaTemp += tab[i];
    }
    return sumaTemp;
}
int tabMaxElem(int *tab)
{
    int max = tab[0];
    for (int i = 1; i < tabMax; i++)
    {
        if (tab[i] > max)
        {
            max = tab[i];
        }
    }
    return max;
}
void tabPrint(int *tab)
{
    for (int i = 0; i < tabMax; i++)
    {
        cout << "tab[" << i << "]=" << tab[i] << "\n";
    }
}
void tabBubbleSort(int *tab)
{
    for (int i = 0; i < tabMax - 1; i++)
    {
        for (int j = i; j < tabMax - i; j++)
        {
            if (tab[i] > tab[j])
                swap(tab[i], tab[j]);
        }
    }
}
int tabBinSearch(int *tab, int l, int r, int lookNum)
{
    if (l <= tabMax - 1 && r >= 0)
    {
        int sr = (l + r) / 2;
        if (tab[sr] == lookNum)
            return sr;
        if (lookNum > tab[sr])
            return tabBinSearch(tab, sr + 1, r, lookNum);
        return tabBinSearch(tab, l, sr - 1, lookNum);
    }

    return -1;
}
