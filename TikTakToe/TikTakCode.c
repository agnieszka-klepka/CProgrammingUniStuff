#include <stdio.h>
#include <stdbool.h>
int m, n;
char matrix[8][8];
bool victoria = false;
int countMoves = 0;
bool whenWin();
void gameRule(int m, int n);
void getNumber(int m, int n);
int showMatrix(int m, int n);

int main(void)
{
    int i, j;
    int p = 1;
    printf("%s", " ~~~~~~~~\n 12345678\n ~~~~~~~~\n");
    for (i = 0; i < 8; i++)
    { //petla wyswietla nasza plansze
        printf("%d", p++);
        for (j = 0; j < 8; j++)
        {
            matrix[i][j] = 'O';
            printf("%c", matrix[i][j]);
        };
        printf("\n");
    };
    printf("%s", " ~~~~~~~~\n");
    getNumber(m, n);
};

void getNumber(m, n) //funkcja pobierająca numerki od gracza, liczy rowniez ruchy
{

    if (victoria != true)
    {
        do
        {
            printf("Podaj numerek wiersza od 1 do 8:");
            scanf("%d", &m);
            if (!(1 <= m && m <= 8))
                printf("Nie ma takiego numeru wiersza!\n");
        } while (!(1 <= m && m <= 8));
        do
        {
            printf("Podaj numerek kolumny od 1 do 8:");
            scanf("%d", &n);
            if (!(1 <= n && n <= 8))
                printf("Nie ma takiego numeru kolumny!\n");
        } while (!(1 <= n && n <= 8));
        countMoves++;
        gameRule(m, n);
    };
};

void gameRule(int m, int n) //zdefiniowana zasada gry oraz warunki brzegowe
{
    if (matrix[m - 1][n - 1] == 'O')
    {
        matrix[m - 1][n - 1] = 'X';
    }
    else
    {
        matrix[m - 1][n - 1] = 'O';
    };
    if (matrix[m - 1][n - 2] == 'O')
    {
        matrix[m - 1][n - 2] = 'X';
    }
    else
    {
        matrix[m - 1][n - 2] = 'O';
    };
    if (matrix[m - 1][n] == 'O')
    {
        matrix[m - 1][n] = 'X';
    }
    else
    {
        matrix[m - 1][n] = 'O';
    };
    if (matrix[m][n - 1] == 'O')
    {
        matrix[m][n - 1] = 'X';
    }
    else
    {
        matrix[m][n - 1] = 'O';
    };
    if (matrix[m - 2][n - 1] == 'O')
    {
        matrix[m - 2][n - 1] = 'X';
    }
    else
    {
        matrix[m - 2][n - 1] = 'O';
    };

    showMatrix(m, n);
};

int showMatrix(m, n)
{
    int p = 1; //zmienna sluzy do wyswietlenia numeru wierszow przy uzyciu petli
    printf("liczba ruchow:%d\n", countMoves);
    printf("%s", " ~~~~~~~~\n 12345678\n ~~~~~~~~\n");
    for (m = 0; m < 8; m++)
    { //petla wyswietla macierz
        printf("%d", p++);
        for (n = 0; n < 8; n++)
        {
            printf("%c", matrix[m][n]);
        };
        printf("\n");
    };
    printf("%s", " ~~~~~~~~\n");

    whenWin();
    getNumber(m, n);
    return 0;
}

bool whenWin()
{
    int k, l;
    int counter = 0;
    for (k = 0; k < 8; k++)
    {
        for (l = 0; l < 8; l++)
        {
            if (matrix[k][l] == 'X')
            {
                counter++;
            }
        }
    }
    if (counter == 64)
        victoria = true;
    return victoria;
};
