#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char *a, const char *b)
{
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] < b[i])
        {
            return 0;
        }
        else if (a[i] > b[i])
        {
            return 1;
        }
    }

    return 0;
};

int lexicographic_sort_reverse(const char *a, const char *b)
{
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] > b[i])
        {
            return 0;
        }
        else if (a[i] < b[i])
        {
            return 1;
        }
    }

    if (strlen(a) < strlen(b))
    {
        return 1;
    }

    return 0;
};

int sort_by_length(const char *a, const char *b)
{
    if (strlen(a) > strlen(b))
    {
        return 1;
    }
    else if (strlen(a) == strlen(b))
    {
        return lexicographic_sort(a, b);
    }

    return 0;
};

int distinct_characters(const char *str)
{
    int a[26] = {0}, ret = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (a[str[i] - 97] == 0)
        {
            a[str[i] - 97] = 1;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        ret += a[i];
    }

    return ret;
};

int sort_by_number_of_distinct_characters(const char *a, const char *b)
{
    if (distinct_characters(a) > distinct_characters(b))
    {
        return 1;
    }
    else if (distinct_characters(a) == distinct_characters(b))
    {
        return lexicographic_sort(a, b);
    }

    return 0;
};

void string_sort(char **arr, const int len, int (*cmp_func)(const char *a, const char *b))
{
    char *temp;

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (cmp_func(arr[i], arr[j]))
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
};

int main()
{
    int n;
    scanf("%d", &n);

    char **arr;
    arr = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);

    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);

    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);

    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);

    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}
