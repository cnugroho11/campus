#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

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
        gotoxy(45,11);printf("====================================\n");
        gotoxy(45,12);printf("++++Program akan keluar dalam %d++++\n", i);
        gotoxy(45,13);printf("====================================\n");
        Sleep(1000);
    }

    gotoxy(45,15);printf("Terimakasih!!\n");
    Sleep(1000);
    exit(0);
}

void login()
{
    system("cls");
    gotoxy(45,11);printf("Selamat Datang di Kamus Ala Kadarnya\n");
    gotoxy(45,12);printf("                                    \n");
    gotoxy(45,13);printf("====================================\n");
    gotoxy(45,16);printf("====================================\n");
    gotoxy(45,17);printf("++++++++++++++++++++++++++++++++++++\n");
    gotoxy(51,18);get_time();
    gotoxy(45,14);printf("Username     : ");scanf("%s", usr);
    gotoxy(45,15);printf("Pass (max 8) : ");
    int i = 0;
    while(1)
    {
        ch = getch();
        if(ch != '\r')
        {
            pass[i] = ch;
            ch = '*' ;
            printf("%c",ch);
            //i++;
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
        gotoxy(45,11);printf("====================================\n");
        gotoxy(45,12);printf("==========Berhasil Login!!==========\n");
        gotoxy(45,13);printf("====================================\n");
    }
    else
    {
        system("cls");
        gotoxy(45,11);printf("====================================\n");
        gotoxy(45,12);printf("!!!!Password atau Usename salah!!!!!\n");
        gotoxy(45,13);printf("====================================\n");
        gotoxy(45,14);printf("Mau coba login lagi? (y/n) \n");
        gotoxy(45,15);scanf("\n%c", &pil);
        if(pil == 'y' || pil == 'Y') login();
        else
        {
            quit_program();
        }
    }
}

void menu()
{
    system("cls");
    gotoxy(45,11);printf("Selamat Datang di Kamus Ala Kadarnya\n");
    gotoxy(45,12);printf("                                    \n");
    gotoxy(45,13);printf("====================================\n");
    gotoxy(45,14);printf("==========Silakan Pilih Menu========\n");
    gotoxy(45,15);printf("1. Membuat Database Kamus\n");
    gotoxy(45,16);printf("2. Menampilkan Isi Database Kamus\n");
    gotoxy(45,17);printf("3. Menambah Data Kamus\n");
    gotoxy(45,18);printf("4. Menghapus Database Kamus\n");
    gotoxy(45,19);printf("5. Mengedit Database Kamus\n");
    gotoxy(45,20);printf("6. Mencari Database Kamus\n");
    gotoxy(45,21);printf("7. Mengurutkan Data pada Database\n");
    gotoxy(45,22);printf("8. Log Aktivitas\n");
    gotoxy(45,23);printf("9. Keluar dari Program\n");
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
    printf("Bahasa Indonesia\t\tBahasa Jawa\t\tBahasa Inggris\t\tBahasa Gaul\t\tArtinya\n");
    while (curr != NULL)
    {
        printf("%s", curr -> indo);
        printf("%s", curr -> jawa);
        printf("%s", curr -> inggris);
        printf("%s", curr -> gaul);
        printf("%s", curr -> arti);
        curr = curr -> next;
        printf("\n");
    }
}

void input_data()
{
    int tc;
    char ind[25], ja[25], ing[25], ga[25], ar[25];
    printf("Masukan banyak data : ");scanf("%d", &tc);
    for(int i = 0; i < tc; i++)
    {
        printf("Masukan data ke - %d\n", i+1);
        printf("Bahasa Indonesia : ");scanf("%s", ind);
        printf("Bahasa Inggris : ");scanf("%s", ja);
        printf("Bahasa Jawa : ");scanf("%s", ing);
        printf("Bahasa Gaul : ");scanf("%s", ga);
        printf("Bahasa Arti : ");scanf("%s", ar);
        insert_data(ind, ja, ing, ga, ar);
    }
}


int main()
{
    login();
    input_data();
    print_data();
    return 0;
}
