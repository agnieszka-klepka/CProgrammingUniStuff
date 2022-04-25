#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void letterSize(char *studentInformation);

typedef struct list
{
    char *studentInfromation;
    char *studentLastName;
    int INDEX;
    float L1;
    float L2;
    float L3;
    float L4;
    float L5;
    float K1;

} studentList;

studentList transformLine(char *lines)
{
    //char lines2[strlen(lines) + 5];
    char *studentInformation = strtok(lines, ",");
    letterSize(studentInformation);
    char *studentLastName = strtok(NULL, ",");
    letterSize(studentLastName);
    char *INDEX = strtok(NULL, ",");
    addComma(INDEX);
    char *L1 = strtok(NULL, ",");
    addComma(L1);
    char *L2 = strtok(NULL, ",");
    addComma(L2);
    char *L3 = strtok(NULL, ",");
    addComma(L3);
    char *L4 = strtok(NULL, ",");
    addComma(L4);
    char *K1 = strtok(NULL, ",");
    dataToFile(K1);
};

void letterSize(char *studentInformation)
{
    int counter = 0;
    for (int i = 0; i <= strlen(studentInformation); i++) //funkcja strlen oblicza dlugosc zmiennej
    {
        if (studentInformation[i] >= 'A' && studentInformation[i] <= 'Z')
        {
            studentInformation[i] = studentInformation[i] + 32;
        };
        counter++;
    };
    studentInformation[0] = toupper(studentInformation[0]);

    //sortByName(studentInformation);
    addComma(studentInformation);
};

int addComma(char *studentInformation)
{
    char studentInformation2[strlen(studentInformation) + 1];
    strcpy(studentInformation2, studentInformation);
    strcat(studentInformation2, ",");
    dataToFile(studentInformation2);
};

/*int sortByName()
{
    size_t iterator_a, iterator_b;

    addComma(studentInformation);
};*/

int sortByName(char *studentInformation))
{
    char *sortingTab = (char *)malloc(sizeof(char));

    int i = 0;
    for (i = 0; i < 20; i++)
    {
        sortingTab[i] = studentInformation2;
    };
    for (i = 0; i < 20; i++)
    {
        printf("%s", &sortingTab[i]);
    };
};

int dataToFile(char *studentInformation2)
{
    FILE *file = fopen("plik_wy.txt", "a"); //uzywam argumentu "a", by plik nie był nadpisywany, tylko informacje dopisywane na koncu pliku
    //printf("%s", studentInformation);
    fwrite(studentInformation2, 1, strlen(studentInformation2), file);
    fclose(file);
};

int main()
{
    char *line = NULL;
    size_t lines_length = 0;
    ssize_t line_size;

    FILE *fp = fopen("plik.txt", "r");

    if (fp == NULL)
    {
        printf("%s", "Error opening file");
        fclose(fp);
        return 0;
    };

    line_size = getline(&line, &lines_length, fp); //pierwsza linia naszego pliku

    while (line_size >= 0) //petla działa do konca linijek w pliku
    {
        studentList studentData = transformLine(line); //odwołuje się do funkcji, ktora przerabia mi linię na elementy, ktore włozę do struktury
        line_size = getline(&line, &lines_length, fp); //biorę jedna linijke z pliku
    };

    free(line);
    line = NULL;
    fclose(fp);
};
