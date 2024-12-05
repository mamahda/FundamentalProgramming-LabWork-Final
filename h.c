#include <stdio.h>

void chessChecker(char wk[3], char wq[3], char bk[3], char bq[3], char x)
{
    char board[8][8] = {0};
    int wk_y = wk[1] - '1';
    int wq_y = wq[1] - '1';
    int bk_y = bk[1] - '1';
    int bq_y = bq[1] - '1';

    int wk_x = wk[0] - 'a';
    int wq_x = wq[0] - 'a';
    int bk_x = bk[0] - 'a';
    int bq_x = bq[0] - 'a';

    board[wk_x][wk_y] = 'k';
    board[bk_x][bk_y] = 'K';
    board[wq_x][wq_y] = 'q';
    board[bq_x][bq_y] = 'Q';

    int checkW = 0;
    int checkB = 0;

    if (x == 'b')
    {
        int i = bq_y + 1;

        while (i < 7 && board[bq_x][i] == 0)
        {
            if (board[bq_x][i + 1] == 'k')
            {
                checkW = 1;
                break;
            }
            i++;
        }
        int j = bq_y - 1;
        while (j > 0 && board[bq_x][j] == 0)
        {
            if (board[bq_x][j - 1] == 'k')
            {
                checkW = 1;
                break;
            }
            j--;
        }
        int k = bq_x + 1;
        while (k < 7 && board[k][bq_y] == 0)
        {
            if (board[k + 1][bq_y] == 'k')
            {
                checkW = 1;
                break;
            }
            k++;
        }
        int m = bq_x - 1;
        while (m > 0 && board[m][bq_y] == 0)
        {
            if (board[m - 1][bq_y] == 'k')
            {
                checkW = 1;
                break;
            }
            m--;
        }
        int a = bq_x + 1;
        int b = bq_y + 1;
        while (a < 7 && b < 7 && board[a][b] == 0)
        {
            if (board[a + 1][b + 1] == 'k')
            {
                checkW = 1;
                break;
            }
            a++;
            b++;
        }

        int c = bq_x - 1;
        int d = bq_y - 1;
        while (c > 0 && d > 0 && board[c][d] == 0)
        {
            if (board[c - 1][d - 1] == 'k')
            {
                checkW = 1;
                break;
            }
            c--;
            d--;
        }

        int e = bq_x - 1;
        int f = bq_y + 1;
        while (e > 0 && f < 7 && board[e][f] == 0)
        {
            if (board[e - 1][f + 1] == 'k')
            {
                checkW = 1;
                break;
            }
            e--;
            f++;
        }

        int g = bq_x + 1;
        int h = bq_y - 1;
        while (g < 7 && h > 0 && board[g][h] == 0)
        {
            if (board[g + 1][h - 1] == 'k')
            {
                checkW = 1;
                break;
            }
            g++;
            h--;
        }
    }
    else
    {
        int i = wq_y + 1;

        while (i < 7 && board[wq_x][i] == 0)
        {
            if (board[wq_x][i + 1] == 'K')
            {
                checkB = 1;
                break;
            }
            i++;
        }
        int j = wq_y - 1;
        while (j > 0 && board[wq_x][j] == 0)
        {
            if (board[wq_x][j - 1] == 'K')
            {
                checkB = 1;
                break;
            }
            j--;
        }
        int k = wq_x + 1;
        while (k < 7 && board[k][wq_y] == 0)
        {
            if (board[k + 1][wq_y] == 'K')
            {
                checkB = 1;
                break;
            }
            k++;
        }
        int m = wq_x - 1;
        while (m > 0 && board[m][wq_y] == 0)
        {
            if (board[m - 1][wq_y] == 'K')
            {
                checkB = 1;
                break;
            }
            m--;
        }
        int a = wq_x + 1;
        int b = wq_y + 1;
        while (a < 7 && b < 7 && board[a][b] == 0)
        {
            if (board[a + 1][b + 1] == 'K')
            {
                checkB = 1;
                break;
            }
            a++;
            b++;
        }

        int c = wq_x - 1;
        int d = wq_y - 1;
        while (c > 0 && d > 0 && board[c][d] == 0)
        {
            if (board[c - 1][d - 1] == 'K')
            {
                checkB = 1;
                break;
            }
            c--;
            d--;
        }

        int e = wq_x - 1;
        int f = wq_y + 1;
        while (e > 0 && f < 7 && board[e][f] == 0)
        {
            if (board[e - 1][f + 1] == 'K')
            {
                checkB = 1;
                break;
            }
            e--;
            f++;
        }

        int g = wq_x + 1;
        int h = wq_y - 1;
        while (g < 7 && h > 0 && board[g][h] == 0)
        {
            if (board[g + 1][h - 1] == 'K')
            {
                checkB = 1;
                break;
            }
            g++;
            h--;
        }
    }

    if (checkW == 1)
    {
        printf("Black checked White!");
    }
    else if (checkB == 1)
    {
        printf("White checked Black!");
    }
    else
    {
        printf("Game is still going!");
    }
}

int main()
{
    char wk[3], wq[3], bk[3], bq[3], x;
    scanf("%s %s ", wk, wq);
    scanf("%s %s ", bk, bq);
    scanf("%c", &x);
    chessChecker(wk, wq, bk, bq, x);
}