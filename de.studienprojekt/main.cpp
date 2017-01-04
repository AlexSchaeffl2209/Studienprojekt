#include <iostream>

#define FILEPATHR "C:\\Users\\Alex-Pc\\Desktop\\lesen.txt"
#define FILEPATHW "C:\\Users\\Alex-Pc\\Desktop\\schreiben.txt"

using namespace std;

void readFile()
{
    FILE *fp;
    fp = fopen(FILEPATHR, "r");


    int size = 200;
    char buffer[size];
    double safe[size];

    if (fp == NULL)
    {
        printf("Datei konnte nicht geoeffnet werden!\n");
    }
    else
    {
        int i = 0;
        int countOfNumbers = 0;

        while (fscanf(fp, "%s", buffer) != EOF)
        {
            while (buffer[i] != '\0')   //Geht das Array durch bis er entweder am Ende der Zahl ist
            {
                safe[countOfNumbers] = 0.0;
                int j = i;
                int z = i;

                //Wenn eine Double Zahl gefunden wird
                if (buffer[i] == '.')
                {
                    unsigned long long x = 1;
                    while (j > 0)
                    {
                        safe[countOfNumbers] = safe[countOfNumbers] + ((buffer[j - 1] - '0') * (1 * x));  //Addiert die 1_er der Zahl + 10er_Stelle usw. in das Double_Array
                        j--;
                        x = x * 10;
                    }

                    unsigned long long a = 10;
                    while (buffer[z + 1] != '\0')
                    {
                        double test = (buffer[z + 1] - '0');
                        double tmp = test * (1.0 / a);

                        safe[countOfNumbers] = safe[countOfNumbers] + tmp;     //Addiert bei Double_Zahlen die Stellen nach dem '.' hinzu
                        z++;
                        a = a * 10;
                    }
                    break;
                }
                    //Wenn eine Int Zahl gefunden wird
                else if (buffer[i + 1] == '\0')
                {
                    unsigned long long x = 1;
                    while (j >= 0)
                    {
                        safe[countOfNumbers] = safe[countOfNumbers] + ((buffer[j] * (1 * x)) - '0');  //Addiert die 1_er der Zahl + 10er_Stelle usw. in das Double_Array
                        j--;
                        x = x * 10;
                    }
                }
                i++;
            }
            i = 0;
            printf("%.2f\n", safe[countOfNumbers]);
            countOfNumbers++;
        }
    }

    //writeFile

    FILE *fp2;
    fp2 = fopen(FILEPATHW, "w");

    //Feldart
    if (safe[0] == 0)
    {
        //fprintf(fp, "%s %s %s %d", "We", "are", "in", 2012);
    }
    if (safe[0] == 1)
    {
    }
    if (safe[0] == 2)
    {
    }

    //Geometrie
    if (safe[0] == 0)
    {
    }
    if (safe[0] == 1)
    {
    }

    //Boundary
    for (int i = 0; i <= ((int) safe[6]); i++)
    {
        //BoundaryTyp
        int boundaryTyp = 7;
        switch ((int) safe[boundaryTyp])
        {
            case 1 :
                fprintf(fp2, "%s %d %d \n", "gl.bc", i, 1);
                break;
            case 2:
                fprintf(fp2, "%s %d \n", "gl.di", 1);
                break;
            case 3:
                fprintf(fp2, "%s %d %d \n", "gl.bc", i, 3);
                break;
        }
    }
}


    int main()
    {
        readFile();

        return 0;
    }

