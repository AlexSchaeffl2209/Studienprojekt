#include <iostream>
#include <stdio.h>
#include <string.h>

#define FILEPATH "C:\\Users\\Alex-Pc\\Desktop\\lesen.txt"

using namespace std;

//Bestimmt die Feldart des Xtwin-Programms
int getFieldType(char charArray[])
{
    if ((charArray[0]) == '0')
    {
        return printf("Feldart: %c Kapaz. & Real\n", charArray[0]);

    }
    else if (charArray[0] == '1')
    {
        return printf("Feldart: %c Kapaz. & komplex\n", charArray[0]);

    }
    else if (charArray[0] == '2')
    {
        return printf("Feldart: %c Kapaz. Res & komplex\n", charArray[0]);

    }
    return 0;
}

//Bestimmt die Geometry des Xtwin-Programms
int getGeometryType(char charArray[])
{
    if ((charArray[2]) == '0')
    {
        return printf("Geometrie: %c 2D\n", charArray[2]);

    }
    else if (charArray[2] == '1')
    {
        return printf("Geometrie: %c Achsensymmetrisch\n", charArray[2]);

    }
    return 0;
}

//Bestimmt ob die Ergebnisse geladen werden sollen oder nicht
int getLoadResults(char charArray[])
{
    int charPosition = 4;
    if ((charArray[charPosition]) == '0')
    {
        return printf("Ergebnisse laden: %c\n", charArray[charPosition]);

    }
    else if (charArray[charPosition] == '1')
    {
        return printf("Ergebnisse laden: %c\n", charArray[charPosition]);
    }
    return 0;
}

/*
int getExternField(char charArray[])
{

}
*/


int readFile()
{
    FILE *fp;
    fp = fopen(FILEPATH, "r");

    int size = 255;
    char buffer[size];
    double safe[size];

//    for (int j = 0; j < size; j++)
//    {
//        buffer[j] = ' ';
//    }

    if (fp == NULL)
    {
        printf("Datei konnte nicht geoeffnet werden!\n");
    }
    else
    {
        int i = 0;
        while (fscanf(fp, "%s", buffer) != EOF)
        {
            fscanf(fp, "%f", buffer);

            while (buffer[i] != '\0' || buffer[i] !=
                                        '.')   //Geht das Array durch bis er entweder am Ende der Zahl ist oder bei einer DoubleZahl einen '.' findet
            {
                int j = i;
                int z = i;

                if (buffer[i] == '.')
                {
                    unsigned long long x = 1;
                    while (j > 0)
                    {
                        safe[0] = safe[0] + ((buffer[j - 1] - '0' ) * (1 * x));  //Addiert die 1_er der Zahl + 10er_Stelle usw. in das Double_Array
                        j--;
                        x =  x * 10;
                    }

                    unsigned long long a = 10;
                    while (z != '\000')
                    {
                        safe[0] = safe[0] + ((buffer[z + 1] - '0') * (1 / a));     //Addiert bei Double_Zahl die Stellen nach dem '.' hinzu
                        z++;
                        a = a * 10;
                    }
                }
                i++;
            }
        }

        printf("%f", safe[0]);

        //printf("%s\n\n", tmp);

        //getFieldType(tmp);
        //getGeometryType(tmp);
        //getLoadResults(tmp);
        //getExternField(tmp);

    }
    return 0;
}

int main()
{
    readFile();
}

