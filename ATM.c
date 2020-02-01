#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a,b,c,d,e,f,hutang,bayar,sisa_hutang,kembalian;
    char x,ch;
    do{
    system ("cls");
    printf("Selamat datang!! \n");
    printf("1. bangun ruang \n");
    printf("2. hutang \n");
    printf("3. exit \n");
    printf("Pilih menu : ");
    scanf("%i", &f);
    switch (f) {
        case 1:
            e=1;
            printf("masukan tinggi segitiga ");
            scanf("%i", &a);
            for (b=0; b<a; b++){
                for (c=b; c<a; c++){
                printf("     ");
                }
                for (d=0; d<b+1; d++){
            printf("%10d", e);
            e++;
            e++;
        }
        printf("\n");
    }
        break;
        case 2:
            printf("Hutang berapa? ");
            scanf("%i", &hutang);
            printf("hutang anda adalah %i\n", hutang);
            printf ("==========\n");
            do {
                printf("bayar hutang ");
                scanf("%i", &bayar);
                hutang=hutang-bayar;
                    if (hutang > 0){
                        printf("hutang anda masih %i\n", hutang);
                    } else if (hutang == 0){
                        printf ("hutang lunas! \n");
                        break;
                    } else if (hutang < 0){
                        kembalian=hutang*-1;
                        printf("hutang anda lunas! kembali %i\n", kembalian);
                        break;
                    }
                printf("Apakah anda mau bayar lagi? y/n ");
                scanf(" %c", &x);
                    } while (x == 'y' || x== 'Y');
                        if (hutang = 0 || hutang < 0){
                            break;
                        } else if (x=='n' || x=='N') {
                            printf("segera bayar hutang!!\n");
                        }
                    break;
        case 3:
            exit (0);
                    default :
                    printf("pilihan anda tidak ada\n");
                }
            printf("====press any key to conntinue====");
            ch=getch();
        }
    while (ch = 'true');
}
