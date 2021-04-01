# Antrosios uzduoties ketvirta versija

### Galimybės:
* ši versija leidžia suvesti norimą studentų kiekį; 
* kiekvienam studentui galima pridėti norimą kiekį namų darbų pažymių (nesvarbu ar iš anksto žinote jų skaičių ar ne);
* taip pat yra privaloma pridėti egzamino balą;
* yra galimybė namų darbų rezultatus ir egzamino balą sugeneruoti atsitiktinai;
* galiausiai ši programa jums pateikia studentų galutinį vidurkį arba medianą;
* leidžia nuskaityti norimus failus su studentų rezultatais.
* yra apsauga, kuri įspėja, jeigu jūsų norimas nuskaityti failas neegzistuoja;
* taip pat, jeigu faile yra pažymiai, kurių reikšmė n>10 arba n<0, tada jūs esate įspėjami dėl netinkamo programos veikimo.
* galima generuoti savo studentų failus;
* rezultatai gali būti pateikiami į ```kursiokaiNoobai.txt```, kurių rezultatai yra <5 ir ```kursiokaiNiordai.txt```. kurių rezultatai yra >=5;
* programa pateikia jos įvairių funkcijų laiko trukmę.

### v0.5 privalumai
- patikrina skaitymo ir rūšiavimo grečių skirtumus, tarp std::vector, std::list, std::deque

### laikų skirtumai
kompiuterio komponentai: i5-6400 2.70GHz, DDR4 16GB 2900MHz, WDC WD10EZEX 1TB HDD

std::vector
| dydis    | Nuskaitymas | Rūšiavimas |
| 1000     | 0.047s      | 0.002s     |
| 10000    | 0.423s      | 0.018s     |
| 100000   | 4.691s      | 0.223s     |
| 1000000  | 42.124s     | 2.779s     |
| 10000000 | 

std::list
| dydis    | Nuskaitymas | Rūšiavimas |
| 1000     | 0.045s      | 0.0009s    |
| 10000    | 0.448s      | 0.009s     |
| 100000   | 4.314s      | 0.133s     |
| 1000000  | 41.613s     | 1.316s     |
| 10000000 | 

std::deque
| dydis    | Nuskaitymas | Rūšiavimas |
| 1000     | 0.045s      | 0.002s     |
| 10000    | 0.429s      | 0.023s     |
| 100000   | 4.319s      | 0.272s     |
| 1000000  | 41.616s     | 3.340s     |
| 10000000 | 

### programos veikimo ,naudojant vektorių ir rūšiavimą išvedimo metu, laikai
rezultatai pateikiami skaičiuojant su 10 namų darbų pažymių.

| dydis    | Failo generavimas | Nuskaitymas | Rūšiavimas | Išvedimas |
|----------|-------------------|-------------|------------|-----------|
| 1000     | 0.029s            | 0.049s      | 0.001s     | 0.02s     |
| 10000    | 0.155s            | 0.439s      | 0.017s     | 0.08s     | 
| 100000   | 1.547s            | 4.364s      | 0.218s     | 0.66s     |
| 1000000  | 15.764s           | 43.895s     | 2.892s     | 6.395s    |
| 10000000 | 157.145s          | 438.956s    | 21.512s    | 61.432s   |


Įdiegimo instrukcija:
* parsisiunčiate šį aplanką, kuriame rasite kelis .cpp failus;
* ir šiuos failus leidžiate su pasirinkta programa, kuri paleižia c++ failus;
* jei neturite tokios programos, ar nežinote kaip tai atlikti, čia yra [nuoroda](https://code.visualstudio.com/docs/languages/cpp).
* jūsų naudojimo palengvinimui yra padarytas makefile:
```
compile:
	g++ -c paleidimas.cpp funkcijos.cpp ivedimasFailo.cpp ivedimasRankinis.cpp strukturos.cpp sukurimasFailo.cpp
	g++ -o main paleidimas.o funkcijos.o ivedimasFailo.o ivedimasRankinis.o strukturos.o sukurimasFailo.o
clean:
	del *.o *.exe
```
Šį failą galite paleisti su komanda
```mingw32-make <norima komanda>```  
        
