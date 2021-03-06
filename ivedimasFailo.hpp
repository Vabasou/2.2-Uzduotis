#ifndef IVEDIMASFAILO_HPP
#define IVEDIMASFAILO_HPP

#include "libraries.hpp"

struct StudentasFailo{
    string Vardas, Pavarde;
    double galutinisVidurkis, galutinisMediana;

    void galutinisPazymys(vector<double> &grades, double egzamRez);

    bool operator < (StudentasFailo &stud) const;
};

double getVidurkisFailas(vector<double> &pazymiai);
double getMedianaFailas(vector<double> &pazymiai);
void isvedimasFailo(vector<StudentasFailo> studentas);
void skaitymasIsFailo();

#endif