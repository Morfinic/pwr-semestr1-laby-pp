#include <iostream>

int sumZakres();
int sumPierwsze();
bool czyPierwsza(int num);
int NWD(int a, int b);

int main()
{
    while (true)
    {
        int wybor;

        std::cout << "MENU\n0. Exit\n1. Suma z zakresu < -15, 15 >\n2. Suma z pierwszych\n3. NWD\n";
        std::cin >> wybor;

        switch (wybor)
        {
        case 0:
            return 0;
            break;
        case 1:
            int wynik1;
            wynik1 = sumZakres();
            std::cout << "Wynik: " << wynik1 << "\n\n";
            break;
        case 2:
            int wynik2;
            wynik2 = sumPierwsze();
            std::cout << "Wynik: " << wynik2 << "\n\n";
            break;
        case 3:
            int a(0), b(0);
            std::cout << "Podaj a, b do NWD\n";
            std::cin >> a >> b;
            int wynik3(NWD(a, b));
            std::cout << "Wynik: " << wynik3 << "\n\n";
            break;
        }
    }
}

int sumZakres()
{
    int wynik(0), temp(0);

    std::cout << "Podaj liczby: \n";

    do
    {
        std::cin >> temp;
        if (temp >= -15 && temp <= 15)
        {
            wynik += temp;
        }
    } while (temp != 99);

    return wynik;
}

int sumPierwsze()
{
    int temp(0), wynik(0);
    std::cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        std::cin >> temp;
        if (temp > 1 && czyPierwsza(temp))
        {
            wynik++;
        }
    }
    return wynik;
}

bool czyPierwsza(int num)
{
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int NWD(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}
