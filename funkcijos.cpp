#include "libraries.hpp"
#include "strukturos.hpp"
#include "funkcijos.hpp"

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

    if (pazymiai.size() == 0)
    {
        return 0;
    }  
    else
    {
        sort(pazymiai.begin(), pazymiai.end());
        if (pazymiai.size() % 2 == 0)
        {
            return (pazymiai[pazymiai.size() / 2 - 1] + pazymiai[pazymiai.size() / 2]) / 2;
        }
        else
        {
            return pazymiai[pazymiai.size() / 2];
        }
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