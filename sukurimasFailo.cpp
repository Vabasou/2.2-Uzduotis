#include "libraries.hpp"
#include "strukturos.hpp"

const string vardai[13] = {"Sofija", "Vytautas", "Ignas", "Paulius", "Tomas", "Algirdas", "Naglis", "Deividas", "Matas", "Amelija", "Gabija", "Emilija", "Luka"};
const string pavardes[13] = {"Vroom", "Ikea", "Akropilis", "Maxima", "Bridgestone", "Michellin", "Coral", "Cube", "Circle", "End", "Kompot", "Cipak", "Kwinkvin"};

class RandInt {
  public:
    RandInt(int low, int high) : mt{rd()}, dist{low, high} { }
    int operator()() { return dist(mt); }
  private:
    std::random_device rd;
    std::mt19937 mt;
    std::uniform_int_distribution<int> dist;
};

void outputas(vector<StudentasFailo> &a)
{   
  ofstream out_file ("studentai.txt"); 
  out_file << "Vardas" << setw(10+7) << "Pavarde" << setw(10+7) 
  << "ND1 " << "ND2 " << "ND3 " << "ND4 " << "ND5 " << "ND6 " << "ND7 " << "ND8 " << "ND9 " << "ND10 " << "EGZR" << endl;
  for(int i =0 ; i < a.size(); i++)
  {
    out_file << a[i].Vardas<< setw(16-a[i].Vardas.length()+a[i].Pavarde.length())<< a[i].Pavarde << setw(18-a[i].Pavarde.length()+3);
    for(int j = 0; j < a[i].ndRez.size(); j++)
    {
      out_file << a[i].ndRez[j] << setw(4);
    } 
    out_file << " " << a[i].egzamRez;
    out_file << endl;
  }
  out_file.close();
}

void sukurimasFailo()
{
  RandInt rnd {1, 10};
  RandInt rnz {0, 12};

  int zmoniuSkaic = 0;
  int pasirinkimas;
  cout << "Kiek zmoniu sugeneruoti?" << endl;
  cout << "1. 1 000" << endl;
  cout << "2. 10 000" << endl;
  cout << "3. 100 000" << endl;
  cout << "4. 1 000 000" << endl;
  cout << "5. 10 000 000" << endl;
  cin >> pasirinkimas;

  if(pasirinkimas == 1) zmoniuSkaic = 1000;
  if(pasirinkimas == 2) zmoniuSkaic = 10000;
  if(pasirinkimas == 3) zmoniuSkaic = 100000;
  if(pasirinkimas == 4) zmoniuSkaic = 1000000;
  if(pasirinkimas == 5) zmoniuSkaic = 10000000;
  if(pasirinkimas < 1 || pasirinkimas > 5)
  {
    cout << "Ivedete bloga reiksme" << endl;
    cin.clear();
    cin.ignore(10000, '\n');
  }
   
  std::chrono::time_point<std::chrono::high_resolution_clock> start_input, end_input;
  start_input = std::chrono::high_resolution_clock::now();

  vector <StudentasFailo> a;
  StudentasFailo studentas;
  for(int i = 0; i < zmoniuSkaic; i++)
  {
    double vid, med;
    double suma = 0;
    for(int j = 0; j < 10; j++)
    {
      studentas.ndRez.push_back(rnd());
    }

    studentas.egzamRez = rnd();
    studentas.Vardas = vardai[rnz()];
    studentas.Pavarde = pavardes[rnz()];

    a.push_back(studentas);
    studentas.ndRez.clear();
  }
  sort(a.begin(), a.end());
  outputas(a);
  a.clear();
  end_input = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> input_duration = end_input - start_input;
  cout << "Failo sukurimas uztruko: " << input_duration.count() << "s" << endl;
  
}
