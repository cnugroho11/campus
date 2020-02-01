
import java.util.Scanner;

public class segitiiga {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Masukan tinggi segitiga ");
        int a;
        a = in.nextInt();
        for (int b = 0; b < a / 2; b++) {
            for (int c = a; c > b; c--) {
                System.out.print(" ");
            }
            for (int d = 0; d <= b * 2; d++) {
                System.out.print("*");
            }
            System.out.println("");
        }
        if (a % 2 == 0) {
            int e;
            for (int d = 0; d < a / 2; d++) {
                for (e = a / 2; e > d; e--) {
                    System.out.print(" ");
                }
                for (int f = 0; f <= a + e + d; f++) {
                    if (f == 0 || f == a + d * 2) {
                        System.out.print("*");
                    } else if (f == ((a + e + d) + 2) / 4 || f == (a + e + d) * 3 / 4) {
                        System.out.print("3");
                    } else if (f == (a + e + d) / 2) {
                        System.out.print("2");
                    } else if (f >= 1) {
                        System.out.print("#");
                    }
                }
                System.out.println("");
            }
        } else {
            int e;
            for (int d = 0; d < a / 2 + 1; d++) {
                for (e = a / 2; e + 1 > d; e--) {
                    System.out.print(" ");
                }
                for (int f = 0; f <= a + e + d; f++) {
                    if (f == 0 || f == a + d * 2 - 1) {
                        System.out.print("*");
                    } else if (f == ((a + e + d) + 2) / 4 || f == (a + e + d) * 3 / 4) {
                        System.out.print("3");
                    } else if (f == (a + e + d) / 2) {
                        System.out.print("2");
                    } else if (f >= 1) {
                        System.out.print("#");
                    }
                }
                System.out.println("");
            }
        }
    }
}
