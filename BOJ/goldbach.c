#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define NUMLEN  7

struct pair
{
    int first;
    int last;
};

char prime_numbers[10001];

bool is_prime(int n);
struct pair* goldbach(int n);


int main()
{
    char results[10000][10] = { 0 };
    char buffer[NUMLEN] = { 0 };
    int t = 0;
    int nresult = 0;

    memset(prime_numbers, -1, 10001);

    fgets(buffer, NUMLEN, stdin);
    buffer[strlen(buffer) - 1] = 0;

    t = atoi(buffer);

    for (int i = 0; i < t; i++)
    {
        fgets(buffer, NUMLEN, stdin);
        buffer[strlen(buffer) - 1] = 0;

        int n = atoi(buffer);
        struct pair* result = goldbach(n);

        if (result)
            sprintf(results[nresult++], "%d %d", result->first, result->last);
    }
    for (int i = 0; i < nresult; i++)
        printf("%s\n", results[i]);
    return 0;
}


bool is_prime(int n)
{
    if (prime_numbers[n] != -1)
        return prime_numbers[n];

    int upper_bound = sqrtf(n);

    for (int i = 2; i <= upper_bound; i++)
        if (n % i == 0)
            return (prime_numbers[n] = false);
    return (prime_numbers[n] = true);
}

struct pair* goldbach(int n)
{
    static struct pair result;
    int cur = n / 2;

    do
    {
        if (is_prime(cur) && is_prime(n - cur))
        {
            result.first = cur;
            result.last = n - cur;
            return &result;
        }
    } while (cur--);

    return NULL;
}