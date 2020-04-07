#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct kamus
{
    char indo[25];
    char jawa[25];
    char inggris[25];
    char gaul[25];
    char arti[25];
};

typedef struct activity
{
    char act[100];
};

struct activity log[100];
struct kamus km[100];
int tc_data, log_i = 0;

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
    system("cls");
    system("color 3f");
    Sleep(1000);
    printf(" ####   ####   ####  #####  #####  #   # ###### \n");
    Sleep(1000);
    printf("#    # #    # #    # #    # #    #  # #  #      \n");
    Sleep(1000);
    printf("#      #    # #    # #    # #####    #   #####  \n");
    Sleep(1000);
    printf("#  ### #    # #    # #    # #    #   #   #      \n");
    Sleep(1000);
    printf("#    # #    # #    # #    # #    #   #   #      \n");
    Sleep(1000);
    printf(" ####   ####   ####  #####  #####    #   ###### \n");
    Sleep(3000);
    gotoxy(40,20);printf("M");
    Sleep(500);
    gotoxy(40,20);printf("MA");
    Sleep(500);
    gotoxy(40,20);printf("MAD");
    Sleep(500);
    gotoxy(40,20);printf("MADE");
    Sleep(500);
    gotoxy(40,20);printf("MADE B");
    Sleep(500);
    gotoxy(40,20);printf("MADE BY");
    Sleep(500);
    gotoxy(40,20);printf("MADE BY :");
    Sleep(500);
    gotoxy(40,20);printf("MADE BY : CAHYO NUGROHO 672018039");

    Sleep(5000);

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
    system("color 5c");
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
        strcpy(log[log_i].act, "Admin telah login");
        log_i++;
        system("cls");
        gotoxy(40,11);printf("====================================\n");
        gotoxy(40,12);printf("==========Berhasil Login!!==========\n");
        gotoxy(40,13);printf("====================================\n");
        Sleep(1000);
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
    //672018039
    int cek;
    system("color 4f");
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


void insert_data()
{
    int tmpdt;
    system("color 2d");
    void header()
    {
        gotoxy(40,4);printf("====================================\n");
        gotoxy(40,5);printf("        Menu Input Database\n");
        gotoxy(40,6);printf("++++++++++++++++++++++++++++++++++++\n");
        gotoxy(40,8);printf("====================================\n");
    }
    system("cls");
    header();
    gotoxy(40,9);printf("Memasukan berapa data? : \n");gotoxy(70,9);scanf("%d", &tc_data);
    for(int i = 0; i < tc_data; i++)
    {
        system("cls");
        header();
        gotoxy(40,10);printf(":: Data ke-%d : ", i+1);
        gotoxy(40,11);printf(":: Bahasa Indonesia : ");scanf("%s", &km[i].indo);
        gotoxy(40,12);printf(":: Bahasa Jawa      : ");scanf("%s", &km[i].jawa);
        gotoxy(40,13);printf(":: Bahasa Inggris   : ");scanf("%s", &km[i].inggris);
        gotoxy(40,14);printf(":: Bahasa Gaul      : ");scanf("%s", &km[i].gaul);
        gotoxy(40,15);printf(":: Bahasa Arti      : ");scanf("%s", &km[i].arti);

    }
    tmpdt = tc_data;
    char tmpstr[25];
    sprintf(tmpstr, "%d", tmpdt);
    char log_pre[] = "Admin memasukan ";
    char log_suf[] = " data";
    strcat(log_pre, tmpstr);
    strcat(log_pre, log_suf);

    strcpy(log[log_i].act, log_pre);
    log_i++;
}


void print_data()
{
    system("color 2f");
    system("cls");
    gotoxy(10,8);printf("=======================Berikut adalah data yang anda masukan===========================");
    gotoxy(10,9);printf("=======================================================================================");
    gotoxy(10,10);printf("Bahasa Indonesia");gotoxy(30,10);printf("Bahasa Jawa");gotoxy(50,10);printf("Bahasa Inggris");gotoxy(70,10);printf("Bahasa Gaul");gotoxy(90,10);printf("Artinya");
    gotoxy(10,11);printf("+-------------------------------------------------------------------------------------+");
    for(int i = 0; i < tc_data; i++)
    {
        gotoxy(10,13+i);printf("%s ", km[i].indo);
        gotoxy(30,13+i);printf("%s ", km[i].jawa);
        gotoxy(50,13+i);printf("%s ", km[i].inggris);
        gotoxy(70,13+i);printf("%s ", km[i].gaul);
        gotoxy(90,13+i);printf("%s ", km[i].arti);
    }
    strcpy(log[log_i].act, "Admin telah melihat data");
    log_i++;
    getch();
}

