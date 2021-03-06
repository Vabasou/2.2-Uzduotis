#include "libraries.hpp"
#include "ivedimasRankinis.hpp"

int main()
{
    int zmoniuskaic;
    cout << "Iveskite studentu skaiciu: " << endl;
    cin >> zmoniuskaic;
    zmogus* studentas = new zmogus[zmoniuskaic];
    ivedimas(zmoniuskaic, studentas);
    isvedimas(zmoniuskaic, studentas);
}