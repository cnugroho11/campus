package javaapplication9;

import java.util.Scanner;

public class JavaApplication9 {

    //variabel
    static String[] string_a = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh",
        "delapan", "sembilan", "sepuluh", "sebelas"};

    //method
    static void tampilan() {
        System.out.println("===tugas string===");
        System.out.println("1. backspace");
        System.out.println("2. int to string");
        System.out.println("3. palindrom");
        System.out.println("4. exit");
    }

    public static String int_string(Long an) {
        if (an < 12) {
            return string_a[an.intValue()];
        } else if (an >= 12 && an < 20) {
            return string_a[an.intValue() % 10] + " belas";
        } else if (an >= 20 && an <= 99) {
            return int_string(an / 10) + " puluh " + string_a[an.intValue() % 10];
        } else if (an == 100) {
            return "seratus";
        } else if (an > 99 && an <= 999) {
            if (an > 199) {
                return int_string(an / 100) + " ratus " + int_string(an % 100);
            } else {
                return "seratus " + int_string(an % 100);
            }
        } else if (an == 1000) {
            return "seribu";
        } else if (an > 999 && an < 9999) {
            if (an > 1999) {
                return int_string(an / 1000) + " ribu " + int_string(an % 1000);
            } else {
                return "seribu " + int_string(an % 1000);
            }
        } else if (an == 10000) {
            return string_a[10] + " ribu";
        }
        return "";
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String save_pal, balik = "";
        int x, y, cek = 0;
        String input1, jadi;
        Long int_in;
        do {
            tampilan();
            System.out.print("pilihan : ");
            x = in.nextInt();
            switch (x) {
                case 1:
                    System.out.print("Masukan string : ");
                    input1 = in.next();
                    char kal[] = input1.toCharArray();
                    for (int i = input1.length() - 1; i >= 0; i--) {
                        if (kal[i] == '<') {
                            kal[i] = ' ';
                            cek++;
                        } else if (cek > 0) {
                            kal[i] = ' ';
                            cek--;
                        }
                    }
                    jadi = new String(kal);
                    System.out.println("kalimat jadi : " + jadi.replaceAll(" ", ""));
                    break;
                case 2:
                    System.out.print("Masukan int : ");
                    int_in = in.nextLong();
                    int_string(int_in);
                    System.out.println("kalimat : " + int_string(int_in));
                    break;
                case 3:
                    System.out.print("Masukan test-case : ");
                    y = in.nextInt();
                    String pal[] = new String[y];
                    for (int i = 0; i < y; i++) {
                        System.out.print("Test-case ke " + (i + 1) + ": ");
                        pal[i] = in.next();
                    }
                    for (int a = 0; a < y; a++) {
                        for (int j = pal[a].length() - 1; j >= 0; j--) {
                            save_pal = pal[a];
                            balik = balik + save_pal.charAt(j);
                        }
                        System.out.println("test-case ke : " + (a + 1));
                        if (pal[a].equals(balik)) {
                            System.out.println("True (" + balik + ")");
                        } else {
                            System.out.println("False (" + balik + ")");
                        }
                        balik = "";
                    }
                    break;
                case 4:
                    System.exit(0);
            }
        } while (0 == 0);

    }
}
