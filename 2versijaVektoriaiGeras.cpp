#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <chrono> 

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::setw;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::stringstream;
using std::fstream;
using std::setprecision;
using std::fixed;

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

    if(pazymiai.size()%2 == 0)
    {
        mediana = pazymiai[pazymiai.size()/2];
    }     
    else  
    {
        mediana = pazymiai[pazymiai.size()/2] + pazymiai[(pazymiai.size()/2)- 1];
    }
    return mediana;
   
}

struct StudentasFailo{
    string Vardas, Pavarde;
    double galutinisVidurkis, galutinisMediana;

    void galutinisPazymys(vector<double> &grades, double egzamRez){
        egzamRez *= 0.6;
        galutinisVidurkis = ((getVidurkisFailas(grades)*0.4) + egzamRez);
        galutinisMediana = ((getMedianaFailas(grades)*0.4) + egzamRez);
    }

    bool operator < (StudentasFailo &stud) const {
        return Vardas.compare(stud.Vardas) < 0;
    }
};

struct zmogus
{
    string vardas, pavarde;
    int n = 0;    
    vector<double> ndrez;
    int egzamrez;
};

void ndrezultatai(zmogus* studentas, int i)
{   
    int balas;
    string ndPaz = "s";
    cout << "Iveskite studento gauta pazymi: " << endl;
    while(ndPaz.length() != 0)
    {
        cin.clear();
        cin.sync();
        getline(cin, ndPaz);
        if(ndPaz.length() != 0)
        {
            balas = std::stoi(ndPaz);
            studentas[i].ndrez.push_back(balas);
            studentas[i].n++;
        }
    }
}

double getVidurkis(int zmoniuskaic, zmogus* studentas, int i)
{
    if(studentas[i].n > 0)
    {
        double avrg = 0;    
        for(int j = 0; j < studentas[i].n; j++)
        {
            avrg += studentas[i].ndrez[j];
        }
        avrg = ((avrg / studentas[i].n)*0.4)+(studentas[i].egzamrez * 0.6);
        return avrg; 
    }
    else
    {
        double egzam;
        egzam = (studentas[i].egzamrez * 0.6);
        return egzam;
    }      
}

double getMediana(int zmoniuskaic, zmogus* studentas, int i)
{
    double med;
    if(studentas[i].n > 0)
    {
        std::sort(studentas[i].ndrez.begin(), studentas[i].ndrez.end());
        if ((studentas[i].n % 2) == 0)
        {
            med = (((studentas[i].ndrez[studentas[i].n / 2 - 1]) + studentas[i].ndrez[(studentas[i].n) / 2]) / 2) * 0.4 + (0.6 * studentas[i].egzamrez);
            return med;
        }
        else
        {
            med = (studentas[i].ndrez[studentas[i].n / 2] * 0.4) + (0.6 * studentas[i].egzamrez); 
            return med;
        }
    }
    else
    {
        med = (0.6 * studentas[i].egzamrez);
        return med;
    }    
}

void atsRibojimas(char& ats)
{
    while(true)
    {
        cin >> ats;
        if(ats == 'Y' || ats == 'y' || ats == 'N' || ats == 'n')
        {
            break;
        }    
        else
        {
            cout << "Iveskite viena is nurodytu reiksmiu: "<< endl;
        }
    }
}

void ivedimas(int zmoniuskaic, zmogus* studentas)
{   
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(1,10);
        
    for(int i = 0; i < zmoniuskaic; i++)
    {
        cout << "Iveskite studento varda: " << endl;
        cin >> studentas[i].vardas;
        cout << "Iveskite studento pavarde: " << endl;
        cin >> studentas[i].pavarde;
        cout << "Ar zinote pazymiu skaiciu?: y/n (y-yes / n-no)" << endl;
        char ats;
        char ats2;
        atsRibojimas(ats);
        if(ats == 'Y' || ats == 'y')
        {
            cout << "Ar norite sugeneruoti skaicius atsitiktinai?: y/n (y-yes / n-no)" << endl;
            atsRibojimas(ats2);
            if(ats2 == 'Y' || ats2 == 'y')
            {                
                cout << "Pazymiu skaicius: " << endl;
                cin >> studentas[i].n;
                for(int j = 0; j < studentas[i].n; j++)
                {
                    studentas[i].ndrez.push_back(distribution(generator));
                    cout<< "   " << studentas[i].ndrez[j] << endl;
                }
            }
            else 
            {           
                cout << "Pazymiu skaicius: " << endl;
                cin >> studentas[i].n;
                cout << "Iveskite studento pazymius: " << endl;
                for(int j = 0; j < studentas[i].n; j++)
                {
                    int balas;
                    cin >> balas;
                    studentas[i].ndrez.push_back(balas);
                }                
            }
        }
        else
        {
            ndrezultatai(studentas, i);
        }
        cout << "Ar norite sugeneruoti egzamino rezultata atsistiktinai?: y/n (y-yes / n-no)" <<endl;
        atsRibojimas(ats2);
        if(ats2 == 'Y' || ats2 == 'y')
        {
            studentas[i].egzamrez = (rand() % 10) + 1;
            cout << "Sugeneruotas balas: "<< studentas[i].egzamrez << endl;
        }
        else
        {
            cout << "Iveskite studento gauta egzamino bala: " <<endl;
            cin >> studentas[i].egzamrez;
        }           
    }
}

