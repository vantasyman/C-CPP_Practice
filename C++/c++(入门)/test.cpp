#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
bool isPalindrome(int x) {
    if (x < 0)
    {
        return false;
    }
    int* tmp = (int*)malloc(sizeof(int) * 11);
    int count = 0;
    while (x != 0)
    {
        tmp[count] = x % 10;
        x /= 10;
        count++;
    }
    count--;

    for (int x = 0; x < count; x++, count--)
    {
        printf("%d", x);
        printf("%d %d", tmp[x], tmp[count]);
        if (tmp[x] != tmp[count]);
        {
            return false;
        }
    }
    return true;
}
int main()
{
    printf("%d",isPalindrome(121));
}







