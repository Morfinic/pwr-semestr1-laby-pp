#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

struct student
{
    unsigned int indeks;
    string imie;
    string nazwisko;
    unsigned int wiek;
    string plec;
};

void wczytywanie_z_pliku(vector<student> &stDB)
{
    fstream file;
    student temp;
    file.open("baza.txt", ios::in);

    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> temp.indeks;
            file >> temp.imie;
            file >> temp.nazwisko;
            file >> temp.wiek;
            file >> temp.plec;

            stDB.push_back(temp);
        }
    }
    else
        cout << "Nie udało się otworzyć pliku\n";

    file.close();
    stDB.pop_back();
    stDB.shrink_to_fit();
}

void zapis_do_pliku(vector<student> &stDB)
{
    fstream file;
    file.open("baza.txt", ios::out);

    if (file.is_open())
    {
        for (int i = 0; i < stDB.size(); i++)
            file << stDB[i].indeks << " " << stDB[i].imie << " " << stDB[i].nazwisko << " " << stDB[i].wiek << " " << stDB[i].plec << "\n";
    }
    else
        cout << "Nie udało się otworzyć pliku\n";

    file.close();
}

void wyswietl_baze(vector<student> &stDB)
{
    for (int i = 0; i < stDB.size(); i++)
        cout << stDB[i].indeks << " " << stDB[i].imie << " " << stDB[i].nazwisko << " " << stDB[i].wiek << " " << stDB[i].plec << "\n";
}

void usun_z_bazy(vector<student> &stDB)
{
    wyswietl_baze(stDB);

    unsigned int indeks;
    cout << "\nPodaj indeks studenta, którego chcesz usunąć: ";
    cin >> indeks;

    int i;
    for (i = 0; i < stDB.size(); i++)
    {
        if (stDB[i].indeks == indeks)
            break;
    }

    stDB.erase(stDB.begin() + i);
    stDB.shrink_to_fit();
}

void dodaj_do_bazy(vector<student> &stDB)
{
    student temp;

    cout << "Indeks (6 cyfrowa liczba np:. 123456): ";
    cin >> temp.indeks;
    cout << "Imię (Podać imię z dużej litery): ";
    cin >> temp.imie;
    cout << "Nazwisko (Podać nazwisko z dużej litery): ";
    cin >> temp.nazwisko;
    cout << "wiek (liczba np.: 14): ";
    cin >> temp.wiek;
    cout << "płeć (kobieta, mężczyzna): ";
    cin >> temp.plec;

    stDB.push_back(temp);
    stDB.shrink_to_fit();
}

void losowanie(vector<student> &stDB)
{
    srand(time(NULL));
    int randomStudent = rand() % stDB.size() - 1 + 0;
    cout << stDB[randomStudent].indeks << " " << stDB[randomStudent].imie << " " << stDB[randomStudent].nazwisko << " " << stDB[randomStudent].wiek << " " << stDB[randomStudent].plec << "\n";
}

void wyszukiwanie_w_bazie(vector<student> &stDB)
{
    unsigned int indeks;
    cout << "Podaj indeks szukanego studenta: ";
    cin >> indeks;

    for (int i = 0; i < stDB.size(); i++)
    {
        if (stDB[i].indeks == indeks)
        {
            cout << stDB[i].indeks << " " << stDB[i].imie << " " << stDB[i].nazwisko << " " << stDB[i].wiek << " " << stDB[i].plec << "\n";
            break;
        }
    }
}

