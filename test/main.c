#include <stdio.h>
#include <stdlib.h>

struct barang {
    char kbarang [30];
    char nbarang [30];
    char bbarang [30];
    char hbarang [30];
    int jbarang;
};

void main()
{
    int tc;
    printf("Banyak barang yang akan dimasukan : ");scanf("\n%d", &tc);
    struct barang bg[tc];
    for(int i = 0; i < tc; i++)
    {
        printf("\n\n:: Kode Barang     :  ");scanf("\n%s", &bg[i].kbarang);
        printf(":: Nama Barang     :  ");scanf("\n%s", &bg[i].nbarang);
        printf(":: Bahan Dasar     :  ");scanf("\n%s", &bg[i].bbarang);
        printf(":: Jumlah          :  ");scanf("\n%d", &bg[i].jbarang);
        printf(":: Harga Per Unit  :  Rp. ");scanf("%s", &bg[i].hbarang);
    }
    system("clear");
    for(int i = 0; i < tc; i++)
    {
        printf("\n\nData barang ke %d : ", i+1);
        printf("\n\n:: Kode Barang     :  %s\n", bg[i].kbarang);
        printf(":: Nama Barang     :  %s\n", bg[i].nbarang);
        printf(":: Bahan Dasar     :  %s\n", bg[i].bbarang);
        printf(":: Jumlah          :  %d\n", bg[i].jbarang);
        printf(":: Harga Per Unit  :  Rp. %s\n\n", bg[i].hbarang);
    }
}

