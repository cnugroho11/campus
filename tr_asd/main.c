#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int ii = 0;

struct kegiatan
{
    char logg[100];
};

struct kegiatan keg[100];

char usr[25],pass[25],ch;

void get_time()
{
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime );
    timeinfo = localtime (&rawtime);
    printf ("%s", asctime (timeinfo) );
}


void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

void quit_program()
{
    for(int i = 3; i >= 0; i--)
    {
        system("cls");
        gotoxy(40,11);printf("====================================\n");
        gotoxy(40,12);printf("++++Program akan keluar dalam %d++++\n", i);
        gotoxy(40,13);printf("====================================\n");
        Sleep(1000);
    }

    gotoxy(40,15);printf("Terimakasih!!\n");
    Sleep(1000);
    exit(0);
}

void login()
{
    system("cls");
    gotoxy(40,11);printf("Selamat Datang di Kamus Ala Kadarnya\n");
    gotoxy(40,12);printf("                                    \n");
    gotoxy(40,13);printf("====================================\n");
    gotoxy(40,16);printf("====================================\n");
    gotoxy(40,17);printf("++++++++++++++++++++++++++++++++++++\n");
    gotoxy(45,18);get_time();
    gotoxy(40,14);printf("Username   : ");scanf("%s", usr);
    gotoxy(40,15);printf("Pass       : ");
    int i = 0;
    while(1)
    {
        ch = getch();
        if(ch != '\r')
        {
            pass[i] = ch;
            ch = '*' ;
            printf("%c",ch);
        }
        else
        {
            break;
        }
        i++;
    }
    login_check();
}

void login_check()
{
    char pil = 'z';
    int c1 = strcmp(usr, "admin"),c2 = strcmp(pass, "admin");
    if(c1 == 0 && c2 == 0)
    {
        system("cls");
        gotoxy(40,11);printf("====================================\n");
        gotoxy(40,12);printf("==========Berhasil Login!!==========\n");
        gotoxy(40,13);printf("====================================\n");
        strcpy(keg[ii].logg, "Admin Telah Login");
        ii++;
        menu();
    }
    else
    {
        system("cls");
        gotoxy(40,11);printf("====================================\n");
        gotoxy(40,12);printf("!!!!Password atau Usename salah!!!!!\n");
        gotoxy(40,13);printf("====================================\n");
        gotoxy(40,14);printf("Mau coba login lagi? (y/n) \n");
        gotoxy(40,15);scanf("\n%c", &pil);
        if(pil == 'y' || pil == 'Y') login();
        else
        {
            quit_program();
        }
    }
}

void menu()
{
    int cek;
    system("cls");
    gotoxy(40,9);printf("==Selamat Datang di Kamus Ala Kadarnya==\n");
    gotoxy(40,10);printf("\n");
    gotoxy(40,11);printf("========================================\n");
    gotoxy(40,12);printf("++==========Silakan Pilih Menu========++\n");
    gotoxy(40,13);printf("| 1. Membuat Database Kamus            |\n");
    gotoxy(40,14);printf("| 2. Menampilkan Isi Database Kamus    |\n");
    gotoxy(40,15);printf("| 3. Menambah Data Kamus               |\n");
    gotoxy(40,16);printf("| 4. Menghapus Database Kamus          |\n");
    gotoxy(40,17);printf("| 5. Mengedit Database Kamus           |\n");
    gotoxy(40,18);printf("| 6. Mencari Database Kamus            |\n");
    gotoxy(40,19);printf("| 7. Mengurutkan Data pada Database    |\n");
    gotoxy(40,20);printf("| 8. Log Aktivitas                     |\n");
    gotoxy(40,21);printf("| 9. Keluar dari Program               |\n");
    gotoxy(40,23);printf("+______________________________________+\n");
}

struct tnode
{
    char indo[25];
    char jawa[25];
    char inggris[25];
    char gaul[25];
    char arti[25];
    struct tnode *next;
};
struct tnode *head=NULL,*curr=NULL, *node=NULL;

void insert_data(char ind[25], char ja[25], char ing[25], char ga[25], char ar[25])
{
    node = (struct tnode *)malloc (sizeof(struct tnode));
    strcpy(node ->indo,ind);
    strcpy(node ->jawa,ja);
    strcpy(node ->inggris,ing);
    strcpy(node ->gaul,ga);
    strcpy(node ->arti,ar);

    if (head == NULL)
    {
        head = node;
        curr = node;
    }
    else
    {
        curr -> next = node;
        curr = node;
    }

    curr -> next = NULL;
    curr = head;
}

void print_data()
{
    system("cls");
    gotoxy(10,8);printf("=======================Berikut adalah data yang anda masukan===========================");
    gotoxy(10,9);printf("=======================================================================================");
    gotoxy(10,10);printf("Bahasa Indonesia");gotoxy(30,10);printf("Bahasa Jawa");gotoxy(50,10);printf("Bahasa Inggris");gotoxy(70,10);printf("Bahasa Gaul");gotoxy(90,10);printf("Artinya");
    gotoxy(10,11);printf("+-------------------------------------------------------------------------------------+");
    int i = 0;
    while (curr != NULL)
    {
        gotoxy(10,13+i);printf("%s ", curr -> indo);
        gotoxy(30,13+i);printf("%s ", curr -> jawa);
        gotoxy(50,13+i);printf("%s ", curr -> inggris);
        gotoxy(70,13+i);printf("%s ", curr -> gaul);
        gotoxy(90,13+i);printf("%s ", curr -> arti);
        curr = curr -> next;
        printf("\n");
        i++;
    }
}
void input_data()
{
    void header()
    {
        gotoxy(40,4);printf("====================================\n");
        gotoxy(40,5);printf("        Menu Input Database\n");
        gotoxy(40,6);printf("++++++++++++++++++++++++++++++++++++\n");
        gotoxy(40,8);printf("====================================\n");
    }
    int tc;
    system("cls");
    header();
    char ind[25], ja[25], ing[25], ga[25], ar[25];
    gotoxy(40,9);printf("Masukan banyak data : ");
    gotoxy(63,9);scanf("%d", &tc);
    for(int i = 0; i < tc; i++)
    {
        system("cls");
        header();
        gotoxy(40,10);printf(":: Masukan data ke - %d\n", i+1);
        gotoxy(40,11);printf(":: Bahasa Indonesia : ");scanf("%s", ind);
        gotoxy(40,12);printf(":: Bahasa Inggris : ");scanf("%s", ja);
        gotoxy(40,13);printf(":: Bahasa Jawa : ");scanf("%s", ing);
        gotoxy(40,14);printf(":: Bahasa Gaul : ");scanf("%s", ga);
        gotoxy(40,15);printf(":: Bahasa Arti : ");scanf("%s", ar);
        insert_data(ind, ja, ing, ga, ar);
    }
    print_data();
    strcpy(keg[ii].logg, "Admin Telah Memasukan Data");
    ii++;
}

void main()
{
    int tc;
    login();
    gotoxy(40,22);printf("| Masukan pilihan anda :               |\n");
    gotoxy(65,22);scanf("%d", &tc);
    switch(tc)
    {
    case 1:
        input_data();
        break;
    case 2:
        print_data();
        break;
    }
}
