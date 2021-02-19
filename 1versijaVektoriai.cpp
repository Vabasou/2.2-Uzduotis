#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::setw;

struct zmogus
{
    string vardas, pavarde;
    int n;    
    vector<double> ndrez;
    int egzamrez;

};

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

void ndrezultatai(zmogus* studentas, int kartai, int i)
{   
    int balas;
    cout << "Iveskite studento gauta pazymi: " << endl;
    cin >> balas;
    studentas[i].ndrez.push_back(balas);
    cout << "Ar norite prideti dar viena pazymi?: y/n (y-yes / n-no)" << endl;
    char ats1;
    atsRibojimas(ats1);
    if(ats1 == 'Y' || ats1 == 'y')
    {
        kartai++;
        ndrezultatai(studentas, kartai, i);
    }
    else
    {
        studentas[i].n = kartai++;
    }
}

void ivedimas(int zmoniuskaic, zmogus* studentas)
{   
    srand(time(NULL));
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
                    studentas[i].ndrez.push_back((rand() % 10) + 1);
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
            int kartai = 0;
            ndrezultatai(studentas, kartai, i);
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
        }
        cout << "..." <<endl;
    }

    else
    {
        cout << "Vardas " << "        Pavarde " << "     Galutinis (Vid.)" << endl;
        cout << "------------------------------------------" << endl;
        for(int i = 0; i < zmoniuskaic; i++)
        {
            cout << studentas[i].vardas << setw(11 - studentas[i].vardas.length() + studentas[i].pavarde.length()) 
            << studentas[i].pavarde << setw(13 - studentas[i].pavarde.length() + 3) << std::setprecision(2) << getVidurkis(zmoniuskaic, studentas, i) << endl;              
        }
        cout << "..." << endl;
    }
}

int main()
{
    int zmoniuskaic;
    cout << "Iveskite studentu skaiciu: " << endl;
    cin >> zmoniuskaic;
    zmogus* studentas = new zmogus[zmoniuskaic];
    ivedimas(zmoniuskaic, studentas);
    isvedimas(zmoniuskaic, studentas);
    
    
    
    return 0;
}