#include <stdio.h>
#include <stdlib.h>

int a;
int b;
char ch;

int tambah (int b)
{
    printf ("%d + %d ", a,b );
    return (a+b);
}

int kurang (int b)
{
    printf ("%d - %d ", a,b );
    return (a-b);
}

int kali (int b)
{
    printf ("%d * %d ", a,b );
    return (a*b);
}

int bagi (int b)
{
    printf ("%d / %d ", a,b );
    return (a/b);
}

int mod (int b)
{
    printf ("%d mod %d ", a,b );
    return (a % b);
}

int fak (int a)
{
    if (a != 0){
    return a* fak(a-1);
    } else {
        return 1;
    }
}

int reset (int a)
{
    return (a=0);
}

void angka2()
{
    printf("masukan angka kedua ");
    scanf("%d", &b);
}

void tampilan ()
{
    printf("masukan angka awal (int) : ");
    scanf("%d", &a);
}

void menu ()
{
    printf("pilihan menu \n");
    printf("1. Tambah \n2. Kurang\n3. Kali \n4. Bagi \n5. Modulo \n6. Faktorial \n7. Reset \n8. Exit \n");
    printf("pilihan ");
}

void main()
{
    int pil;
    tampilan();
    do{
    system("cls");
    printf("angka pertama %d\n", a);
    menu();
    scanf("%d", &pil);
        switch (pil)
        {
        case 1 :
            angka2();
            a=tambah(b);
            printf("hasilnya adalah %d\n", a);
            printf("===press any key to continue===");
            break;
        case 2 :
            angka2();
            a=kurang(b);
            printf("hasilnya adalah %d\n", a);
            printf("===press any key to continue===");
            break;
        case 3:
            angka2();
            a=kali(b);
            printf("hasilnya adalah %d\n", a);
            printf("===press any key to continue===");
            break;
        case 4 :
            angka2();
            a=bagi(b);
            printf("hasilnya adalah %d\n", a);
            printf("===press any key to continue===");
            break;
        case 5 :
            angka2();
            a=mod(b);
            printf("hasilnya adalah %d\n", a);
            printf("===press any key to continue===");
            break;
        case 6 :
            printf ("%d! ", a );
            a=fak(a);
            printf("hasilnya adalah %d\n", a);
            printf("===press any key to continue===");
            break;
        case 7 :
            a=reset(a);
            printf("===tekan sembarang untuk reset===\n");
            break;
        case 8:
            exit(0);
            break;
        }
        ch=getch();
    }while(ch='true');
}
