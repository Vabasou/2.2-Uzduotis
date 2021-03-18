#include "libraries.hpp"
#include "strukturos.hpp"
#include "funkcijos.hpp"

void StudentasFailo::galutinisPazymys(vector<double> &pazymys, double egzamRez)
{
    egzamRez *= 0.6;
    galutinisVidurkis = ((getVidurkisFailas(pazymys) * 0.4) + egzamRez);
    galutinisMediana = ((getMedianaFailas(pazymys) * 0.4) + egzamRez);
}

bool StudentasFailo::operator < (StudentasFailo &stud) const
{
    return (Vardas < stud.Vardas);
}
