#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char *s;

    s = malloc(1024 * sizeof(char));

    scanf("%s", s);

    s = realloc(s, strlen(s) + 1);

    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = 0;
    }

    for (int j = 0; j < strlen(s); j++)
    {
        if (s[j] >= '0' && s[j] <= '9')
        {
            arr[(int)(s[j] - '0')]++;
        }
    }

    for (int k = 0; k < 10; k++)
    {
        printf("%d ", arr[k]);
    }

    printf("\n");

    free(s);

    return 0;
}