void isvedimas(int zmoniuskaic, zmogus* studentas)
{
    cout << "Ar vietoj vidurkio skaiciuoti mediana?: y/n (y-yes / n-no)" << endl;
    char ats;
    cin >> ats;
    if(ats == 'Y' || ats == 'y')
    {
        cout << "Vardas" << std::setw(12) << "Pavarde" << std::setw(20) << "Galutinis (Med.)" << endl;
        cout << "------------------------------------------" << endl;
        for(int i = 0; i < zmoniuskaic; i++)
        {
            cout << studentas[i].vardas << setw(11 - studentas[i].vardas.length() + studentas[i].pavarde.length()) 
            << studentas[i].pavarde << setw(13 - studentas[i].pavarde.length() + 3) << std::setprecision(2) << getMediana(zmoniuskaic, studentas, i) << endl;
            studentas[i].ndrez.clear();              
        }
        cout << "..." <<endl;
    }

    else
    {
        cout << "Vardas" << std::setw(12) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << endl;
        cout << "------------------------------------------" << endl;
        for(int i = 0; i < zmoniuskaic; i++)
        {
            cout << studentas[i].vardas << setw(11 - studentas[i].vardas.length() + studentas[i].pavarde.length()) 
            << studentas[i].pavarde << setw(13 - studentas[i].pavarde.length() + 3) << std::setprecision(2) << getVidurkis(zmoniuskaic, studentas, i) << endl;
            studentas[i].ndrez.clear();          
        }
        cout << "..." << endl;
    }
}

void isvedimasFailo(vector<StudentasFailo> studentas)
{   
    ofstream out_file ("kursiokaiOut.txt");
    
    out_file << "Vardas" << setw(10+7) << "Pavarde" << setw(10+15) << "Galutinis (med.)" << setw(5+15) << "Galutinis (vid.)" 
    << endl << "------------------------------------------------------------------------------" << endl;
    for(int i =0 ; i < studentas.size(); i++)
    {
        out_file << studentas[i].Vardas << setw(16-studentas[i].Vardas.length()+studentas[i].Pavarde.length()) << studentas[i].Pavarde 
        << setw(18-studentas[i].Pavarde.length()+3) << fixed << setprecision(2) << studentas[i].galutinisVidurkis
        << setw(20-3+3) << fixed << setprecision(2) << studentas[i].galutinisMediana << endl;
    }
}

void skaitymasIsFailo()
{
    auto start = std::chrono::high_resolution_clock::now();
    vector<StudentasFailo> Studentai;
        
    string failoString;
    fstream duomenys;
    duomenys.open("kursiokai100000.txt");
    string buffString;

    stringstream my_buffer;

    my_buffer << duomenys.rdbuf();
    //cout << my_buffer.str();
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

int main()
{
    char ats;
    cout << "Ar norite rasyti savo duomenis?: y/n (y-yes / n-no)" << endl;
    atsRibojimas(ats);
    if(ats == 'Y' || ats == 'y')
    {
        int zmoniuskaic;
        cout << "Iveskite studentu skaiciu: " << endl;
        cin >> zmoniuskaic;
        zmogus* studentas = new zmogus[zmoniuskaic];
        ivedimas(zmoniuskaic, studentas);
        isvedimas(zmoniuskaic, studentas);
    }
    else
    skaitymasIsFailo();
    
    return 0;
}
