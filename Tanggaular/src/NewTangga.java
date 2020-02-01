
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JPanel;
import javax.swing.border.LineBorder;

public class NewTangga extends JFrame {

    JLabel txt1, txt3;
    JPanel pnl1;
    JTextField pnl2;
    JButton dice, gil1, gil2;

    int n;
    int turn = 1;
    int gilp1 = 0;
    int gilp2 = 0;
    int player1locx = 0;
    int player2locx = 0;
    int player1locy = 0;
    int player2locy = 0;

    NewTangga() {
        //windows
        this.setTitle("Ular tangga");
        this.setVisible(true);
        this.setSize(1000, 800);
        this.setDefaultCloseOperation(3);
        this.setLayout(null);

        //panel
        int nmr;
        String num = null;
        int x = 10;
        int y = 10;
        int j;
        int i;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                pnl1 = new JPanel();
                this.add(pnl1);
                pnl1.setBorder(new LineBorder(Color.BLACK, 1));
                pnl1.setVisible(true);
                pnl1.setOpaque(false);
                pnl1.setBounds(x + (j * 65), y + (i * 65), 65, 65);

                //nomor
                if (i == 0) {
                    nmr = j + 1;
                    num = Integer.toString(nmr);
                    txt1 = new JLabel(num);
                    pnl1.add(txt1);
                }
                if (i == 1) {
                    nmr = 20 - j;
                    num = Integer.toString(nmr);
                    txt1 = new JLabel(num);
                    pnl1.add(txt1);

                }
                if (i == 2) {
                    nmr = j + 21;
                    num = Integer.toString(nmr);
                    txt1 = new JLabel(num);
                    pnl1.add(txt1);

                }
                if (i == 3) {
                    nmr = 40 - j;
                    num = Integer.toString(nmr);
                    txt1 = new JLabel(num);
                    pnl1.add(txt1);

                }
                if (i == 4) {
                    nmr = j + 41;
                    num = Integer.toString(nmr);
                    txt1 = new JLabel(num);
                    pnl1.add(txt1);

                }
                if (i == 5) {
                    nmr = 60 - j;
                    num = Integer.toString(nmr);
                    txt1 = new JLabel(num);
                    pnl1.add(txt1);

                }
                if (i == 6) {
                    nmr = j + 61;
                    num = Integer.toString(nmr);
                    txt1 = new JLabel(num);
                    pnl1.add(txt1);

                }
                if (i == 7) {
                    nmr = 80 - j;
                    num = Integer.toString(nmr);
                    txt1 = new JLabel(num);
                    pnl1.add(txt1);

                }
                if (i == 8) {
                    nmr = j + 81;
                    num = Integer.toString(nmr);
                    txt1 = new JLabel(num);
                    pnl1.add(txt1);

                }
                if (i == 9) {
                    nmr = 100 - j;
                    num = Integer.toString(nmr);
                    txt1 = new JLabel(num);
                    pnl1.add(txt1);

                }
            }
        }

        //button
        dice = new JButton("Random");
        this.add(dice);
        dice.setVisible(true);
        dice.setBounds(750, 320, 100, 50);

        gil1 = new JButton("P1");
        this.add(gil1);
        gil1.setVisible(true);
        gil1.setBounds(750, 400, 50, 50);

        gil2 = new JButton("P2");
        this.add(gil2);
        gil2.setVisible(true); 
        gil2.setBounds(800, 400, 50, 50);

        //dadu
        pnl2 = new JTextField();
        this.add(pnl2);
        pnl2.setBorder(new LineBorder(Color.BLACK, 1));
        pnl2.setVisible(true);
        pnl2.setEditable(false);
        pnl2.setBounds(750, 215, 100, 100);

        //player1
        ImageIcon player1 = new ImageIcon("image/mata.png");
        JLabel p1 = new JLabel();
        p1.setIcon(player1);
        this.add(p1);
        p1.setVisible(true);
        p1.setBounds(10, 10, 32, 32);

        //player2
        ImageIcon player2 = new ImageIcon("image/rumah.png");
        JLabel p2 = new JLabel();
        p2.setIcon(player2);
        this.add(p2);
        p2.setVisible(true);
        p2.setBounds(10, 40, 32, 32);

        //col dadu
        pnl2 = new JTextField();
        this.add(pnl2);
        pnl2.setBorder(new LineBorder(Color.BLACK, 1));
        pnl2.getBorder();
        pnl2.setVisible(true);
        pnl2.setBounds(750, 215, 100, 100);

        pnl2.setText("Pilih turn");
        
        gil1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                pnl2.setText("P1 maju");
                gilp1 = 1;
                gilp2 = 2;
                gil1.setEnabled(false);
                gil2.setEnabled(false);
            }
        });

        gil2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                pnl2.setText("P2 maju");
                gilp1 = 2;
                gilp2 = 1;
                gil1.setEnabled(false);
                gil2.setEnabled(false);
            }
        });
        
        dice.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int cek1 = 0;
                int cek2 = 0;
                n = (int) (Math.random() * 6 + 1);
                String dadu;
                dadu = Integer.toString(n);
                pnl2.setText(dadu);
                if (turn == gilp1) {
                    player1locx = player1locx + n;
                    if (player1locx > 9 && player1locy == 9) {
                        int loc = player1locx % 9;
                        player1locx = 9 - loc;
                    } else if (player1locx > 9) {
                        player1locy += 1;
                        player1locx %= 9;
                        player1locx--;
                    }
                    if (player1locy % 2 == 1) {
                        cek1 = 9 - player1locx;
                    }
                    if (cek1 == 0 && player1locy == 9) {
                        p1.setLocation(10 + (65 * cek1), 40 + (65 * player1locy));
                        pnl2.setText("Mata Menang!");
                        turn = 0;
                    } else if (player1locy % 2 == 1) {
                        p1.setLocation(10 + (65 * cek1), 10 + (65 * player1locy));
                        turn = gilp2;
                    } else {
                        p1.setLocation(10 + (65 * player1locx), 10 + (65 * player1locy));
                        turn = gilp2;
                    }
                } else if (turn == gilp2) {
                    player2locx = player2locx + n;
                    if (player2locx > 9 && player2locy == 9) {
                        int loc = player2locx % 9;
                        player2locx = 9 - loc;
                    } else if (player2locx > 9) {
                        player2locy += 1;
                        player2locx %= 9;
                        player2locx--;
                    }
                    if (player2locy % 2 == 1) {
                        cek2 = 9 - player2locx;
                    }

                    if (cek2 == 0 && player2locy == 9) {
                        p2.setLocation(10 + (65 * cek2), 40 + (65 * player2locy));
                        pnl2.setText("Rumah Menang");
                        turn = 0;
                    } else if (player2locy % 2 == 1) {
                        p2.setLocation(10 + (65 * cek2), 40 + (65 * player2locy));
                        turn = gilp1;
                    } else {
                        p2.setLocation(10 + (65 * player2locx), 40 + (65 * player2locy));
                        turn = gilp1;
                    }

                } else {
                    pnl2.setText("SUDAH SELESAI");
                }

            }
        }
        );

    }

    public static void main(String[] args) {
        new NewTangga();
    }
}
