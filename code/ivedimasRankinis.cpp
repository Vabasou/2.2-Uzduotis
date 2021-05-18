#include "libraries.hpp"
#include "ivedimasRankinis.hpp"
#include "klase.hpp"

class RandInt {
  public:
    RandInt(int low, int high) : mt{rd()}, dist{low, high} { }
    int operator()() { return dist(mt); }
  private:
    std::random_device rd;
    std::mt19937 mt;
    std::uniform_int_distribution<int> dist;
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

void isvedimasRank(int studSkaic, StudentasFailo* studentas)
{
    cout << "Vardas" << setw(10+7) << "Pavarde" << setw(10+15) << "Galutinis (med.)" << setw(5+15) << "Galutinis (vid.)" 
    << endl << "------------------------------------------------------------------------------" << endl;
    for(int i =0 ; i < studSkaic; i++)
    {
        cout << studentas[i].Vardas << setw(16-studentas[i].Vardas.length()+studentas[i].Pavarde.length()) << studentas[i].Pavarde 
        << setw(18-studentas[i].Pavarde.length()+3) << fixed << setprecision(2) << studentas[i].galutinisMediana
        << setw(20-3+3) << fixed << setprecision(2) << studentas[i].galutinisVidurkis << endl;
    }
}

void ndRez(StudentasFailo* studentas, int i)
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
            studentas[i].ndRez.push_back(balas);
            studentas[i].pazymiuSkaic++;
        }
    }
}

void ivestis()
{
    RandInt rnd {1, 10};

    int studKiek, pazKiek;

    cout << "Iveskite studentu skaiciu: " << endl;
    cin >> studKiek;

    StudentasFailo studentas[1000];

    for(int i = 0; i < studKiek; i++)
    {
        vector<double> pazymiai;
        cout << "Iveskite studento varda: " << endl;
        cin >> studentas[i].Vardas;
        cout << "Iveskite studento pavarde: " << endl;
        cin >> studentas[i].Pavarde;
        cout << "Ar zinote pazymiu skaiciu?: y/n (y-yes / n-no)" << endl;
        char ats;
        char ats2;
        atsRibojimas(ats);
        if(ats == 'Y' || ats == 'y')
        {
            cout << "Ar norite sugeneruoti pazymius atsitiktinai?: y/n (y-yes / n-no)" << endl;
            atsRibojimas(ats2);
            if(ats2 == 'Y' || ats2 == 'y')
            {                
                cout << "Pazymiu skaicius: " << endl;
                cin >> studentas[i].pazymiuSkaic;
                for(int j = 0; j < studentas[i].pazymiuSkaic; j++)
                {
                    studentas[i].ndRez.push_back(rnd());
                    cout<< "   " << studentas[i].ndRez[j] << endl;
                }
            }
            else 
            {           
                cout << "Pazymiu skaicius: " << endl;
                cin >> studentas[i].pazymiuSkaic;
                cout << "Iveskite studento pazymius: " << endl;
                for(int j = 0; j < studentas[i].pazymiuSkaic; j++)
                {
                    int balas;
                    cin >> balas;
                    studentas[i].ndRez.push_back(balas);
                }                
            }
        }
        else
        {
            ndRez(studentas, i);
        }
        cout << "Ar norite sugeneruoti egzamino rezultata atsistiktinai?: y/n (y-yes / n-no)" <<endl;
        atsRibojimas(ats2);
        if(ats2 == 'Y' || ats2 == 'y')
        {
            studentas[i].egzamRez = (rand() % 10) + 1;
            cout << "Sugeneruotas balas: "<< studentas[i].egzamRez << endl;
        }
        else
        {
            cout << "Iveskite studento gauta egzamino bala: " <<endl;
            cin >> studentas[i].egzamRez;
        }
        studentas[i].galutinisPazymys(studentas[i].ndRez, studentas[i].egzamRez);
        studentas[i].ndRez.clear();
    }
    isvedimasRank(studKiek, studentas);
}