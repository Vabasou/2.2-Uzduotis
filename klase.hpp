#pragma once
#include <string>
#include <vector>

class Studentas
{
    private:
        std::string vardas, pavarde;
        double finalMed, finalVid;

    public:
        void galutinisPazymys(std::vector<double> &pazymys, double egzamRez);

        void setVardas(std::string vardas);
        void setPavarde(std::string pavarde);
        void setPazymiai(std::vector<double> ndRez);

        const std::string getVardas();
        const std::string getPavarde();
        const double getVidurkis();
        const double getMediana();

        bool operator < (Studentas &stud) const;
};

struct StudentasFailo
{
    std::string Vardas, Pavarde;
    double galutinisVidurkis, galutinisMediana;

    int pazymiuSkaic;
    std::vector<double> ndRez;
    int egzamRez;

    void galutinisPazymys(std::vector<double> &pazymys, double egzamRez);

    bool operator < (StudentasFailo &stud) const;
};