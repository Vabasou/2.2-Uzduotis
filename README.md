# Antrosios užduoties 1.0 versija

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
* programa pateikia jos įvairių funkcijų laiko trukmę;
* patikrina skaitymo ir rūšiavimo grečių skirtumus, tarp std::vector, std::list, std::deque.

### v1.0 privalumai
- patikrina skaitymo ir rūšiavimo grečių skirtumus, tarp std::vector, std::list, std::deque taikant skirtingas stretegijas

### laukų skirtumai, naudojant naujus konteinerius
kompiuterio komponentai: i5-6400 2.70GHz, DDR4 16GB 2900MHz, WDC WD10EZEX 1TB HDD

std::vector

| Dydis    | Nuskaitymas | Rūšiavimas | Laikas su išvedimu |
|----------|-------------|------------|--------------------|
| 1000     | 0.072s      | 0.001s     | 0.15s              |
| 10000    | 0.423s      | 0.018s     | 0.554s             |
| 100000   | 4.691s      | 0.223s     | 5.42s              |
| 1000000  | 52.745s     | 0.397s     | 60.524s            |
| 10000000 | 543.926s    | 3.42s      | 622.249s           |

std::list

| Dydis    | Nuskaitymas | Rūšiavimas | Laikas su išvedimu |
|----------|-------------|------------|--------------------|
| 1000     | 0.055s      | 0.012s     | 0.069s             |
| 10000    | 0.712s      | 0.006s     | 0.831s             |
| 100000   | 5.1s        | 0.039s     | 5.867s             |
| 1000000  | 51.469s     | 7.744s     | 59.503s            |
| 10000000 | 534.789s    | 80.216s    | 618.154s           |

std::deque

| Dydis    | Nuskaitymas | Rūšiavimas | Laikas su išvedimu |
|----------|-------------|------------|--------------------|
| 1000     | 0.059s      | 0.01s      | 0.077s             |
| 10000    | 0.592s      | 0.09s      | 0.692s             |
| 100000   | 4.994s      | 0.747s     | 5.775s             |
| 1000000  | 50.661s     | 7.682s     | 58.576s            |
| 10000000 | 544.596s    | 83.12      | 630.427s           |

![Screenshot 2021-04-14 140230](https://user-images.githubusercontent.com/75567390/114703647-3baa3900-9d2e-11eb-9ccf-0cc4579d70cd.png)

### laikų skirtumai, naudojant senus ir naujus konteinerius
kompiuterio komponentai: i5-6400 2.70GHz, DDR4 16GB 2900MHz, WDC WD10EZEX 1TB HDD

std::vector

| Dydis    | Nuskaitymas | Rūšiavimas | Laikas su išvedimu |
|----------|-------------|------------|--------------------|
| 1000     | 0.047s      | 0.002s     | 0.07s              |
| 10000    | 0.569s      | 0.105s     | 0.685s             |
| 100000   | 4.998s      | 0.737s     | 5.763s             |
| 1000000  | 42.124s     | 2.779s     | 54.388s            |
| 10000000 | 421.289s    | 34.458s    | 562.077s           |

std::list

| Dydis    | Nuskaitymas | Rūšiavimas | Laikas su išvedimu |
|----------|-------------|------------|--------------------|
| 1000     | 0.045s      | 0.0009s    | 0.06s              |
| 10000    | 0.448s      | 0.009s     | 0.537s             |
| 100000   | 4.314s      | 0.133s     | 5.395s             |
| 1000000  | 41.613s     | 1.316s     | 51.37s             |
| 10000000 | 414.377s    | 17.226s    | 513.636s           |

std::deque

| Dydis    | Nuskaitymas | Rūšiavimas | Laikas su išvedimu |
|----------|-------------|------------|--------------------|
| 1000     | 0.045s      | 0.002s     | 0.06s              |
| 10000    | 0.429s      | 0.023s     | 0.545s             |
| 100000   | 4.319s      | 0.272s     | 5.311s             |
| 1000000  | 41.616s     | 3.340s     | 55.58s             |
| 10000000 | 419.74s     | 41.356     | 594.766s           |

![Screenshot 2021-04-14 124319](https://user-images.githubusercontent.com/75567390/114703658-3fd65680-9d2e-11eb-8e84-2b33169c340e.png)

![Screenshot 2021-04-14 140230](https://user-images.githubusercontent.com/75567390/114703647-3baa3900-9d2e-11eb-9ccf-0cc4579d70cd.png)

### programos veikimo ,naudojant vektorių ir rūšiavimą išvedimo metu, laikai
rezultatai pateikiami skaičiuojant su 10 namų darbų pažymių.

| Dydis    | Failo generavimas | Nuskaitymas | Rūšiavimas | Išvedimas |
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
Šį failą galite paleisti per windows su komanda
```mingw32-make <norima komanda>```  

Šį failą galite paleisti per linux arba iOS su komanda
```make <norima komanda>```
        
