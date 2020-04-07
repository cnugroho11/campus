#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, x;
    char str[100];

    printf("Masukan kalimat anda : ");
    scanf("%s", &str);

    for(i = 0; (i < 100 && str[i] != '\0'); i++)
    {
        str[i] = str[i] + 5;
    }
    printf("String anda adalah : %s", str);
}
