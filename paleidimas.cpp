#include "libraries.hpp"
#include "inOut.hpp"
#include "genRand.hpp"
#include "sort.hpp"
#include "ivedimasRankinis.hpp"

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
        generuoti();

        failoSortVector(failas);
        cout << endl;
    }
    if (pasirinkimas == 4)
    {   
        cout << "Kuria strategija naudoti? :" << endl;
        cout << "1. Nauji konteineriai" << endl;
        cout << "2. Panaudojami seni konteineriai" << endl;
        int ats;
        cin >> ats;
        
        generuoti();

        if(ats == 1)
        {
            string failas = "studentai.txt";

            auto startVector = std::chrono::high_resolution_clock::now();

            failoSortVector2Budas(failas);

            auto endVector = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diffVector = endVector - startVector;
            cout << "Vector laikas: "<< diffVector.count() << " s\n";
            cout << endl;

            auto startList = std::chrono::high_resolution_clock::now();

            failoSortList2Budas(failas);

            auto endList = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diffList = endList - startList;
            cout << "List laikas: "<< diffList.count() << " s\n";
            cout << endl;

            auto startDeque = std::chrono::high_resolution_clock::now();

            failoSortDeque2Budas(failas);

            auto endDeque = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diffDeque = endDeque - startDeque;
            cout << "Deque laikas: "<< diffDeque.count() << " s\n";
            cout << endl;
        }
        else if(ats == 2)
        {
            string failas = "studentai.txt";

            auto startVector = std::chrono::high_resolution_clock::now();

            failoSortVector(failas);

            auto endVector = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diffVector = endVector - startVector;
            cout << "Vector laikas: "<< diffVector.count() << " s\n";
            cout << endl;

            auto startList = std::chrono::high_resolution_clock::now();

            failoSortList(failas);

            auto endList = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diffList = endList - startList;
            cout << "List laikas: "<< diffList.count() << " s\n";
            cout << endl;

            auto startDeque = std::chrono::high_resolution_clock::now();

            failoSortDeque(failas);

            auto endDeque = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diffDeque = endDeque - startDeque;
            cout << "Deque laikas: "<< diffDeque.count() << " s\n";
            cout << endl;
        }
        else
        {
            cout << "Netinkama reiksme" << endl;
            cin.clear();
            cin.ignore(100000, '\n');
        }
    }

    return 0;
}