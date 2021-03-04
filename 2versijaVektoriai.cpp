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

// FILE* open_file;
// FILE* out_file;

struct zmogus
{
    string vardas, pavarde;
    int n = 0;    
    vector<double> ndrez;
    int egzamrez;
};

struct stud_buff
{
    string vardas, pavarde;
    vector<double> ndRez;
    int egzamRez;

    bool operator < (const stud_buff &stud) const
    {
        return vardas.compare(stud.vardas) < 0;
    }
};
//const string inFile[] = "kursiokai.txt";
//const string outFile[] = "kursiokaiOut.txt";

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

double getVidurkisFailas(vector<stud_buff> studentas, int i)
{
    if(studentas[i].ndRez.size() > 0)
    {
        double avrg = 0;    
        for(int j = 0; j < studentas[i].ndRez.size(); j++)
        {
            avrg += studentas[i].ndRez[j];
        }
        avrg = ((avrg / studentas[i].ndRez.size())*0.4)+(studentas[i].egzamRez * 0.6);
        return avrg; 
    }
    else
    {
        double egzam;
        egzam = (studentas[i].egzamRez * 0.6);
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

double getMedianaFailas(vector<stud_buff> studentas, int i)
{
    double med;
    if(studentas[i].ndRez.size() > 0)
    {
        sort(studentas[i].ndRez.begin(), studentas[i].ndRez.end());
        if ((studentas[i].ndRez.size() % 2) == 0)
        {
            med = (((studentas[i].ndRez[studentas[i].ndRez.size() / 2 - 1]) + studentas[i].ndRez[(studentas[i].ndRez.size()) / 2]) / 2) * 0.4 + (0.6 * studentas[i].egzamRez);
            return med;
        }
        else
        {
            med = (studentas[i].ndRez[studentas[i].ndRez.size() / 2] * 0.4) + (0.6 * studentas[i].egzamRez); 
            return med;
        }
    }
    else
    {
        med = (0.6 * studentas[i].egzamRez);
        return med;
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

void isvedimasFailo(vector<stud_buff> studentas)
{   
    ofstream out_file ("kursiokaiOut.txt");
    
    out_file << "Vardas" << setw(10+7) << "Pavarde" << setw(10+15) << "Vidurkis (med.)" << setw(5+15) << "Vidurkis (vid.)" 
    << endl << "------------------------------------------------------------------------------" << endl;
    for(int i =0 ; i < studentas.size(); i++)
    {
        out_file << studentas[i].vardas << setw(16-studentas[i].vardas.length()+studentas[i].pavarde.length()) << studentas[i].pavarde 
        << setw(18-studentas[i].pavarde.length()+3) << fixed << setprecision(2) << getVidurkisFailas(studentas, i) 
        << setw(20-3+3) << fixed << setprecision(2) << getMedianaFailas(studentas, i) << endl;
    }
}

void skaitymas()
{
    auto start = std::chrono::high_resolution_clock::now();
    vector<stud_buff> studentas;
    int vardoIlgis;
    int pavardesIlgis;
    int studentuSkaicius = 0;
    int ndSkaicius = 0;

    string failoString;
    fstream duomenys;
    duomenys.open("kursiokai.txt");

    while (!duomenys.eof())
    {
        string buffEil;
        getline(duomenys, buffEil);
        buffEil.append("\n");
        failoString += buffEil;
    }

    duomenys.close();

    stringstream fileStream(failoString);

    getline(fileStream, failoString);
    
    while(!fileStream.eof())
    {
        string eil;
        getline(fileStream, eil);
        studentuSkaicius++;
        if(fileStream.eof()) break;

        stringstream lineStream(eil);

        vector<double> pazymiai;
        stud_buff studDuomenys;
        double egzamRez;

        lineStream >> studDuomenys.vardas >> studDuomenys.pavarde;

        while (!lineStream.eof())
        {
            double rezultatai;
            lineStream >> rezultatai;

            if(lineStream.eof())
            studDuomenys.egzamRez = rezultatai;
            else
            {
                studDuomenys.ndRez.push_back(rezultatai);
                ndSkaicius++;
            }       
        }
        
        pazymiai.clear();
        studentas.push_back(studDuomenys);
    }
    
    sort(studentas.begin(), studentas.end());

    isvedimasFailo(studentas);
    // ofstream out_file ("kursiokaiOut.txt");
    // for (int i = 0; i < studentas.size(); i++)
    // {
    //     out_file << studentas[i].vardas << " " << studentas[i].pavarde << " ";
    //     for(int j = 0; j < studentas[i].ndRez.size(); j++)
    //     {
    //         out_file << studentas[i].ndRez[j] << " ";
    //     }
    //     // out_file << studentas[i].egzamRez << endl;
    //     //out_file << std::setprecision(2) << getVidurkisFailas(studentas, i) << " ";
    //     //out_file << std::setprecision(2) << getMedianaFailas(studentas, i) << " ";
    //     out_file << endl;
    //     //out_file << studentas[i].egzamRez << endl;
    // }
    studentas.clear();
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
    skaitymas();
    
    return 0;
}
