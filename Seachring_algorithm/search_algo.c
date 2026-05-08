#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define FILE_COUNT 3

// Function for Longest Common Substring
int longestCommonSubstring(char *X, char *Y)
{
    int m = strlen(X);
    int n = strlen(Y);

    int LCSuff[m + 1][n + 1];
    int result = 0;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                LCSuff[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;

                if (LCSuff[i][j] > result)
                {
                    result = LCSuff[i][j];
                }
            }
            else
            {
                LCSuff[i][j] = 0;
            }
        }
    }

    return result;
}

int main()
{
    char *files[FILE_COUNT] = {
        "file1.txt",
        "file2.txt",
        "file3.txt"
    };

    char pattern[100];

    printf("Enter substring to search: ");
    scanf("%s", pattern);

    printf("\n===== SEARCH RESULTS =====\n");

    for (int f = 0; f < FILE_COUNT; f++)
    {
        FILE *fp = fopen(files[f], "r");

        if (fp == NULL)
        {
            printf("Cannot open %s\n", files[f]);
            continue;
        }

        char text[MAX];

        fread(text, sizeof(char), MAX, fp);
        fclose(fp);

        int matchLength = longestCommonSubstring(pattern, text);

        if (matchLength == strlen(pattern))
        {
            printf("Substring \"%s\" is FOUND in %s\n",
                   pattern, files[f]);
        }
        else
        {
            printf("Substring \"%s\" is NOT FOUND in %s\n",
                   pattern, files[f]);
        }
    }

    return 0;
}