#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>

using std::cout;
using std::cin;
using std::string;
using std::endl;

struct zmogus
{
    string vardas, pavarde;
    int n;    
    int* ndrez = new int[n];
    int egzamrez;

};

void atsRibojimas(char& ats)
{
    while (true)
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
    cout << "Iveskite studento gauta pazymi: " << endl;
    cin >> studentas[i].ndrez[kartai];
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
            if(ats2 == 'Y' || ats == 'y')
            {                
                cout << "Pazymiu skaicius: " << endl;
                cin >> studentas[i].n;
                for(int j = 0; j < studentas[i].n; j++)
                {
                    studentas[i].ndrez[j] = (rand() % 10) + 1;
                    cout<< "   " << studentas[i].ndrez[j] << endl;
                }
            }
            else 
            {           
                cout << "Pazymiu skaicius: " << endl;
                cin >> studentas[i].n;
                cout << "Iveskite studento pazymius: " << endl;
                for(int j = 0; j < studentas[i].n; j++)
                cin >> studentas[i].ndrez[j];
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
        std::sort(studentas[i].ndrez, studentas[i].ndrez + studentas[i].n);
        if ((studentas[i].n % 2) == 0)
        {
            med = (((studentas[i].ndrez[studentas[i].n / 2 - 1]) + studentas[i].ndrez[(studentas[i].n) / 2]) / 2) * 0.4 + (0.6 * studentas[i].egzamrez);
        }
        else
        {
            med = (studentas[i].ndrez[studentas[i].n / 2] * 0.4) + (0.6 * studentas[i].egzamrez); 
        }
        return med;
    }
    else
    {
        med = (0.6 * studentas[i].egzamrez);
        return med;
    }
}

void isvedimas(int zmoniuskaic, zmogus* studentas, int i)
{
    cout << "Ar vietoj vidurkio skaiciuoti mediana?: y/n (y-yes / n-no)" << endl;
    char ats;
    cin >> ats;
    if(ats == 'Y' || ats == 'y')
    {
        for(int i = 0; i < zmoniuskaic; i++)
        {
            cout << studentas[i].vardas << " " << studentas[i].pavarde << " " << std::setprecision(3) << getMediana(zmoniuskaic, studentas, i) << endl;
        }
    }
    else
    {
        for(int i = 0; i < zmoniuskaic; i++)
        {
            cout << studentas[i].vardas << " " << studentas[i].pavarde << " " << std::setprecision(3) << getVidurkis(zmoniuskaic, studentas, i) << endl;
        }
    }
}

int main()
{
    int zmoniuskaic = 100000000;
    cout << "Iveskite studentu skaiciu: " << endl;
    cin >> zmoniuskaic;
    zmogus* studentas = new zmogus[zmoniuskaic];
    for(int i = 0; i < zmoniuskaic; i++)
    {
        ivedimas(zmoniuskaic, studentas);
        isvedimas(zmoniuskaic, studentas, i);
    }
    
    
    return 0;
}