void add_data()
{
    void header()
    {
        gotoxy(40,4);printf("====================================\n");
        gotoxy(40,5);printf("         Menu Tambah Data\n");
        gotoxy(40,6);printf("++++++++++++++++++++++++++++++++++++\n");
        gotoxy(40,8);printf("====================================\n");
    }
    system("cls");
    header();
    gotoxy(40,11);printf(":: Bahasa Indonesia : ");scanf("%s", &km[tc_data].indo);
    gotoxy(40,12);printf(":: Bahasa Jawa      : ");scanf("%s", &km[tc_data].jawa);
    gotoxy(40,13);printf(":: Bahasa Inggris   : ");scanf("%s", &km[tc_data].inggris);
    gotoxy(40,14);printf(":: Bahasa Gaul      : ");scanf("%s", &km[tc_data].gaul);
    gotoxy(40,15);printf(":: Bahasa Arti      : ");scanf("%s", &km[tc_data].arti);

    char tmpstr[25];
    sprintf(tmpstr, "%s %s %s %s %s", km[tc_data].indo, km[tc_data].jawa, km[tc_data].inggris, km[tc_data].gaul, km[tc_data].arti);
    char log_pre[] = "Admin menambahkan ";
    char log_suf[] = " ke database";
    strcat(log_pre, tmpstr);
    strcat(log_pre, log_suf);

    strcpy(log[log_i].act, log_pre);
    log_i++;
    tc_data += 1;
}

void delete_data()
{
    char cc[25], stat = 'z';
    struct kamus tmp;
    void header()
    {
        gotoxy(40,4);printf("====================================\n");
        gotoxy(40,5);printf("         Menu Hapus Data\n");
        gotoxy(40,6);printf("++++++++++++++++++++++++++++++++++++\n");
        gotoxy(40,8);printf("====================================\n");
        gotoxy(15,9);printf("=======================Berikut adalah data yang anda masukan===========================");
        gotoxy(15,10);printf("=======================================================================================");
        gotoxy(15,11);printf("Bahasa Indonesia");gotoxy(40,11);printf("Bahasa Jawa");gotoxy(60,11);printf("Bahasa Inggris");gotoxy(80,11);printf("Bahasa Gaul");gotoxy(100,11);printf("Artinya");
        gotoxy(15,12);printf("+-------------------------------------------------------------------------------------+");
        for(int i = 0; i < tc_data; i++)
        {
            gotoxy(15,14+i);printf("%s ", km[i].indo);
            gotoxy(35,14+i);printf("%s ", km[i].jawa);
            gotoxy(55,14+i);printf("%s ", km[i].inggris);
            gotoxy(75,14+i);printf("%s ", km[i].gaul);
            gotoxy(95,14+i);printf("%s ", km[i].arti);
        }
    }
    system("cls");
    header();
    gotoxy(40,7);printf(":: Tekan sembarang untuk melanjutkan ");
    getch();
    system("cls");
    gotoxy(40,4);printf("====================================\n");
    gotoxy(40,5);printf("         Menu hapus Data\n");
    gotoxy(40,6);printf("++++++++++++++++++++++++++++++++++++\n");
    gotoxy(40,8);printf("====================================\n");
    gotoxy(40,7);printf(":: Mau hapus bahasa apa (Indonesia) : ");gotoxy(80,7);scanf("%s", &cc);
    char tmpstr[25];
    sprintf(tmpstr, "%s", cc);
    char log_pre[] = "Admin menghapus data ";
    char log_suf[] = " dari database";
    strcat(log_pre, tmpstr);
    strcat(log_pre, log_suf);
    strcpy(log[log_i].act, log_pre);
    log_i++;
    for(int i = 0; i < tc_data; i++)
    {
        if(strcmp(km[i].indo, cc) == 0)
        {
            gotoxy(10,13);printf(":: Berikut adalah data anda");
            gotoxy(10,14);printf("Bahasa Indonesia  : %s ", km[i].indo);
            gotoxy(10,15);printf("Bahasa Jawa       : %s ", km[i].jawa);
            gotoxy(10,16);printf("Bahasa Inggris    : %s ", km[i].inggris);
            gotoxy(10,17);printf("Bahasa Gaul       : %s ", km[i].gaul);
            gotoxy(10,18);printf("Arti              : %s ", km[i].arti);
            gotoxy(10,19);printf("Apakah anda yakin untuk hapus? (y/n) : ");
            gotoxy(50,19);scanf("%s", &stat);
            if(stat == 'y' || stat == 'Y')
            {
                for(int j = i; j < tc_data; j++)
                {
                    tmp = km[j];
                    km[j] = km[j+1];
                    km[j+1] = tmp;
                }
                gotoxy(10,20);printf(":: Data berhasil dihapus ::");
                getch();
                tc_data -= 1;
            }
        }
        if(strcmp(km[i].indo, cc) != 0 && i == tc_data)
        {
            gotoxy(10,13);printf(":: Data anda tidak ada ::");
            getch();
        }
    }
    system("cls");
}

