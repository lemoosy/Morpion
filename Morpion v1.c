#include <stdio.h>
#include <stdlib.h> /*for system("cls")*/


void fill_matrix(int value, int matrix[][3])
{
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
            matrix[y][x] = value;
}

int check_vertical(int matrix[][3])
{
    // Vérifie si un joueur a réalisé une colonne

    int product;

    for (int x = 0; x < 3; x++)
    {
        product = 1;

        for (int y = 0; y < 3; y++)
            product *= matrix[y][x];

        if (product == 1)
            return 1;

        if (product == 8)
            return 2;
    }

    return 0;
}

int check_horizontal(int matrix[][3])
{
    // Vérifie si un joueur a réalisé une ligne

    int product;

    for (int y = 0; y < 3; y++)
    {
        product = 1;

        for (int x = 0; x < 3; x++)
            product *= matrix[y][x];

        if (product == 1)
            return 1;

        if (product == 8)
            return 2;
    }

    return 0;
}

void printf_matrix(int matrix[][3])
{
    // Affiche la matrice

    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
            printf("%d", matrix[y][x]);

        printf("\n");
    }
}

int winner(int matrix[][3])
{
    if (check_vertical(matrix))
        return 1;

    if (check_horizontal(matrix))
        return 1;

    int diagonal_1 = matrix[0][0] * matrix[1][1] * matrix[2][2];
    int diagonal_2 = matrix[0][2] * matrix[1][1] * matrix[2][0];

    return diagonal_1 == 1 || diagonal_1 == 8;
}

int matrix_full(int matrix[][3])
{
    int i = 1;

    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
            i *= matrix[y][x];

    return i > 0;
}

int main()
{
    int matrix[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
    int round[3] = {2, 1, 2};
    int square = 0;
    int player = 1;
    int game = 1;
    int x, y;

    while (game)
        while (1)
        {
            if (matrix_full(matrix))
            {
                printf("\nPersonne n'a gagn%c :(\n\n", 130);
                game = 0;
                break;
            }

            system("cls");
            printf("Au tour du joueur %d de jouer :\n\n", player);
            printf_matrix(matrix);
            printf("\nChoisi une case : ");
            scanf_s("%d", &square);

            if (square < 0 || square > 8)
                continue;

            x = square % 3;
            y = square / 3;

            if (matrix[y][x] == 0)
            {
                matrix[y][x] = player;
                player = round[player - 1];

                if (winner(matrix))
                {
                    printf("\nBravo joueur %d ! Tu as gagn%c !\n\n", round[player - 1], 130);
                    game = 0;
                }
                    
                break;
            }
        }

    system("pause");

    return 0;
}


// Léonard Lemoosy | Premier programme en C