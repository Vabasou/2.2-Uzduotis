#include "libraries.hpp"
#include "funkcijos.hpp"
#include "ivedimasRankinis.hpp"
#include "ivedimasFailo.hpp"
#include "sukurimasFailo.hpp"

int main()
{
    string failas;
    int pasirinkimas;
    cout << "Pasirinkite, ka norite daryti: " << endl;
    cout << "1. Rasyti savo duomenis" << endl;
    cout << "2. Nuskaityti is failo" << endl;
    cout << "3. Sugeneruoti random faila" << endl;
    cout << "4. Patikrinti greicius" << endl;
    cin >> pasirinkimas;

    if (pasirinkimas == 1) ivestis();
    if (pasirinkimas == 2)
    {
        int pasirinkimas2;
        cout << "Pasirinkite duomenu faila: " << endl;
        cout << "1. 10" << endl;
        cout << "2. 10 000" << endl;
        cout << "3. 100 000" << endl;
        cout << "4. 1 000 000" << endl;
        cin >> pasirinkimas2;

        if (pasirinkimas2 == 1) failas = "kursiokai.txt";
        if (pasirinkimas2 == 2) failas = "kursiokai10000.txt";
        if (pasirinkimas2 == 3) failas = "kursiokai100000.txt";
        if (pasirinkimas2 == 4) failas = "kursiokai1000000.txt";

        failoSortVector(failas);
    }
    if (pasirinkimas == 3)
    {
        string failas = "studentai.txt";
        sukurimasFailo();

        failoSortVector(failas);
        cout << endl;
    }
    if (pasirinkimas == 4)
    {   
        string failas = "studentai.txt";
        sukurimasFailo();

        failoSortVector(failas);
        cout << endl;

        failoSortList(failas);
        cout << endl;

        failoSortDeque(failas);
        cout << endl;
    }

    return 0;
}