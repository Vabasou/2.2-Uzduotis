#include "libraries.hpp"
#include "funkcijos.hpp"
#include "ivedimasFailo.hpp"
#include "strukturos.hpp"


void skaitymasIsFailo(string failas)
{
    auto start = std::chrono::high_resolution_clock::now();
    vector<StudentasFailo> Studentai;
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

    auto startSort = std::chrono::high_resolution_clock::now();

    sort(Studentai.begin(), Studentai.end());

    auto endSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSort = endSort - startSort;
    cout << Studentai.size() << " studentu rikiavimas uztruko: "<< diffSort.count() << " s\n";

    cout << "Ar norite isvesti i du atskirus failus?: y/n (y-yes / n-no)" << endl;
    char ats;
    atsRibojimas(ats);
    if(ats == 'Y' || ats == 'y')
    {
        auto startIsvedimas = std::chrono::high_resolution_clock::now();
        isvedimasFailuose(Studentai);
        auto endIsvedimas = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diffIsvedimas = endIsvedimas - startIsvedimas;
        cout << Studentai.size() << " studentu isvedimas i dvi grupes uztruko: "<< diffIsvedimas.count() << " s\n";
    }
    else
    {
        isvedimasFailo(Studentai);
    }    
}
void isvedimasFailuose(vector<StudentasFailo> studentas)
{   

    ofstream out_fileNoobs ("kursiokaiNoobai.txt");
    ofstream out_fileCools ("kursiokaiNiordai.txt");
    
    out_fileNoobs << "Vardas" << setw(10+7) << "Pavarde" << setw(10+15) << "Galutinis (vid.)" << setw(5+15) << "Galutinis (med.)"
    << endl << "------------------------------------------------------------------------------" << endl;
    out_fileCools << "Vardas" << setw(10+7) << "Pavarde" << setw(10+15) << "Galutinis (vid.)" << setw(5+15) << "Galutinis (med.)"  
    << endl << "------------------------------------------------------------------------------" << endl;
    long int i;
    for(i = 0 ; i < studentas.size(); i++)
    {
        if(studentas[i].galutinisVidurkis >= 5)
        {
            out_fileCools << studentas[i].Vardas << setw(16-studentas[i].Vardas.length()+studentas[i].Pavarde.length()) << studentas[i].Pavarde 
            << setw(18-studentas[i].Pavarde.length()+3) << fixed << setprecision(2) << studentas[i].galutinisVidurkis
            << setw(20-3+3) << fixed << setprecision(2) << studentas[i].galutinisMediana << endl;
        }
        else
        {
            out_fileNoobs << studentas[i].Vardas << setw(16-studentas[i].Vardas.length()+studentas[i].Pavarde.length()) << studentas[i].Pavarde 
            << setw(18-studentas[i].Pavarde.length()+3) << fixed << setprecision(2) << studentas[i].galutinisVidurkis
            << setw(20-3+3) << fixed << setprecision(2) << studentas[i].galutinisMediana << endl;
        }
        
    }
    out_fileNoobs.close();
    out_fileCools.close();
}

void isvedimasFailo(vector<StudentasFailo> studentas)
{   
    ofstream out_file ("kursiokaiOut.txt");
    
    out_file << "Vardas" << setw(10+7) << "Pavarde" << setw(10+15) << "Galutinis (vid.)" << setw(5+15) << "Galutinis (med.)" 
    << endl << "------------------------------------------------------------------------------" << endl;
    for(int i =0 ; i < studentas.size(); i++)
    {
        out_file << studentas[i].Vardas << setw(16-studentas[i].Vardas.length()+studentas[i].Pavarde.length()) << studentas[i].Pavarde 
        << setw(18-studentas[i].Pavarde.length()+3) << fixed << setprecision(2) << studentas[i].galutinisVidurkis
        << setw(20-3+3) << fixed << setprecision(2) << studentas[i].galutinisMediana << endl;
    }
    out_file.close();
}