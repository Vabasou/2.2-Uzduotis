#include "libraries.hpp"
#include "sort.hpp"
#include "klase.hpp"
#include "inOut.hpp"

void failoSortVector(string failas)
{
    vector <Studentas> Studentai;

    skaitymasIsFailo(Studentai, failas);

    auto startSort = std::chrono::high_resolution_clock::now();

    sort(Studentai.begin(), Studentai.end());

    int i;
    for(i = 0; i < Studentai.size(); i++)
    {
        if(Studentai[i].getVidurkis() >= 5)
            break;
    }

    vector <Studentas> :: iterator Pradzia = Studentai.begin() + i;
    vector <Studentas> :: iterator Pabaiga = Studentai.end();
    vector <Studentas> cools(Pradzia, Pabaiga);
    Studentai.resize(i);

    auto endSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSort = endSort - startSort;
    cout << "Studentu rikiavimas su vektorium uztruko: "<< diffSort.count() << " s\n";

    outputas(cools, "kursiokaiNiordai.txt");
    outputas(Studentai, "kursiokaiNoobai.txt");

    cools.clear();
    Studentai.clear();
}

void failoSortList(string failas)
{
    list <Studentas> Studentai;

    skaitymasIsFailo(Studentai, failas);

    auto startSort = std::chrono::high_resolution_clock::now();

    Studentai.sort();

    list <Studentas> :: iterator it = Studentai.begin();
    for(auto &stud : Studentai)
    {
        if(stud.getVidurkis() >= 5)
            break;
        advance(it, 1);
    }
    list <Studentas> cools;
    cools.splice(cools.begin(), Studentai, it, Studentai.end());

    auto endSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSort = endSort - startSort;
    cout << "Studentu rikiavimas su list uztruko: "<< diffSort.count() << " s\n";

    outputas(cools, "kursiokaiNiordai.txt");
    outputas(Studentai, "kursiokaiNoobai.txt");

    cools.clear();
    Studentai.clear();
}

void failoSortDeque(string failas)
{
    deque <Studentas> Studentai;

    skaitymasIsFailo(Studentai, failas);

    auto startSort = std::chrono::high_resolution_clock::now();

    sort(Studentai.begin(), Studentai.end());

    int i;
    for(i = 0; i < Studentai.size(); i++)
    {
        if(Studentai[i].getVidurkis() >= 5)
            break;
    }

    deque <Studentas> :: iterator Pradzia = Studentai.begin() + i;
    deque <Studentas> :: iterator Pabaiga = Studentai.end();
    deque <Studentas> cools(Pradzia, Pabaiga);
    Studentai.resize(i);

    auto endSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSort = endSort - startSort;
    cout << "Studentu rikiavimas su deque uztruko: "<< diffSort.count() << " s\n";

    outputas(cools, "kursiokaiNiordai.txt");
    outputas(Studentai, "kursiokaiNoobai.txt");

    cools.clear();
    Studentai.clear();
}

void failoSortVector2Budas(string failas)
{
    vector <Studentas> studentai;
    vector <Studentas> good;
    vector <Studentas> bad;

    skaitymasIsFailo(studentai, failas);

    auto startSort = std::chrono::high_resolution_clock::now();

    int i;
    for(i = 0; i < studentai.size(); i++)
    {
        if(studentai[i].getVidurkis() >= 5)
            good.push_back(studentai[i]);
        else
            bad.push_back(studentai[i]);
    }

    auto endSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSort = endSort - startSort;
    cout << "Studentu rikiavimas su vektorium uztruko: "<< diffSort.count() << " s\n";

    outputas(good, "kursiokaiNiordai.txt");
    outputas(bad, "kursiokaiNoobai.txt");

    cout << "good: " << sizeof(good) << endl;
    cout << "bad: " << sizeof(bad) << endl;
    cout << "all: " << sizeof(studentai) << endl;

    good.clear();
    bad.clear();
    studentai.clear();
}

void failoSortList2Budas(string failas)
{
    list <Studentas> studentai;
    list <Studentas> good;
    list <Studentas> bad;

    skaitymasIsFailo(studentai, failas);

    auto startSort = std::chrono::high_resolution_clock::now();

    for(auto &stud : studentai)
    {
        if(stud.getVidurkis() >= 5)
            good.push_back(stud);
        else
            bad.push_back(stud);        
    }

    outputas(good, "kursiokaiNiordai.txt");
    outputas(bad, "kursiokaiNoobai.txt");

    auto endSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSort = endSort - startSort;
    cout << "Studentu rikiavimas su list uztruko: "<< diffSort.count() << " s\n";

    cout << "good: " << sizeof(good) << endl;
    cout << "bad: " << sizeof(bad) << endl;
    cout << "all: " << sizeof(studentai) << endl;


    good.clear();
    bad.clear();
    studentai.clear();
}

void failoSortDeque2Budas(string failas)
{
    deque <Studentas> studentai;
    deque <Studentas> good;
    deque <Studentas> bad;

    skaitymasIsFailo(studentai, failas);

    auto startSort = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < studentai.size(); i++)
    {
        if(studentai[i].getVidurkis() >= 5)
            good.push_back(studentai[i]);
        else
            bad.push_back(studentai[i]);        
    }

    outputas(good, "kursiokaiNiordai.txt");
    outputas(bad, "kursiokaiNoobai.txt");

    auto endSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSort = endSort - startSort;
    cout << "Studentu rikiavimas su deque uztruko: "<< diffSort.count() << " s\n";

    cout << "good: " << sizeof(good) << endl;
    cout << "bad: " << sizeof(bad) << endl;
    cout << "all: " << sizeof(studentai) << endl;

    good.clear();
    bad.clear();
    studentai.clear();
}
