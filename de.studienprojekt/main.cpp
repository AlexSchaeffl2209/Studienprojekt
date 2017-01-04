#include <iostream>

#define FILEPATHR "C:\\Users\\Alex-Pc\\Desktop\\lesen.txt"
#define FILEPATHW "C:\\Users\\Alex-Pc\\Desktop\\schreiben.txt"

using namespace std;

double * readFile()
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
    return safe;
}


void writeFile(double safe[])
{
    FILE *fp;
    fp = fopen(FILEPATHW, "w");

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
    for (int i = 0; i < safe[6]; i++)
    {
        //BoundaryTyp
        int boundaryTyp = 7;
        if(safe[boundaryTyp] == 1)
        {
            fprintf(fp, "%s", "gl.bc 0");
        }
        if(safe[boundaryTyp] == 2)
        {
            fprintf(fp, "%s", "gl.di");
        }
        if(safe[boundaryTyp] == 3)
        {
            fprintf(fp, "%s", "gl.bc 1");
        }
    }
}

int main()
{

    double *tmp;

    tmp = readFile();

    writeFile(tmp);

    return 0;
}

