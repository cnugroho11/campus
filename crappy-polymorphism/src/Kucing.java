
public class Kucing extends Binatang {

    public String Ras;
    private int Berat;

    public void Cetak() {
        System.out.println("Jenis          : " +Jenis);
        System.out.println("Nama           : " +Nama);
        System.out.println("Ras kucing     : " +Ras);
        System.out.println("Berat kucing   : " +Berat);
    }

    public int getBerat() {
        return Berat;
    }

    public void setBerat(int Berat) {
        this.Berat = Berat;
    }

}