void edit_data()
{
    char cc[25];
    void header()
    {
        gotoxy(40,4);printf("====================================\n");
        gotoxy(40,5);printf("         Menu Edit Data\n");
        gotoxy(40,6);printf("++++++++++++++++++++++++++++++++++++\n");
        gotoxy(40,8);printf("====================================\n");
        gotoxy(15,9);printf("====================== Berikut adalah data yang anda masukan ==========================");
        gotoxy(15,10);printf("=======================================================================================");
        gotoxy(15,11);printf("Bahasa Indonesia");gotoxy(35,11);printf("Bahasa Jawa");gotoxy(55,11);printf("Bahasa Inggris");gotoxy(75,11);printf("Bahasa Gaul");gotoxy(95,11);printf("Artinya");
        gotoxy(15,12);printf("+-------------------------------------------------------------------------------------+");
        for(int i = 0; i < tc_data; i++)
        {
            gotoxy(15,14+i);printf("%s ", km[i].indo);
            gotoxy(35,14+i);printf("%s ", km[i].jawa);
            gotoxy(55,14+i);printf("%s ", km[i].inggris);
            gotoxy(75,14+i);printf("%s ", km[i].gaul);
            gotoxy(95,14+i);printf("%s ", km[i].arti);
        }
    }

    system("cls");
    gotoxy(40,4);printf("====================================\n");
    gotoxy(40,5);printf("         Menu Edit Data\n");
    gotoxy(40,6);printf("++++++++++++++++++++++++++++++++++++\n");
    gotoxy(40,8);printf("====================================\n");
    gotoxy(40,9);printf(":: indonesia/jawa/inggris/gaul/arti :: ");
    gotoxy(40,7);printf(":: Mau Edit bahasa apa : ");gotoxy(70,7);scanf("%s", &cc);
    if(strcmp(cc, "indonesia") == 0)
    {
        char edd[25];
        char temp[25];
        system("cls");
        gotoxy(40,4);printf("==========================================\n");
        gotoxy(40,5);printf("Berikut adalah data dalam bahasa indonesia\n");
        gotoxy(40,6);printf("++++++++++++++++++++++++++++++++++++++++++\n");
        for(int i = 0; i < tc_data; i++)
        {
            gotoxy(40,10+i);printf(":: %s ", km[i].indo);
        }
        getch();
        system("cls");
        gotoxy(40,7);printf(":: Mau edit kata apa : ");gotoxy(70,7);scanf("%s", &edd);
        for(int i = 0; i < tc_data; i++)
        {
            if(strcmp(km[i].indo, edd) == 0)
            {
                system("cls");
                gotoxy(40,7);printf(":: Edit jadi apa : ");gotoxy(70,7);scanf("%s", &temp);
                strcpy(km[i].indo, temp);
                system("cls");
                gotoxy(40,7);printf(":: Berhasil di edit ");
                break;
            }
            if(strcmp(km[i].indo, cc) != 0 && i == tc_data-1)
            {
                system("cls");
                gotoxy(40,7);printf(":: Data anda tidak ada ::");
            }
        }
        char tmpstr[25];
        sprintf(tmpstr, "%s menjadi %s", edd,temp);
        char log_pre[] = "Admin mengedit data ";
        char log_suf[] = " dari database";
        strcat(log_pre, tmpstr);
        strcat(log_pre, log_suf);
        strcpy(log[log_i].act, log_pre);
        log_i++;
    }
    else if(strcmp(cc, "jawa") == 0)
    {
        char edd[25];
        char temp[25];
        system("cls");
        gotoxy(40,4);printf("==========================================\n");
        gotoxy(40,5);printf("Berikut adalah data dalam bahasa jawa\n");
        gotoxy(40,6);printf("++++++++++++++++++++++++++++++++++++++++++\n");
        for(int i = 0; i < tc_data; i++)
        {
            gotoxy(40,10+i);printf(":: %s ", km[i].jawa);
        }
        getch();
        system("cls");
        gotoxy(40,7);printf(":: Mau edit kata apa : ");gotoxy(70,7);scanf("%s", &edd);
        for(int i = 0; i < tc_data; i++)
        {
            if(strcmp(km[i].jawa, edd) == 0)
            {
                system("cls");
                gotoxy(40,7);printf(":: Edit jadi apa : ");gotoxy(70,7);scanf("%s", &temp);
                strcpy(km[i].jawa, temp);
                system("cls");
                gotoxy(40,7);printf(":: Berhasil di edit ");
                break;
            }
            if(strcmp(km[i].jawa, cc) != 0 && i == tc_data-1)
            {
                system("cls");
                gotoxy(40,7);printf(":: Data anda tidak ada ::");
            }
        }
        char tmpstr[25];
        sprintf(tmpstr, "%s menjadi %s", edd,temp);
        char log_pre[] = "Admin mengedit data ";
        char log_suf[] = " dari database";
        strcat(log_pre, tmpstr);
        strcat(log_pre, log_suf);
        strcpy(log[log_i].act, log_pre);
        log_i++;
    }
    else if(strcmp(cc, "inggris") == 0)
    {
        char edd[25];
        char temp[25];
        system("cls");
        gotoxy(40,4);printf("==========================================\n");
        gotoxy(40,5);printf("Berikut adalah data dalam bahasa inggris\n");
        gotoxy(40,6);printf("++++++++++++++++++++++++++++++++++++++++++\n");
        for(int i = 0; i < tc_data; i++)
        {
            gotoxy(40,10+i);printf(":: %s ", km[i].inggris);
        }
        getch();
        system("cls");
        gotoxy(40,7);printf(":: Mau edit kata apa : ");gotoxy(70,7);scanf("%s", &edd);
        for(int i = 0; i < tc_data; i++)
        {
            if(strcmp(km[i].inggris, edd) == 0)
            {
                system("cls");
                gotoxy(40,7);printf(":: Edit jadi apa : ");gotoxy(70,7);scanf("%s", &temp);
                strcpy(km[i].inggris, temp);
                system("cls");
                gotoxy(40,7);printf(":: Berhasil di edit ");
                break;
            }
            if(strcmp(km[i].inggris, cc) != 0 && i == tc_data-1)
            {
                system("cls");
                gotoxy(40,7);printf(":: Data anda tidak ada ::");
            }
        }
        char tmpstr[25];
        sprintf(tmpstr, "%s menjadi %s", edd,temp);
        char log_pre[] = "Admin mengedit data ";
        char log_suf[] = " dari database";
        strcat(log_pre, tmpstr);
        strcat(log_pre, log_suf);
        strcpy(log[log_i].act, log_pre);
        log_i++;
    }
    else if(strcmp(cc, "gaul") == 0)
    {
        char edd[25];
        char temp[25];
        system("cls");
        gotoxy(40,4);printf("==========================================\n");
        gotoxy(40,5);printf("Berikut adalah data dalam bahasa gaul\n");
        gotoxy(40,6);printf("++++++++++++++++++++++++++++++++++++++++++\n");
        for(int i = 0; i < tc_data; i++)
        {
            gotoxy(40,10+i);printf(":: %s ", km[i].gaul);
        }
        getch();
        system("cls");
        gotoxy(40,7);printf(":: Mau edit kata apa : ");gotoxy(70,7);scanf("%s", &edd);
        for(int i = 0; i < tc_data; i++)
        {
            if(strcmp(km[i].gaul, edd) == 0)
            {
                system("cls");
                gotoxy(40,7);printf(":: Edit jadi apa : ");gotoxy(70,7);scanf("%s", &temp);
                strcpy(km[i].gaul, temp);
                system("cls");
                gotoxy(40,7);printf(":: Berhasil di edit ");
                break;
            }
            if(strcmp(km[i].gaul, cc) != 0 && i == tc_data-1)
            {
                system("cls");
                gotoxy(40,7);printf(":: Data anda tidak ada ::");
            }
        }
        char tmpstr[25];
        sprintf(tmpstr, "%s menjadi %s", edd,temp);
        char log_pre[] = "Admin mengedit data ";
        char log_suf[] = " dari database";
        strcat(log_pre, tmpstr);
        strcat(log_pre, log_suf);
        strcpy(log[log_i].act, log_pre);
        log_i++;
    }
    else if(strcmp(cc, "arti") == 0)
    {
        char edd[25];
        char temp[25];
        system("cls");
        gotoxy(40,4);printf("==========================================\n");
        gotoxy(40,5);printf("Berikut adalah data dalam bahasa arti\n");
        gotoxy(40,6);printf("++++++++++++++++++++++++++++++++++++++++++\n");
        for(int i = 0; i < tc_data; i++)
        {
            gotoxy(40,10+i);printf(":: %s ", km[i].arti);
        }
        getch();
        system("cls");
        gotoxy(40,7);printf(":: Mau edit kata apa : ");gotoxy(70,7);scanf("%s", &edd);
        for(int i = 0; i < tc_data; i++)
        {
            if(strcmp(km[i].arti, edd) == 0)
            {
                system("cls");
                gotoxy(40,7);printf(":: Edit jadi apa : ");gotoxy(70,7);scanf("%s", &temp);
                strcpy(km[i].arti, temp);
                system("cls");
                gotoxy(40,7);printf(":: Berhasil di edit ");
                break;
            }
            if(strcmp(km[i].arti, cc) != 0 && i == tc_data-1)
            {
                system("cls");
                gotoxy(40,7);printf(":: Data anda tidak ada ::");
            }
        }
        char tmpstr[25];
        sprintf(tmpstr, "%s menjadi %s", edd,temp);
        char log_pre[] = "Admin mengedit data ";
        char log_suf[] = " dari database";
        strcat(log_pre, tmpstr);
        strcat(log_pre, log_suf);
        strcpy(log[log_i].act, log_pre);
        log_i++;
    }
    else
    {
        system("cls");
        gotoxy(40,9);printf(":: Pilihan anda tidak ada ::");
    }
    getch();
}

