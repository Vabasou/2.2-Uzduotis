#include "libraries.hpp"
#include "ivedimasFailo.hpp"

double getVidurkisFailas(vector<double> &pazymiai){
    double sum = 0;

    for(int i = 0; i<pazymiai.size(); i++)
    {
        sum += pazymiai[i];
    }

    return sum/pazymiai.size();
}

double getMedianaFailas(vector<double> &pazymiai){
    double mediana;

    sort(pazymiai.begin(), pazymiai.end());

    if(pazymiai.size()%2 == 1)
    {
        mediana = pazymiai[pazymiai.size()/2];
    }     
    else  
    {
        mediana = pazymiai[pazymiai.size()/2] + pazymiai[(pazymiai.size()/2)- 1];
    }
    return mediana;   
}

void StudentasFailo::galutinisPazymys(vector<double> &pazymys, double egzamRez)
{
    egzamRez *= 0.6;
    galutinisVidurkis = ((getVidurkisFailas(pazymys) * 0.4) + egzamRez);
    galutinisMediana = ((getMedianaFailas(pazymys) * 0.4) + egzamRez);
}

bool StudentasFailo::operator<(StudentasFailo &stud) const
{
    return (Vardas < stud.Vardas);
}

void skaitymasIsFailo()
{
    auto start = std::chrono::high_resolution_clock::now();
    vector<StudentasFailo> Studentai;
    string failoString;
    std::fstream duomenys;

    std::ifstream input("kursiokai.txt");
        try
        {
            if(input.fail()) throw "Nepavyko atidaryti failo"; 
        }
        catch(const char * e)
        {
            std::cerr << e << endl;
            exit(EXIT_FAILURE);
        }
        duomenys.open("kursiokai.txt");        
    
    //duomenys.open("kursiokai.txt");
    string buffString;

    stringstream my_buffer;

    my_buffer << duomenys.rdbuf();
    duomenys.close();
        
    stringstream fileStream(failoString);
        
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
                if(buffDouble > 10 || buffDouble < 1)
                {
                    throw std::runtime_error("Faile yra pazymys, kaip is pasakos trauktas!!!\n");
                }
            }
            catch(const std::runtime_error& e)
            {
                std::cout << e.what() << '\n';
            }            

            if(lineStream.eof()) examRez = buffDouble;
            else pazymiai.push_back(buffDouble);
        }

        buffStud.galutinisPazymys(pazymiai, examRez);
        pazymiai.clear();
        Studentai.push_back(buffStud);
    }

    sort(Studentai.begin(), Studentai.end());
    isvedimasFailo(Studentai);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    cout << "elementu uzpildymas uztruko: "<< diff.count() << " s\n";
}

void isvedimasFailo(vector<StudentasFailo> studentas)
{   
    ofstream out_file ("kursiokaiOut.txt");
    
    out_file << "Vardas" << setw(10+7) << "Pavarde" << setw(10+15) << "Vidurkis (med.)" << setw(5+15) << "Vidurkis (vid.)" 
    << endl << "------------------------------------------------------------------------------" << endl;
    for(int i =0 ; i < studentas.size(); i++)
    {
        out_file << studentas[i].Vardas << setw(16-studentas[i].Vardas.length()+studentas[i].Pavarde.length()) << studentas[i].Pavarde 
        << setw(18-studentas[i].Pavarde.length()+3) << fixed << setprecision(2) << studentas[i].galutinisVidurkis
        << setw(20-3+3) << fixed << setprecision(2) << studentas[i].galutinisMediana << endl;
    }
    out_file.close();
}