#include <stdio.h>
#include <string.h>
int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        char str1[100001];
        char str2[100001];
        scanf("%s", str1);
        scanf("%s", str2); // isme malum krna hai;
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int i, j = 0, count = 0;
        if (len1 <= len2)
        {
            for (i = 0; i < len1; i++)
            {
                char value = str1[i];
                for (; j < len2; j++)
                {
                    if (str2[j] == value)
                    {
                        count++;
                        continue;
                    }
                }
            }
        }

        if (count == len1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}