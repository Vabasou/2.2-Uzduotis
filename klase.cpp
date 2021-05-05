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

Studentas::Studentas() //konstruktorius
{
    this->vardas = "";
    this->pavarde = "";
    this->finalVid = 0;
    this->finalMed = 0;
    this->egzamRez = 0;
}

Studentas::Studentas(const Studentas& other) //copy konstruktorius
{
    this->vardas = other.vardas;
    this->pavarde = other.pavarde;
    this->finalVid = other.finalVid;
    this->finalMed = other.finalMed;
}

Studentas::~Studentas() {} //destruktorius

Studentas Studentas::operator=(const Studentas& other) //priskyrimo operatorius
{
    this->vardas = other.vardas;
    this->pavarde = other.pavarde;
    this->finalVid = other.finalVid;
    this->finalMed = other.finalMed;

    return *this;
}

//set'eriai
void Zmogus::setVardas(std::string vardas) {this->vardas = vardas;};
void Zmogus::setPavarde(std::string pavarde){this->pavarde = pavarde;};

//get'eriai
const std::string Zmogus::getVardas() {return vardas;};
const std::string Zmogus::getPavarde() {return pavarde;};

//set'eriai
void Studentas::setPazymiai(std::vector<double> ndRez) 
{
    finalVid = getVidurkisFailas(ndRez);
    finalMed= getMedianaFailas(ndRez);
};
void Studentas::setEgzamRez(int egzamRez) {this->egzamRez = egzamRez;};

//get'eriai
const double Studentas::getVidurkis() {return finalVid;};
const double Studentas::getMediana() {return finalMed;};
const int Studentas::getEgzamRez() {return egzamRez;};

bool Studentas::operator < (Studentas &stud) const
{
    return (finalVid < stud.finalVid);
}

//struktura
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