# Antrosios uzduoties pirma versija

Galimybės:
* ši versija leidžia suvesti norimą studentų kiekį; 
* kiekvienam studentui galima pridėti norimą kiekį namų darbų pažymių (nesvarbu ar iš anksto žinote jų skaičių ar ne);
* taip pat yra privaloma pridėti egzamino balą;
* yra galimybė namų darbų rezultatus ir egzamino balą sugeneruoti atsitiktinai;
* galiausiai ši programa jums pateikia studentų galutinį vidurkį arba medianą.

Įdiegimo instrukcija:
* parsisiunčiate šį failą, kuriame rasite du skirtingus .cpp dokumentus (jie yra vienodi, tik vienas atliktas su vektoriais);
* ir šiuos failus leidžiate su pasirinkta programa, kuri paleižia c++ failus;
* jei neturite tokios programos, ar nežinote kaip tai atlikti, čia yra [nuoroda](https://code.visualstudio.com/docs/languages/cpp).

Naudotos formulės:
* Vidurkio
```double avrg = 0;    
        for(int j = 0; j < studentas[i].n; j++)
        {
            avrg += studentas[i].ndrez[j];
        }
        avrg = ((avrg / studentas[i].n)*0.4)+(studentas[i].egzamrez * 0.6);
        return avrg;
 ```       
* Medianos:
```std::sort(studentas[i].ndrez.begin(), studentas[i].ndrez.end());
        if ((studentas[i].n % 2) == 0)
        {
            med = (((studentas[i].ndrez[studentas[i].n / 2 - 1]) + studentas[i].ndrez[(studentas[i].n) / 2]) / 2) * 0.4 + (0.6 * studentas[i].egzamrez);
            return med;
        }
        else
        {
            med = (studentas[i].ndrez[studentas[i].n / 2] * 0.4) + (0.6 * studentas[i].egzamrez); 
            return med;
        }
        ```
