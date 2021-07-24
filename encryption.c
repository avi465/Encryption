#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void encryption();
void decryption();
int encrypted_matrix[1000][3], y;
void main()
{
    int n;
    printf("1: Encryption   2: Decryption  ||  Input: ");
    fflush(stdin);
    scanf("%d", &n);
    if (n == 1)
        encryption();
    else if (n == 2)
        decryption();
}
void encryption()
{
    int i, j, k, l = 0;
    int sum = 0;
    char text[2500];
    int num_text[2500];
    int key[3][3] = {{4, 7, 9}, {3, 0, 5}, {7, 1, 2}}; //this is key for encoding message
    int message_matrix[1000][3];
    printf("Enter Message: ");
    fflush(stdin);
    gets(text);
    y = strlen(text);
    for (int i = 0; i < y; i++)
    {
        // here i have custom assigned number to character to improve security but it is basic limited character
        if (text[i] >= 'A' && text[i] <= 'Z')
            num_text[i] = text[i] - 35;
        else if (text[i] >= 'a' && text[i] <= 'z')
            num_text[i] = text[i] - 95;
        else if (text[i] == ' ')
            num_text[i] = text[i] - 32;
    }
    if (y % 3 == 1)
    {
        num_text[y + 1] = 0;
        num_text[y + 2] = 0;
        y = y + 2;
    }
    else if (y % 3 == 2)
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
    printf("Encryption Successful\n");
    printf("Encrypted Text: ");
    for (i = 0; i < y / 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d", encrypted_matrix[i][j]);
        }
    }
    int n;
    printf("\n\n1: Decryption   2: Exit  ||  Input: ");
    fflush(stdin);
    scanf("%d", &n);
    if (n == 1)
        decryption();
    else if (n == 2)
        exit(1);
}

// function for decryption
void decryption()
{
    int i, j, k, l = 0;
    char text[2500];
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

    // wrong key matrix which will result in incorrect decryption, only for testing [
    // float a1 = (float)2/54;
    // float a2 = (float)-1/67;
    // float a3 = (float)1 / 6;
    // float a4 = (float)29;
    // float a5 = (float)-11;
    // float a6 = (float)1/3;
    // float a7 = (float)56;
    // float a8 = (float)3 /4;
    // float a9 = (float)10/4;
    // ]

    float message_matrix[1000][3];
    float inverse_key[3][3] = {a1, a2, a3, a4, a5, a6, a7, a8, a9}; //this is key for decoding message

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
        for (int j = 0; j < 3; j++)
        {
            // here is some problem in decryption of program
            if (message_matrix[i][j] >= 30 && message_matrix[i][j <= 55])
                if ((int)message_matrix[i][j] + 0.5 < message_matrix[i][j])
                {
                    text[l] = (int)message_matrix[i][j] + 36;
                }
                else
                    text[l] = message_matrix[i][j] + 35;
            else if (message_matrix[i][j] >= 1 && message_matrix[i][j] <= 27)
                if ((int)message_matrix[i][j] + 0.5 < message_matrix[i][j])
                {
                    text[l] = (int)message_matrix[i][j] + 96;
                }
                else
                    text[l] = message_matrix[i][j] + 95;
            else if (message_matrix[i][j] < 1)
                text[l] = 32;
            l++;
        }
    }
    for (i = 0; i < y; i++)
    {
        printf("%c", text[i]);
    }

    int n;
    printf("\n\n1: Encryption   2: Exit  ||  Input: ");
    fflush(stdin);
    scanf("%d", &n);
    if (n == 1)
        encryption();
    else if (n == 2)
        exit(1);
}