#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 2000

int encrypted_matrix[1000][3], y;

void encryption()
{
    int i, j, k, l = 0, sum = 0;
    char text[SIZE];
    int num_text[SIZE], message_matrix[1000][3];
    //this is key for encoding message
    int key[3][3] = {{4, 7, 9}, {3, 0, 5}, {7, 1, 2}};

    // this while loop for cleaning the buffer
    int c;
    while ( (c = getchar()) != '\n' && c != EOF ) { }
    printf("\nEnter Message: ");
    fgets(text, SIZE, stdin);

    y = strlen(text);

    for (int i = 0; i < y; i++)
    {
        num_text[i] = (int)text[i];
    }

    if (y % 3 == 1)
    {
        num_text[y + 1] = 0;
        num_text[y + 2] = 0;
        y = y + 2;
    }else if (y % 3 == 2)
    {
        num_text[y + 1] = 0;
        y = y + 1;
    }

    for (i = 0; i < y / 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            message_matrix[i][j] = num_text[l];
            l++;
        }
    }
    // for multiplying A_matrix*key_matrix
    for (i = 0; i < (y / 3); i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                sum += (message_matrix[i][k] * key[k][j]);
            }
            encrypted_matrix[i][j] = sum;
            sum = 0;
        }
    }
    // printing Encrypted matrix
    printf("\nEncrypted Text: ");
    for (i = 0; i < y / 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", encrypted_matrix[i][j]);
        }
    }
}

// function for decryption
void decryption()
{
    int i, j, k, l = 0;
    char text[SIZE];
    float sum = 0;
    // inverse matrix or key matrix[
    float a1 = (float)-1 / 42;
    float a2 = (float)-1 / 42;
    float a3 = (float)1 / 6;
    float a4 = (float)29 / 210;
    float a5 = (float)-11 / 42;
    float a6 = (float)1 / 30;
    float a7 = (float)1 / 70;
    float a8 = (float)3 / 14;
    float a9 = (float)-1 / 10;
    // ]

    float message_matrix[1000][3];
    // this is key for decoding message
    float inverse_key[3][3] = {a1, a2, a3, a4, a5, a6, a7, a8, a9};

    // for multiplying A_matrix*key_matrix
    for (i = 0; i < y / 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                sum = sum + (float)encrypted_matrix[i][k] * inverse_key[k][j];
            }
            message_matrix[i][j] = sum;
            sum = 0;
        }
    }

    // printing decrypted matrix
    printf("Decrypted numeric text: ");
    for (i = 0; i < y / 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%.0f ", message_matrix[i][j]);
        }
    }
    // convereting decrypted number to text
    printf("\nProcesseed Message text: ");
    for (i = 0; i < y / 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if ((int)message_matrix[i][j] + 0.5 < message_matrix[i][j])
                text[l] = (int)message_matrix[i][j] + 1;
            else
                text[l] = (int)message_matrix[i][j];
            l++;
        }
    }

    for (i = 0; i < y; i++)
    {
        printf("%c", text[i]);
    }
}

// main function
void main()
{
    int n;
    while (1)
    {
        printf("\n\n----------------\n"
               "1: Encryption\n"
               "2: Decryption\n"
               "3: Exit\n"
               "----------------\n");
        printf("Enter your choice: ");

        scanf("%d", &n);
        if (n == 1)
            encryption();
        else if (n == 2)
            decryption();
        else
            exit(0);
    }
}