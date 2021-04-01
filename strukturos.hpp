#ifndef STRUKTUROS_HPP
#define STRUKTUROS_HPP

#include "libraries.hpp"

struct StudentasFailo
{
    string Vardas, Pavarde;
    double galutinisVidurkis, galutinisMediana;

    int pazymiuSkaic;
    vector<double> ndRez;
    int egzamRez;

    void galutinisPazymys(vector<double> &pazymys, double egzamRez);

    bool operator < (StudentasFailo &stud) const;
};

#endif