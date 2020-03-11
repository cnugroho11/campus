#include <stdio.h>
#include <stdlib.h>

typedef struct barang{
    char ID [30];
    char nama [30];
    char harga [30];
    int jumlah;
};

void login()
{
    char nm [30], nim[30];
    printf("Masukan nama anda ; ");scanf("%[^\n]s", &nm);
    printf("Masukan NIM anda  : ");scanf("%s", &nim);
}

void main()
{
    int tc;
    printf("Masukan banyak barang : ");scanf("%d", &tc);
    struct barang brg[tc];
    system("clear");
    for(int i = 0; i < tc; i++)
    {
        printf("\n\nMasukan ID barang      : ");scanf("%s", &brg[i].ID);
        printf("Masukan Nama barang    : ");scanf("%s", &brg[i].nama);
        printf("Masukan Harga barang   : ");scanf("%s", &brg[i].harga);
        printf("Masukan Jumlah barang  : ");scanf("%d", &brg[i].jumlah);
    }
    system("clear");
    for(int i = 0; i < tc; i++)
    {
        printf("\n=========== Data barang anda ke-%d ===========", i+1);
        printf("\nID barang      : %s\n", brg[i].ID);
        printf("Nama barang    : %s\n", brg[i].nama);
        printf("Harga barang   : %s\n", brg[i].harga);
        printf("Jumlah barang  : %d\n", brg[i].jumlah);
        printf("==============================================\n");
    }
}
