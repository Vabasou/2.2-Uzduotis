#pragma once
#include <string>
#include <vector>

class Zmogus
{
    protected:
        std::string vardas;
        std::string pavarde;
    public:
        //get'eriai
        virtual const std::string getVardas();
        virtual const std::string getPavarde();

        //set'eriai
        void setVardas(std::string vardas);
        void setPavarde(std::string pavarde);

        virtual void print() = 0;
};

class Studentas : public Zmogus
{
    private:
        double finalMed, finalVid;
        std::vector<double> ndRez;
        double egzamRez;

    public:
        Studentas();
        Studentas(const Studentas&); //copy konstruktorius
        ~Studentas(); //destruktorius
        Studentas operator=(const Studentas& other); //priskyrimo operatorius

        void galutinisPazymys(std::vector<double> &pazymys, double egzamRez);

        //set'eriai
        void setPazymiai(std::vector<double> ndRez);
        void setEgzamRez(int egzamRez);

        //get'eriai
        const double getVidurkis();
        const double getMediana();
        const int getEgzamRez();

        //sort
        bool operator < (Studentas &stud) const;

        void print() override{};
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