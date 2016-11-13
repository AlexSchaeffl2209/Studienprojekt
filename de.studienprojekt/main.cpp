#include <iostream>

#define FILEPATH "C:\\Users\\Alex-Pc\\Desktop\\lesen.txt"

using namespace std;

int readFile()
{
    FILE *fp;
    fp = fopen(FILEPATH, "r");


    int size = 50;
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
            printf("%f\n", safe[countOfNumbers]);
            countOfNumbers++;
        }
    }
}

int main()
{
    readFile();
}

