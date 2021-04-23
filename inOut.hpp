#pragma once
#include "klase.hpp"
#include <fstream>
#include <sstream>
#include <chrono>

template <class T>
void outputas(T &studentai, std::string failas)
{
    std::ofstream outFile(failas);
    outFile << "Vardas" << setw(10+7) << "Pavarde" << setw(10+15) << "Galutinis (vid.)" << setw(5+15) << "Galutinis (med.)" 
    << endl << "------------------------------------------------------------------------------" << endl;
    for(auto &stud : studentai)
    {
        outFile << stud.getVardas() << setw(16-stud.getVardas().length()+stud.getPavarde().length()) << stud.getPavarde() 
        << setw(18-stud.getPavarde().length()+3) << fixed << setprecision(2) << stud.getVidurkis()
        << setw(20-3+3) << fixed << setprecision(2) << stud.getMediana() << endl;
    }
    outFile.close(); 
}

template <class T>
void skaitymasIsFailo(T &Studentai, std::string failas)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::string failoString;
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

    std::stringstream my_buffer;

    my_buffer << duomenys.rdbuf();
    duomenys.close();
        
    getline(my_buffer, failoString);
    
    while(!my_buffer.eof())
    {
        string eil;
        getline(my_buffer, eil);
            
        if(my_buffer.eof()) break;     
            
        std::stringstream lineStream(eil); 
            
        std::vector <double> pazymiai;
        Studentas buffStud;
        double examRez;
        std::string vardas, pavarde;
        lineStream >> vardas >> pavarde;
        buffStud.setVardas(vardas);
        buffStud.setPavarde(pavarde);

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
