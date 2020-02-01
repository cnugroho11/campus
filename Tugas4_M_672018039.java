package javaapplication2;

import java.util.Scanner;

public class JavaApplication2 {

    static void tampilan() {
        System.out.println("Pilihan Menu");
        System.out.println("1. Kalkulator Matrix");
        System.out.println("2. Oddities");
        System.out.println("3. Dice Game");
        System.out.println("4. Exit");
    }

    public static void main(String[] args) {
        int x, y, z;
        Scanner in = new Scanner(System.in);
        do {
            tampilan();
            System.out.print("Pilih ");
            x = in.nextInt();
            switch (x) {
                case 1:
                    int[][] matrix_kali = new int[2][2];
                    int[][] matrix1 = new int[2][2];
                    System.out.println("Masukan matrix #A ");
                    System.out.print("masukan matrix 0,0 ");
                    matrix1[0][0] = in.nextInt();
                    System.out.print("masukan matrix 0,1 ");
                    matrix1[0][1] = in.nextInt();
                    System.out.print("masukan matrix 1,0 ");
                    matrix1[1][0] = in.nextInt();
                    System.out.print("masukan matrix 1,1 ");
                    matrix1[1][1] = in.nextInt();
                    //======================================
                    int[][] matrix2 = new int[2][2];
                    System.out.println("Masukan matrix #B ");
                    System.out.print("masukan matrix 0,0 ");
                    matrix2[0][0] = in.nextInt();
                    System.out.print("masukan matrix 0,1 ");
                    matrix2[0][1] = in.nextInt();
                    System.out.print("masukan matrix 1,0 ");
                    matrix2[1][0] = in.nextInt();
                    System.out.print("masukan matrix 1,1 ");
                    matrix2[1][1] = in.nextInt();
                    System.out.println("==Matrix #A adalah== ");
                    for (int i = 0; i < matrix1.length; i++) {
                        for (int j = 0; j < matrix1.length; j++) {
                            System.out.print(matrix1[i][j] + "\t");
                        }
                        System.out.println("");
                    }
                    System.out.println("==Matrix #B adalah== ");
                    for (int k = 0; k < matrix2.length; k++) {
                        for (int l = 0; l < matrix2.length; l++) {
                            System.out.print(matrix2[k][l] + "\t");
                        }
                        System.out.println("");
                    }
                    System.out.println("Penjumlahan Matrix");
                    for (int a = 0; a < matrix1.length; a++) {
                        for (int b = 0; b < matrix1.length; b++) {
                            int tambah = matrix1[a][b] + matrix2[a][b];
                            System.out.print(tambah + "\t");
                        }
                        System.out.println("");
                    }
                    System.out.println("Pengurangan Matrix");
                    for (int c = 0; c < matrix1.length; c++) {
                        for (int d = 0; d < matrix2.length; d++) {
                            int kurang = matrix1[c][d] - matrix2[c][d];
                            System.out.print(kurang + "\t");
                        }
                        System.out.println("");
                    }
                    System.out.println("Perkalian Matrix");
                    int hasil = 0;
                    for (int i = 0; i < matrix_kali.length; i++) {
                        for (int j = 0; j < matrix_kali.length; j++) {
                            for (int k = 0; k < matrix_kali.length; k++) {
                                hasil = hasil + matrix1[i][k] * matrix2[k][j];
                            }
                            matrix_kali[i][j] = hasil;
                            hasil = 0;
                        }
                    }
                    for (int i = 0; i < matrix_kali.length; i++) {
                        for (int j = 0; j < matrix_kali.length; j++) {
                            System.out.print(matrix_kali[i][j] + "\t");
                        }
                        System.out.println("");
                        System.out.println("");

                    }
                    break;
                case 2:
                    System.out.print("masukan jumlah tes-case : ");
                    x = in.nextInt();
                    int[] odd_even = new int[x];
                    for (int i = 0; i < odd_even.length; i++) {
                        System.out.print("masukan angka ke " + (i + 1) + " ");
                        odd_even[i] = in.nextInt();
                    }
                    System.out.println("====================");
                    for (int i = 0; i < odd_even.length; i++) {
                        System.out.print("angka " + (i + 1) + " ");
                        if (odd_even[i] % 2 == 0) {
                            System.out.println("(even)");
                        } else {
                            System.out.println("(odd)");
                        }
                    }
                    System.out.println("");
                    break;
                case 3:
                    System.out.print("masukan jumlah tes-case ");
                    z = in.nextInt();
                    int a = 0;
                    int test1[] = new int[z];
                    int test2[] = new int[z];
                    int[] nilai_jojo = new int[100];
                    int[] nilai_juan = new int[100];
                    for (int i = 0; i < test1.length; i++) {
                        System.out.println("test case #" + (i + 1));
                        System.out.print("masukan jumlah ronde ");
                        a = in.nextInt();
                        for (int j = 0; j < a; j++) {
                            System.out.println("ronde " + (j + 1));
                            System.out.print("masukan dadu jojo ");
                            nilai_jojo[j] = in.nextInt();
                            System.out.print("masukan dadu juan ");
                            nilai_juan[j] = in.nextInt();
                        }
                    }
                    for (int i = 0; i < test1.length; i++) {
                        int sum1 = 0;
                        int sum2 = 0;
                        for (int nilai1 : nilai_jojo) {
                            sum1 += nilai1;
                        }
                        for (int nilai2 : nilai_juan) {
                            sum2 += nilai2;
                        }
                        System.out.println("hasil test-case " + (i + 1));
                        if(sum1>sum2){
                            System.out.println("jojo win");
                        }else if (sum1<sum2){
                            System.out.println("juan win");
                        } else if (sum1==sum2){
                            System.out.println("tie");
                        }   
                    }break;
                case 4 :
                    System.exit(0);
                    break;
            }
        } while (0 == 0);
    }
}