void filtrowanie(vector<student> &stDB)
{
    int wyb;

    cout << "\nMENU filtrowania\n\t1. Po imieniu\n\t2. Po nazwisku\n\t3. Po wieku\n\t4. Po płci\n";
    cin >> wyb;

    switch (wyb)
    {
    case 1:
    {
        string imie;
        cout << "Podaj imie (z dużej litery): ";
        cin >> imie;
        for (int i = 0; i < stDB.size(); i++)
        {
            if (stDB[i].imie == imie)
                cout << stDB[i].indeks << " " << stDB[i].imie << " " << stDB[i].nazwisko << " " << stDB[i].wiek << " " << stDB[i].plec << "\n";
        }
        break;
    }
    case 2:
    {
        string nazwisko;
        cout << "Podaj nazwisko (z dużej litery): ";
        cin >> nazwisko;
        for (int i = 0; i < stDB.size(); i++)
        {
            if (stDB[i].nazwisko == nazwisko)
                cout << stDB[i].indeks << " " << stDB[i].imie << " " << stDB[i].nazwisko << " " << stDB[i].wiek << " " << stDB[i].plec << "\n";
        }
        break;
    }
    case 3:
    {
        unsigned int wiek;
        cout << "Podaj wiek (jako liczba np.: 14): ";
        cin >> wiek;
        for (int i = 0; i < stDB.size(); i++)
        {
            if (stDB[i].wiek == wiek)
                cout << stDB[i].indeks << " " << stDB[i].imie << " " << stDB[i].nazwisko << " " << stDB[i].wiek << " " << stDB[i].plec << "\n";
        }
        break;
    }
    case 4:
    {
        string plec;
        cout << "Podaj płeć (kobieta, mężczyzna): ";
        cin >> plec;
        for (int i = 0; i < stDB.size(); i++)
        {
            if (stDB[i].plec == plec)
                cout << stDB[i].indeks << " " << stDB[i].imie << " " << stDB[i].nazwisko << " " << stDB[i].wiek << " " << stDB[i].plec << "\n";
        }
        break;
    }
    default:
        cout << "ERROR -> default, filtrowanie";
        break;
    }
}

void sortowanie_bazy(vector<student> &stDB)
{
    short wyb;
    cout << "Wybierz kryterium sortowania: \n\t1. płeć\n\t2. wiek\n";
    cin >> wyb;

    switch (wyb)
    {
    case 1:
        for (int i = 0; i < stDB.size() - 1; i++)
        {
            for (int j = i; j < stDB.size(); j++)
            {
                if (stDB[i].plec > stDB[j].plec)
                    swap(stDB[i], stDB[j]);
            }
        }
        break;
    case 2:
        for (int i = 0; i < stDB.size() - 1; i++)
        {
            for (int j = i; j < stDB.size(); j++)
            {
                if (stDB[i].wiek > stDB[j].wiek)
                    swap(stDB[i], stDB[j]);
            }
        }
        cout << "Posortowano po wieku!\n";
        break;
    default:
        cout << "ERROR -> sortowanie bazy";
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "pl_PL.utf-8");
    vector<student> studentDB;
    int wyb;

    while (true)
    {
        cout << "\nMENU:\n\t1. Wczytywanie z pliku\n\t2. Zapis do pliku\n\t3. Wyświetlenie bazy\n\t"
                "4. Usuwanie\n\t5. Dodawanie\n\t6. Losowanie\n\t7. Wyszukiwanie\n\t8. "
                "Filtrowanie\n\t9. Sortowanie\n\t0. exit\n";

        cin >> wyb;

        switch (wyb)
        {
        case 0:
            return 0;
            break;
        case 1:
            wczytywanie_z_pliku(studentDB);
            cout << "Poprawnie odczytano dane\n";
            break;
        case 2:
            zapis_do_pliku(studentDB);
            cout << "Zapisano do pliku\n";
            break;
        case 3:
            wyswietl_baze(studentDB);
            break;
        case 4:
            usun_z_bazy(studentDB);
            cout << "Poprawnie usunięto studenta z bazy\n";
            cout << "\nUWAGA! Nie zapomnij zapisać rekordu w bazie.\n";
            break;
        case 5:
            dodaj_do_bazy(studentDB);
            cout << "Poprawnie dodano studenta do bazy\n";
            cout << "\nUWAGA! Nie zapomnij zapisać rekordu w bazie.\n";
            break;
        case 6:
            losowanie(studentDB);
            break;
        case 7:
            wyszukiwanie_w_bazie(studentDB);
            break;
        case 8:
            filtrowanie(studentDB);
            break;
        case 9:
            sortowanie_bazy(studentDB);
            break;
        default:
            cout << "ERROR -> default, main";
            break;
        }
    }

    return 0;
}
