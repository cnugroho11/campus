
public class Anjing extends Binatang {

    private int Kecepatan;
    public String Ras;

    public void Cetak() {
        System.out.println("Jenis            : " +Jenis);
        System.out.println("Nama             : " +Nama);
        System.out.println("Ras anjing       : " +Ras);
        System.out.println("Kecepatan anjing : " +Kecepatan);
    }

    public int getKecepatan() {
        return Kecepatan;
    }

    public void setKecepatan(int Kecepatan) {
        this.Kecepatan = Kecepatan;
    }

}