void search_data()
{
    char cc[25];
    system("cls");
    gotoxy(40,4);printf("====================================\n");
    gotoxy(40,5);printf("         Menu Cari Data\n");
    gotoxy(40,6);printf("++++++++++++++++++++++++++++++++++++\n");
    gotoxy(40,8);printf("====================================\n");
    gotoxy(40,9);printf(":: indonesia/jawa/inggris/gaul/arti :: ");
    gotoxy(40,7);printf(":: Mau cari berdasarkan bahasa apa : ");gotoxy(80,7);scanf("%s", &cc);
    if(strcmp(cc, "indonesia") == 0)
    {
        char scc[25];
        system("cls");
        gotoxy(40,4);printf("==========================================\n");
        gotoxy(40,5);printf("           Mau cari kata apa?\n");
        gotoxy(40,7);printf("==========================================\n");
        gotoxy(40,9);printf("==========================================\n");
        gotoxy(40,8);printf("Masukan kata anda dalam bahasa indonesia : \n");gotoxy(85,8);scanf("%s", &scc);
        char tmpstr[25];
        sprintf(tmpstr, "%s", scc);
        char log_pre[] = "Admin mencari data ";
        char log_suf[] = " dari database";
        strcat(log_pre, tmpstr);
        strcat(log_pre, log_suf);
        strcpy(log[log_i].act, log_pre);
        log_i++;
        for(int i = 0; i < tc_data; i++)
        {
            if(strcmp(km[i].indo, scc) == 0)
            {
                system("cls");
                gotoxy(10,8);printf("=========================Berikut adalah data yang anda cari============================");
                gotoxy(10,9);printf("=======================================================================================");
                gotoxy(10,10);printf("Bahasa Indonesia");gotoxy(30,10);printf("Bahasa Jawa");gotoxy(50,10);printf("Bahasa Inggris");gotoxy(70,10);printf("Bahasa Gaul");gotoxy(90,10);printf("Artinya");
                gotoxy(10,11);printf("+-------------------------------------------------------------------------------------+");
                gotoxy(10,13);printf("%s ", km[i].indo);
                gotoxy(30,13);printf("%s ", km[i].jawa);
                gotoxy(50,13);printf("%s ", km[i].inggris);
                gotoxy(70,13);printf("%s ", km[i].gaul);
                gotoxy(90,13);printf("%s ", km[i].arti);
                break;
            }
            if(strcmp(km[i].indo, scc) != 0 && i == tc_data - 1)
            {
                system("cls");
                gotoxy(10,8);printf(":: Data Tidak Ditemukan ::");
            }
        }
    }
    else if(strcmp(cc, "jawa") == 0)
    {
        char scc[25];
        system("cls");
        gotoxy(40,4);printf("==========================================\n");
        gotoxy(40,5);printf("           Mau cari kata apa?\n");
        gotoxy(40,7);printf("==========================================\n");
        gotoxy(40,9);printf("==========================================\n");
        gotoxy(40,8);printf("Masukan kata anda dalam bahasa jawa : \n");gotoxy(80,8);scanf("%s", &scc);
        for(int i = 0; i < tc_data; i++)
        {
            if(strcmp(km[i].jawa, scc) == 0)
            {
                system("cls");
                gotoxy(10,8);printf("=========================Berikut adalah data yang anda cari============================");
                gotoxy(10,9);printf("=======================================================================================");
                gotoxy(10,10);printf("Bahasa Indonesia");gotoxy(30,10);printf("Bahasa Jawa");gotoxy(50,10);printf("Bahasa Inggris");gotoxy(70,10);printf("Bahasa Gaul");gotoxy(90,10);printf("Artinya");
                gotoxy(10,11);printf("+-------------------------------------------------------------------------------------+");
                gotoxy(10,13);printf("%s ", km[i].indo);
                gotoxy(30,13);printf("%s ", km[i].jawa);
                gotoxy(50,13);printf("%s ", km[i].inggris);
                gotoxy(70,13);printf("%s ", km[i].gaul);
                gotoxy(90,13);printf("%s ", km[i].arti);
                break;
            }
            if(strcmp(km[i].jawa, scc) != 0 && i == tc_data - 1)
            {
                system("cls");
                gotoxy(10,8);printf(":: Data Tidak Ditemukan ::");
            }
        }
    }
    else if(strcmp(cc, "inggris") == 0)
    {
        char scc[25];
        system("cls");
        gotoxy(40,4);printf("==========================================\n");
        gotoxy(40,5);printf("           Mau cari kata apa?\n");
        gotoxy(40,7);printf("==========================================\n");
        gotoxy(40,9);printf("==========================================\n");
        gotoxy(40,8);printf("Masukan kata anda dalam bahasa inggris : \n");gotoxy(85,8);scanf("%s", &scc);
        for(int i = 0; i < tc_data; i++)
        {
            if(strcmp(km[i].inggris, scc) == 0)
            {
                system("cls");
                gotoxy(10,8);printf("=========================Berikut adalah data yang anda cari============================");
                gotoxy(10,9);printf("=======================================================================================");
                gotoxy(10,10);printf("Bahasa Indonesia");gotoxy(30,10);printf("Bahasa Jawa");gotoxy(50,10);printf("Bahasa Inggris");gotoxy(70,10);printf("Bahasa Gaul");gotoxy(90,10);printf("Artinya");
                gotoxy(10,11);printf("+-------------------------------------------------------------------------------------+");
                gotoxy(10,13);printf("%s ", km[i].indo);
                gotoxy(30,13);printf("%s ", km[i].jawa);
                gotoxy(50,13);printf("%s ", km[i].inggris);
                gotoxy(70,13);printf("%s ", km[i].gaul);
                gotoxy(90,13);printf("%s ", km[i].arti);
                break;
            }
            if(strcmp(km[i].inggris, scc) != 0 && i == tc_data - 1)
            {
                system("cls");
                gotoxy(10,8);printf(":: Data Tidak Ditemukan ::");
            }
        }
    }
    else if(strcmp(cc, "gaul") == 0)
    {
        char scc[25];
        system("cls");
        gotoxy(40,4);printf("==========================================\n");
        gotoxy(40,5);printf("           Mau cari kata apa?\n");
        gotoxy(40,7);printf("==========================================\n");
        gotoxy(40,9);printf("==========================================\n");
        gotoxy(40,8);printf("Masukan kata anda dalam bahasa gaul : \n");gotoxy(85,8);scanf("%s", &scc);
        for(int i = 0; i < tc_data; i++)
        {
            if(strcmp(km[i].gaul, scc) == 0)
            {
                system("cls");
                gotoxy(10,8);printf("=========================Berikut adalah data yang anda cari============================");
                gotoxy(10,9);printf("=======================================================================================");
                gotoxy(10,10);printf("Bahasa Indonesia");gotoxy(30,10);printf("Bahasa Jawa");gotoxy(50,10);printf("Bahasa Inggris");gotoxy(70,10);printf("Bahasa Gaul");gotoxy(90,10);printf("Artinya");
                gotoxy(10,11);printf("+-------------------------------------------------------------------------------------+");
                gotoxy(10,13);printf("%s ", km[i].indo);
                gotoxy(30,13);printf("%s ", km[i].jawa);
                gotoxy(50,13);printf("%s ", km[i].inggris);
                gotoxy(70,13);printf("%s ", km[i].gaul);
                gotoxy(90,13);printf("%s ", km[i].arti);
                break;
            }
            if(strcmp(km[i].gaul, scc) != 0 && i == tc_data - 1)
            {
                system("cls");
                gotoxy(10,8);printf(":: Data Tidak Ditemukan ::");
            }
        }
    }
    else if(strcmp(cc, "arti") == 0)
    {
        char scc[25];
        system("cls");
        gotoxy(40,4);printf("==========================================\n");
        gotoxy(40,5);printf("           Mau cari kata apa?\n");
        gotoxy(40,7);printf("==========================================\n");
        gotoxy(40,9);printf("==========================================\n");
        gotoxy(40,8);printf("Masukan kata anda dalam bahasa arti : \n");gotoxy(85,8);scanf("%s", &scc);
        for(int i = 0; i < tc_data; i++)
        {
            if(strcmp(km[i].arti, scc) == 0)
            {
                system("cls");
                gotoxy(10,8);printf("=========================Berikut adalah data yang anda cari============================");
                gotoxy(10,9);printf("=======================================================================================");
                gotoxy(10,10);printf("Bahasa Indonesia");gotoxy(30,10);printf("Bahasa Jawa");gotoxy(50,10);printf("Bahasa Inggris");gotoxy(70,10);printf("Bahasa Gaul");gotoxy(90,10);printf("Artinya");
                gotoxy(10,11);printf("+-------------------------------------------------------------------------------------+");
                gotoxy(10,13);printf("%s ", km[i].indo);
                gotoxy(30,13);printf("%s ", km[i].jawa);
                gotoxy(50,13);printf("%s ", km[i].inggris);
                gotoxy(70,13);printf("%s ", km[i].gaul);
                gotoxy(90,13);printf("%s ", km[i].arti);
                break;
            }
            if(strcmp(km[i].arti, scc) != 0 && i == tc_data - 1)
            {
                system("cls");
                gotoxy(10,8);printf(":: Data Tidak Ditemukan ::");
            }
        }
    }
    else
    {
        system("cls");
        gotoxy(40,9);printf(":: Pilihan anda tidak ada ::");
    }
    getch();
}

