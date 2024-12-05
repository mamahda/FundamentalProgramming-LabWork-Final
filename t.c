#include <stdio.h>
#include <string.h>

void decrypt(char *binary, char *output)
{
    int value = 0;
    for (int i = 0; i < 8; i++)
    {
        value = value * 2 + (binary[i] - '0');
    }
    *output = (char)value;
}

int searchWord(char grid[5][5], char *word)
{
    int len = strlen(word);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= 5 - len; j++)
        {
            int found = 1;
            for (int k = 0; k < len; k++)
            {
                if (grid[i][j + k] != word[k])
                {
                    found = 0;
                    break;
                }
            }
            if (found)
                return 1;
        }
    }

    for (int i = 0; i <= 5 - len; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int found = 1;
            for (int k = 0; k < len; k++)
            {
                if (grid[i + k][j] != word[k])
                {
                    found = 0;
                    break;
                }
            }
            if (found)
                return 1;
        }
    }

    return 0;
}

int main()
{
    char *data[5 * 5] = {
        "01001000", "01011000", "01111001", "01110110", "01000111",
        "01100101", "01000110", "01001010", "01110001", "01100110",
        "01101100", "01110101", "01101000", "01010011", "01001011",
        "01101100", "01001101", "01100011", "01101010", "01101101",
        "01101111", "01110010", "01010101", "01110100", "01011001"};

    char grid[5][5];
    char word[6];
    scanf("%5s", word);

    for (int i = 0; i < 5 * 5; i++)
    {
        decrypt(data[i], &grid[i / 5][i % 5]);
    }

    if (searchWord(grid, word))
    {
        printf("%s found\n", word);
    }
    else
    {
        printf("Failed to find the specified word: %s\n", word);
    }

    return 0;
}