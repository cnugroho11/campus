
import java.util.Scanner;

public class huruf {

    public static void main(String[] args) {

        String in, jadi;
        Scanner sc = new Scanner(System.in);
        System.out.print("Masukan kalimat : ");
        in = sc.nextLine();
        System.out.println("Kalimat anda : " + in);
        jadi = in.replace(" ", "_").replace("a", "A").replace("i", "I").
                replace("u", "U").replace("e", "E").replace("o", "O");
        System.out.println("Kalimat setelah di ubah : " + jadi);
        System.out.println("");
    }
}
