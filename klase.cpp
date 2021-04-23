#include <string>
#include <vector>
#include <algorithm>
#include "klase.hpp"

double getVidurkisFailas(std::vector<double> &pazymiai){
    double sum = 0;

    for(int i = 0; i<pazymiai.size(); i++)
    {
        sum += pazymiai[i];
    }

    return sum/pazymiai.size();
}

double getMedianaFailas(std::vector<double> &pazymiai)
{
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

void Studentas::galutinisPazymys(std::vector<double> &pazymys, double egzamRez)
{
    egzamRez *= 0.6;
    finalVid = ((getVidurkisFailas(pazymys) * 0.4) + egzamRez);
    finalMed = ((getMedianaFailas(pazymys) * 0.4) + egzamRez);
}

void Studentas::setVardas(std::string vardas) {this->vardas = vardas;};
void Studentas::setPavarde(std::string pavarde){this->pavarde = pavarde;};
void Studentas::setPazymiai(std::vector<double> ndRez) 
{
    finalVid = getVidurkisFailas(ndRez);
    finalMed= getMedianaFailas(ndRez);
};

const std::string Studentas::getVardas() {return vardas;};
const std::string Studentas::getPavarde() {return pavarde;};
const double Studentas::getVidurkis() {return finalVid;};
const double Studentas::getMediana() {return finalMed;};

bool Studentas::operator < (Studentas &stud) const
{
    return (finalVid < stud.finalVid);
}

void StudentasFailo::galutinisPazymys(std::vector<double> &pazymys, double egzamRez)
{
    egzamRez *= 0.6;
    galutinisVidurkis = ((getVidurkisFailas(pazymys) * 0.4) + egzamRez);
    galutinisMediana = ((getMedianaFailas(pazymys) * 0.4) + egzamRez);
}

bool StudentasFailo::operator < (StudentasFailo &stud) const
{
    return (Vardas < stud.Vardas);
}