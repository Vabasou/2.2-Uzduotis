#ifndef IVEDIMAS_RANKINIS_HPP
#define IVEDIMAS_RANKINIS_HPP

#include "libraries.hpp"

struct zmogus
{
    string vardas, pavarde;
    int n = 0;    
    vector<double> ndrez;
    int egzamrez;
};

double getVidurkis(zmogus* studentas, int i);
double getMediana(zmogus* studentas, int i);
void atsRibojimas(char& ats);
void ivedimas(int zmoniuskaic, zmogus* studentas);
void isvedimas(int zmoniuskaic, zmogus* studentas);

#endif