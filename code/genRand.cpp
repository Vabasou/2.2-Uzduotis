#include "libraries.hpp"
#include "genRand.hpp"


const std::string vardai[13] = {"Sofija", "Vytautas", "Ignas", "Paulius", "Tomas", "Algirdas", "Naglis", "Deividas", "Matas", "Amelija", "Gabija", "Emilija", "Luka"};
const std::string pavardes[13] = {"Vroom", "Ikea", "Akropilis", "Maxima", "Bridgestone", "Michellin", "Coral", "Cube", "Circle", "End", "Kompot", "Cipak", "Kwinkvin"};

class RandInt{
    private:
        std::random_device rd;
        std::mt19937 mt;
        std::uniform_int_distribution<int> dist;

    public:
        RandInt(int low, int high) : mt{rd()}, dist{low,high} {}
        int operator ()() {return dist(mt);}
};

RandInt rnd{0, 10};
RandInt rnz {0, 12};

void generuoti()
{
  int studKiek = 0;
  int pasirinkimas;
  cout << "Kiek zmoniu sugeneruoti?" << endl;
  cout << "1. 1 000" << endl;
  cout << "2. 10 000" << endl;
  cout << "3. 100 000" << endl;
  cout << "4. 1 000 000" << endl;
  cout << "5. 10 000 000" << endl;
  cin >> pasirinkimas;

  if(pasirinkimas == 1) studKiek = 1000;
  if(pasirinkimas == 2) studKiek = 10000;
  if(pasirinkimas == 3) studKiek = 100000;
  if(pasirinkimas == 4) studKiek = 1000000;
  if(pasirinkimas == 5) studKiek = 10000000;
  if(pasirinkimas < 1 || pasirinkimas > 5)
  {
    cout << "Ivedete bloga reiksme" << endl;
    cin.clear();
    cin.ignore(10000, '\n');
  }
    std::string result;
    result = "Vardas    Pavarde   ND1 ND2 ..... \n";
    for(int i = 0; i < studKiek; i++)
    {
        std::string line;
        line.append(vardai[rnd()]);
        line.append(" ");
        line.append(pavardes[rnd()]);
        for(int j = 0; j < 5; j++)
        {
            line.append(" ");
            line.append(std::to_string(rnd()));
        }
        line.append("\n");
        result.append(line);
    }

    std::ofstream out;
    out.open("studentai.txt");
    out << result;
    out.close();
}
