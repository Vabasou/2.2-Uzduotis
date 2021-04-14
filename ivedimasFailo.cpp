#include "libraries.hpp"
#include "funkcijos.hpp"
#include "ivedimasFailo.hpp"
#include "strukturos.hpp"

template <class T>
void skaitymasIsFailo(T &Studentai, string failas)
{
    auto start = std::chrono::high_resolution_clock::now();
    string failoString;
    std::fstream duomenys;

    duomenys.open(failas);
    try
    {
        if(duomenys.fail()) throw "Nepavyko atidaryti failo"; 
    }
    catch(const char * e)
    {
        std::cerr << e << endl;
        exit(EXIT_FAILURE);
    } 

    stringstream my_buffer;

    my_buffer << duomenys.rdbuf();
    duomenys.close();
        
    getline(my_buffer, failoString);
    
    while(!my_buffer.eof())
    {
        string eil;
        getline(my_buffer, eil);
            
        if(my_buffer.eof()) break;     
            
        stringstream lineStream(eil); 
            
        vector <double> pazymiai;
        StudentasFailo buffStud;
        double examRez;

        lineStream>>buffStud.Vardas>>buffStud.Pavarde;

        while(!lineStream.eof()){

            double buffDouble;
            lineStream >> buffDouble;
            try
            {
                if(buffDouble > 10 || buffDouble < 0)
                {
                    throw std::runtime_error("Faile yra pazymys, kaip is pasakos trauktas!!!\n");
                }
            }
            catch(const std::runtime_error& e)
            {
                std::cout << e.what() << '\n';
                exit(EXIT_FAILURE);
            }            

            if(lineStream.eof()) examRez = buffDouble;
            else pazymiai.push_back(buffDouble);
        }

        buffStud.galutinisPazymys(pazymiai, examRez);
        pazymiai.clear();
        Studentai.push_back(buffStud);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Elementu nuskaitymas uztruko: "<< diff.count() << " s\n";
}

template <class T>
void isvedimasFailuose(T &studentas)
{   
    ofstream out_fileNoobs ("kursiokaiNoobai.txt");
    ofstream out_fileCools ("kursiokaiNiordai.txt");
    
    out_fileNoobs << "Vardas" << setw(10+7) << "Pavarde" << setw(10+15) << "Galutinis (vid.)" << setw(5+15) << "Galutinis (med.)"
    << endl << "------------------------------------------------------------------------------" << endl;
    out_fileCools << "Vardas" << setw(10+7) << "Pavarde" << setw(10+15) << "Galutinis (vid.)" << setw(5+15) << "Galutinis (med.)"  
    << endl << "------------------------------------------------------------------------------" << endl;    
    for(const auto &stud : studentas)
    {
        if(stud.galutinisVidurkis >= 5)
        {
            out_fileCools << stud.Vardas << setw(16 - stud.Vardas.length() + stud.Pavarde.length()) << stud.Pavarde 
            << setw(18 - stud.Pavarde.length() + 3) << fixed << setprecision(2) << stud.galutinisVidurkis
            << setw(20 - 3 + 3) << fixed << setprecision(2) << stud.galutinisMediana << endl;
        }
        else
        {
            out_fileNoobs << stud.Vardas << setw(16 - stud.Vardas.length() + stud.Pavarde.length()) << stud.Pavarde 
            << setw(18 - stud.Pavarde.length() + 3) << fixed << setprecision(2) << stud.galutinisVidurkis
            << setw(20 - 3 + 3) << fixed << setprecision(2) << stud.galutinisMediana << endl;
        }
        
    }
    out_fileNoobs.close();
    out_fileCools.close();
}

template <class T>
void isvedimasFailo(T &studentas, string failas)
{   
    ofstream out_file (failas);
    
    out_file << "Vardas" << setw(10+7) << "Pavarde" << setw(10+15) << "Galutinis (vid.)" << setw(5+15) << "Galutinis (med.)" 
    << endl << "------------------------------------------------------------------------------" << endl;
    for(const auto &stud : studentas)
    {
        out_file << stud.Vardas << setw(16-stud.Vardas.length()+stud.Pavarde.length()) << stud.Pavarde 
        << setw(18-stud.Pavarde.length()+3) << fixed << setprecision(2) << stud.galutinisVidurkis
        << setw(20-3+3) << fixed << setprecision(2) << stud.galutinisMediana << endl;
    }
    out_file.close();
}

void failoSortVector(string failas)
{
    vector <StudentasFailo> Studentai;

    skaitymasIsFailo(Studentai, failas);

    auto startSort = std::chrono::high_resolution_clock::now();

    sort(Studentai.begin(), Studentai.end());

    int i;
    for(i = 0; i < Studentai.size(); i++)
    {
        if(Studentai[i].galutinisVidurkis >= 5)
            break;
    }

    vector <StudentasFailo> :: iterator Pradzia = Studentai.begin() + i;
    vector <StudentasFailo> :: iterator Pabaiga = Studentai.end();
    vector <StudentasFailo> cools(Pradzia, Pabaiga);
    Studentai.resize(i);

    auto endSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSort = endSort - startSort;
    cout << "Studentu rikiavimas su vektorium uztruko: "<< diffSort.count() << " s\n";

    isvedimasFailo(cools, "kursiokaiNiordai.txt");
    isvedimasFailo(Studentai, "kursiokaiNoobai.txt");

    cools.clear();
    Studentai.clear();
}

void failoSortList(string failas)
{
    list <StudentasFailo> Studentai;

    skaitymasIsFailo(Studentai, failas);

    auto startSort = std::chrono::high_resolution_clock::now();

    Studentai.sort();

    list <StudentasFailo> :: iterator it = Studentai.begin();
    for(const auto &stud : Studentai)
    {
        if(stud.galutinisVidurkis >= 5)
            break;
        advance(it, 1);
    }
    list <StudentasFailo> cools;
    cools.splice(cools.begin(), Studentai, it, Studentai.end());

    auto endSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSort = endSort - startSort;
    cout << "Studentu rikiavimas su list uztruko: "<< diffSort.count() << " s\n";

    isvedimasFailo(cools, "kursiokaiNiordai.txt");
    isvedimasFailo(Studentai, "kursiokaiNoobai.txt");

    cools.clear();
    Studentai.clear();
}

void failoSortDeque(string failas)
{
    deque <StudentasFailo> Studentai;

    skaitymasIsFailo(Studentai, failas);

    auto startSort = std::chrono::high_resolution_clock::now();

    sort(Studentai.begin(), Studentai.end());

    int i;
    for(i = 0; i < Studentai.size(); i++)
    {
        if(Studentai[i].galutinisVidurkis >= 5)
            break;
    }

    deque <StudentasFailo> :: iterator Pradzia = Studentai.begin() + i;
    deque <StudentasFailo> :: iterator Pabaiga = Studentai.end();
    deque <StudentasFailo> cools(Pradzia, Pabaiga);
    Studentai.resize(i);

    auto endSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSort = endSort - startSort;
    cout << "Studentu rikiavimas su deque uztruko: "<< diffSort.count() << " s\n";

    isvedimasFailo(cools, "kursiokaiNiordai.txt");
    isvedimasFailo(Studentai, "kursiokaiNoobai.txt");

    cools.clear();
    Studentai.clear();
}

void failoSortVector2Budas(string failas)
{
    vector <StudentasFailo> studentai;
    vector <StudentasFailo> good;
    vector <StudentasFailo> bad;

    skaitymasIsFailo(studentai, failas);

    auto startSort = std::chrono::high_resolution_clock::now();

    int i;
    for(i = 0; i < studentai.size(); i++)
    {
        if(studentai[i].galutinisVidurkis >= 5)
            good.push_back(studentai[i]);
        else
            bad.push_back(studentai[i]);
    }

    auto endSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSort = endSort - startSort;
    cout << "Studentu rikiavimas su vektorium uztruko: "<< diffSort.count() << " s\n";

    isvedimasFailo(good, "kursiokaiNiordai.txt");
    isvedimasFailo(bad, "kursiokaiNoobai.txt");

    good.clear();
    bad.clear();
    studentai.clear();
}

void failoSortList2Budas(string failas)
{
    list <StudentasFailo> studentai;
    list <StudentasFailo> good;
    list <StudentasFailo> bad;

    skaitymasIsFailo(studentai, failas);

    auto startSort = std::chrono::high_resolution_clock::now();

    for(const auto &stud : studentai)
    {
        if(stud.galutinisVidurkis >= 5)
            good.push_back(stud);
        else
            bad.push_back(stud);        
    }

    isvedimasFailo(good, "kursiokaiNiordai.txt");
    isvedimasFailo(bad, "kursiokaiNoobai.txt");

    auto endSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSort = endSort - startSort;
    cout << "Studentu rikiavimas su list uztruko: "<< diffSort.count() << " s\n";

    good.clear();
    bad.clear();
    studentai.clear();
}

void failoSortDeque2Budas(string failas)
{
    deque <StudentasFailo> studentai;
    deque <StudentasFailo> good;
    deque <StudentasFailo> bad;

    skaitymasIsFailo(studentai, failas);

    auto startSort = std::chrono::high_resolution_clock::now();

    for(const auto &stud : studentai)
    {
        if(stud.galutinisVidurkis >= 5)
            good.push_back(stud);
        else
            bad.push_back(stud);        
    }

    isvedimasFailo(good, "kursiokaiNiordai.txt");
    isvedimasFailo(bad, "kursiokaiNoobai.txt");

    auto endSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSort = endSort - startSort;
    cout << "Studentu rikiavimas su deque uztruko: "<< diffSort.count() << " s\n";

    good.clear();
    bad.clear();
    studentai.clear();
}