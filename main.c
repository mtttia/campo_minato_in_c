#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int ROW = 10;
const int COLUMN = 10;

struct Cella {
    int valore;
    int stato;
};

void printMatrix(struct Cella map[ROW][COLUMN])
{
    system("cls");
    printf("   ");
    for(int j = 0; j < COLUMN; j++)
    {
        printf(" %d", j);
    }
    printf("\n");
    printf("   ");
    for(int j = 0; j < COLUMN; j++)
    {
        printf("__");
    }
    printf("\n");
    for(int i = 0; i < ROW; i++)
    {
        printf("%d |", i);
        for(int j = 0; j < COLUMN; j++)
        {
            if(map[i][j].stato == 0)
            {
                printf(" *");
            }
            else
            {
                printf(" %d", map[i][j].valore);
            }
        }
        printf("\n");
    }

    printf("\n");
    puts("Inserisci le coordinate (riga,colonna) (es. 1,5): ");
    int x,y;
    scanf("%d,%d", &x, &y);

    if(map[x][y].valore == -1)
    {
        printf("HAI PERSO");
    }
    else
    {
        map[x][y].stato = 1;
        printMatrix(map);
    }

}

int main() {
    srand(time(NULL));   // Initialization, should only be called once.


    struct Cella map[ROW][COLUMN];
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COLUMN; j++)
        {
            map[i][j].valore = (rand() % 101) < 20 ? -1 : 0;
            map[i][j].stato = 0;
        }
    }

    map[0][0].valore = 0;
    map[0][1].valore = 0;
    map[0][2].valore = 0;
    map[1][0].valore = 0;
    map[1][1].valore = 0;
    map[1][2].valore = 0;
    map[2][0].valore = 0;
    map[2][1].valore = 0;
    map[2][2].valore = 0;
    map[3][0].valore = 0;
    map[3][1].valore = 0;
    map[3][2].valore = 0;
    map[3][3].valore = 0;
    map[0][3].valore = 0;
    map[1][3].valore = 0;
    map[2][3].valore = 0;

    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COLUMN; j++){
            if (map[i][j].valore != -1) {
                int bomb_counter = 0;
                int rmin = i == 0 ? 0 : i - 1;
                int rmax = i == ROW - 1 ? ROW - 1 : i + 1;
                int cmin = j == 0 ? 0 : j - 1;
                int cmax = j == COLUMN - 1 ? COLUMN - 1 : j + 1;

                for (int r = rmin; r <= rmax; r++){
                    for (int c = cmin; c <= cmax; c++){
                        if (map[r][c].valore == -1) {
                            bomb_counter++;
                        }
                    }
                }
                map[i][j].valore = bomb_counter;
                map[i][j].stato = 0;
            }
            else {
                map[i][j].valore = -1;
                map[i][j].stato = 0;
            }

        }
    }

    map[0][0].stato = 1;
    map[0][1].stato = 1;
    map[0][2].stato = 1;
    map[1][0].stato = 1;
    map[1][1].stato = 1;
    map[1][2].stato = 1;
    map[2][0].stato = 1;
    map[2][1].stato = 1;
    map[2][2].stato = 1;
    map[3][0].stato = 1;
    map[3][1].stato = 1;
    map[3][2].stato = 1;
    map[3][3].stato = 1;
    map[0][3].stato = 1;
    map[1][3].stato = 1;
    map[2][3].stato = 1;

    printMatrix(map);

    return 0;
}