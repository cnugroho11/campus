
import java.util.Scanner;

public class Tester {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a;
        int b = 0;
        int c;
        int x;
        Binatang bi = new Binatang();
        Anjing an = new Anjing();
        Kucing ku = new Kucing();
        System.out.print("Masukan banyak binatang : ");
        a = in.nextInt();
        String jenis[] = new String[a];
        String nama_an[] = new String[a];
        String nama_ku[] = new String[a];
        String ras[] = new String[a];
        int spesifik_an[] = new int[a];
        int spesifik_ku[] = new int[a];
        String data[] = new String[a];
        for (int i = 0; i < a; i++) {
            do {
                System.out.println("Binatang #" + (i + 1));
                System.out.println("1. Anjing");
                System.out.println("2. Kucing");
                System.out.print("Pilih jenis (pastikan pilihan anda ada. \njika tidak ada akan otomatis terulang) : ");
                b = in.nextInt();
            } while (b > 2 || b < 1);
            switch (b) {
                case 1:
                    jenis[i] = "Anjing";
                    an.Jenis = jenis[i];
                    System.out.print("Masukan nama anjing : ");
                    nama_an[i] = in.next();
                    System.out.print("Masukan ras anjing : ");
                    an.Ras = ras[i];
                    ras[i] = in.next();
                    System.out.print("Masukan kecepatan : ");
                    spesifik_an[i] = in.nextInt();
                    break;
                case 2:
                    jenis[i] = "Kucing";
                    bi.Jenis = jenis[i];
                    System.out.print("Masukan nama kucing : ");
                    nama_ku[i] = in.next();
                    System.out.print("Masukan ras kucing : ");
                    ras[i] = in.next();
                    System.out.print("Masukan berat : ");
                    spesifik_ku[i] = in.nextInt();
                    break;
            }
        }
        do {
            System.out.println("===== TUGAS PEMROGRAMAN =====");
            System.out.println("===== POLIMORFISME JAVA =====");
            System.out.println("1. Tampilkan semua nama binatang");
            System.out.println("2. Tampilkan semua DATA binatang");
            System.out.println("3. Tampilkan binatang terberat");
            System.out.println("4. Tampilkan binatang tercepat");
            System.out.println("5. Exit");
            System.out.print("Pilihan : ");
            x = in.nextInt();
            switch (x) {
                case 1:
                    for (int i = 0; i < a; i++) {
                        System.out.println("Binatang ke #" + (i + 1));
                        if (jenis[i] == "Anjing") {
                            bi.Nama = nama_an[i];
                            bi.Jenis = jenis[i];
                            bi.Cetak();
                        } else {
                            bi.Nama = nama_ku[i];
                            bi.Jenis = jenis[i];
                            bi.Cetak();
                        }
                    }
                    break;
                case 2:
                    for (int i = 0; i < a; i++) {
                        System.out.println("Binatang ke #" + (i + 1));
                        if (jenis[i] == "Anjing") {
                            bi = an;
                            bi.Nama = nama_an[i];
                            an.Ras = ras[i];
                            bi.Jenis = jenis[i];
                            an.setKecepatan(spesifik_an[i]);
                            bi.Cetak();
                        } else {
                            bi = ku;
                            bi.Nama = nama_ku[i];
                            ku.Ras = ras[i];
                            bi.Jenis = jenis[i];
                            ku.setBerat(spesifik_ku[i]);
                            bi.Cetak();
                        }
                    }
                    break;
                case 3:
                    int max_ku = 0;
                    String name_ku = null;
                        for (int i = 0; i < spesifik_ku.length; i++) {
                            if (spesifik_ku[i] > max_ku) {
                                max_ku = spesifik_ku[i];
                                name_ku = nama_ku[i];
                            }
                        }
                        if (name_ku == null){
                            System.out.println("Data tidak ada!!");
                        } else {
                        System.out.println("Binatang terberat adalah " + name_ku + " (" + max_ku + "kg)");
                        }
                    break;
                case 4:
                    int max_an = 0;
                    String name_an = null;
                        for (int i = 0; i < spesifik_an.length; i++) {
                            if (spesifik_an[i] > max_an) {
                                max_an = spesifik_an[i];
                                name_an = nama_an[i];
                            }
                        }
                        if (nama_an == null){
                            System.out.println("Data tidak ada!!");
                        } else {
                        System.out.println("Binatang tercepat adalah " + name_an + " (" + max_an + "mph)");
                        }
                    break;
                case 5 :
                    System.exit(0);
            }
        } while (0 == 0);
    }
}