void sort_data()
{
    char cc[25];
    system("cls");
    struct kamus temp;
    gotoxy(40,4);printf("====================================\n");
    gotoxy(40,5);printf("          Menu Sort Data\n");
    gotoxy(40,6);printf("++++++++++++++++++++++++++++++++++++\n");
    gotoxy(40,8);printf("====================================\n");
    gotoxy(40,9);printf(":: indonesia/jawa/inggris/gaul/arti :: ");
    gotoxy(40,7);printf(":: Mau urutkan berdasarkan bahasa apa : ");gotoxy(80,7);scanf("%s", &cc);
    char tmpstr[25];
    sprintf(tmpstr, "%s", cc);
    char log_pre[] = "Admin mengurutkan data berdasarkan bahasa ";
    char log_suf[] = " dari database";
    strcat(log_pre, tmpstr);
    strcat(log_pre, log_suf);
    strcpy(log[log_i].act, log_pre);
    log_i++;
    if(strcmp(cc, "indonesia") == 0)
    {
        for(int i = 0; i <tc_data - 1; i++)
        {
            for(int j = i+1; j <tc_data; j++)
            {
                if(strcmp(km[i].indo, km[j].indo) > 0)
                {
                    temp = km[i];
                    km[i] = km[j];
                    km[j] = temp;
                }
            }
        }
        system("cls");
        for(int i = 0; i < tc_data; i++)
        {
            gotoxy(10,8);printf("=========================Berikut adalah data yang diurutukan===========================");
            gotoxy(10,9);printf("=======================================================================================");
            gotoxy(10,10);printf("Bahasa Indonesia");gotoxy(30,10);printf("Bahasa Jawa");gotoxy(50,10);printf("Bahasa Inggris");gotoxy(70,10);printf("Bahasa Gaul");gotoxy(90,10);printf("Artinya");
            gotoxy(10,11);printf("+-------------------------------------------------------------------------------------+");
            gotoxy(10,13+i);printf("%s ", km[i].indo);
            gotoxy(30,13+i);printf("%s ", km[i].jawa);
            gotoxy(50,13+i);printf("%s ", km[i].inggris);
            gotoxy(70,13+i);printf("%s ", km[i].gaul);
            gotoxy(90,13+i);printf("%s ", km[i].arti);
        }
    }
    else if(strcmp(cc, "jawa") == 0)
    {
        for(int i = 0; i <tc_data - 1; i++)
        {
            for(int j = i+1; j <tc_data; j++)
            {
                if(strcmp(km[i].jawa, km[j].jawa) > 0)
                {
                    temp = km[i];
                    km[i] = km[j];
                    km[j] = temp;
                }
            }
        }
        system("cls");
        for(int i = 0; i < tc_data; i++)
        {
            gotoxy(10,8);printf("=========================Berikut adalah data yang diurutukan===========================");
            gotoxy(10,9);printf("=======================================================================================");
            gotoxy(10,10);printf("Bahasa Indonesia");gotoxy(30,10);printf("Bahasa Jawa");gotoxy(50,10);printf("Bahasa Inggris");gotoxy(70,10);printf("Bahasa Gaul");gotoxy(90,10);printf("Artinya");
            gotoxy(10,11);printf("+-------------------------------------------------------------------------------------+");
            gotoxy(10,13+i);printf("%s ", km[i].indo);
            gotoxy(30,13+i);printf("%s ", km[i].jawa);
            gotoxy(50,13+i);printf("%s ", km[i].inggris);
            gotoxy(70,13+i);printf("%s ", km[i].gaul);
            gotoxy(90,13+i);printf("%s ", km[i].arti);
        }
    }
    else if(strcmp(cc, "inggris") == 0)
    {
        for(int i = 0; i <tc_data - 1; i++)
        {
            for(int j = i+1; j <tc_data; j++)
            {
                if(strcmp(km[i].inggris, km[j].inggris) > 0)
                {
                    temp = km[i];
                    km[i] = km[j];
                    km[j] = temp;
                }
            }
        }
        system("cls");
        for(int i = 0; i < tc_data; i++)
        {
            gotoxy(10,8);printf("=========================Berikut adalah data yang diurutukan===========================");
            gotoxy(10,9);printf("=======================================================================================");
            gotoxy(10,10);printf("Bahasa Indonesia");gotoxy(30,10);printf("Bahasa Jawa");gotoxy(50,10);printf("Bahasa Inggris");gotoxy(70,10);printf("Bahasa Gaul");gotoxy(90,10);printf("Artinya");
            gotoxy(10,11);printf("+-------------------------------------------------------------------------------------+");
            gotoxy(10,13+i);printf("%s ", km[i].indo);
            gotoxy(30,13+i);printf("%s ", km[i].jawa);
            gotoxy(50,13+i);printf("%s ", km[i].inggris);
            gotoxy(70,13+i);printf("%s ", km[i].gaul);
            gotoxy(90,13+i);printf("%s ", km[i].arti);
        }
    }
    else if(strcmp(cc, "gaul") == 0)
    {
        for(int i = 0; i <tc_data - 1; i++)
        {
            for(int j = i+1; j <tc_data; j++)
            {
                if(strcmp(km[i].gaul, km[j].gaul) > 0)
                {
                    temp = km[i];
                    km[i] = km[j];
                    km[j] = temp;
                }
            }
        }
        system("cls");
        for(int i = 0; i < tc_data; i++)
        {
            gotoxy(10,8);printf("=========================Berikut adalah data yang diurutukan===========================");
            gotoxy(10,9);printf("=======================================================================================");
            gotoxy(10,10);printf("Bahasa Indonesia");gotoxy(30,10);printf("Bahasa Jawa");gotoxy(50,10);printf("Bahasa Inggris");gotoxy(70,10);printf("Bahasa Gaul");gotoxy(90,10);printf("Artinya");
            gotoxy(10,11);printf("+-------------------------------------------------------------------------------------+");
            gotoxy(10,13+i);printf("%s ", km[i].indo);
            gotoxy(30,13+i);printf("%s ", km[i].jawa);
            gotoxy(50,13+i);printf("%s ", km[i].inggris);
            gotoxy(70,13+i);printf("%s ", km[i].gaul);
            gotoxy(90,13+i);printf("%s ", km[i].arti);
        }
    }
    else if(strcmp(cc, "arti") == 0)
    {
        for(int i = 0; i <tc_data - 1; i++)
        {
            for(int j = i+1; j <tc_data; j++)
            {
                if(strcmp(km[i].arti, km[j].arti) > 0)
                {
                    temp = km[i];
                    km[i] = km[j];
                    km[j] = temp;
                }
            }
        }
        system("cls");
        for(int i = 0; i < tc_data; i++)
        {
            gotoxy(10,8);printf("=========================Berikut adalah data yang diurutukan===========================");
            gotoxy(10,9);printf("=======================================================================================");
            gotoxy(10,10);printf("Bahasa Indonesia");gotoxy(30,10);printf("Bahasa Jawa");gotoxy(50,10);printf("Bahasa Inggris");gotoxy(70,10);printf("Bahasa Gaul");gotoxy(90,10);printf("Artinya");
            gotoxy(10,11);printf("+-------------------------------------------------------------------------------------+");
            gotoxy(10,13+i);printf("%s ", km[i].indo);
            gotoxy(30,13+i);printf("%s ", km[i].jawa);
            gotoxy(50,13+i);printf("%s ", km[i].inggris);
            gotoxy(70,13+i);printf("%s ", km[i].gaul);
            gotoxy(90,13+i);printf("%s ", km[i].arti);
        }
    }
    else
    {
        system("cls");
        gotoxy(40,9);printf(":: Pilihan anda tidak ada ::");
    }
    getch();
}

void log_activity()
{
    system("cls");
    gotoxy(40,11);printf("== Berikut adalah log aktivitas admin ==\n");
    gotoxy(40,12);printf("                                        \n");
    gotoxy(40,13);printf("========================================\n");
    gotoxy(45,14);get_time();
    gotoxy(40,15);printf("========================================\n");
    for(int i = 0; i < log_i; i++)
    {
        gotoxy(40,17+i);printf("%d", i+1);gotoxy(45,17+i);printf("%s", log[i].act);
    }
    getch();
}


void main()
{
    int tc;
    login();
    while(1)
    {
        menu();
        gotoxy(40,22);printf("| Masukan pilihan anda :               |\n");
        gotoxy(65,22);scanf("%d", &tc);
        switch(tc)
        {
        case 1:
            insert_data();
            break;
        case 2:
            print_data();
            break;
        case 3:
            add_data();
            break;
        case 4:
            delete_data();
            break;
        case 5:
            edit_data();
            break;
        case 6:
            search_data();
            break;
        case 7:
            sort_data();
            break;
        case 8:
            log_activity();
            break;
        case 9:
            quit_program();
            break;
        }
    }
}
