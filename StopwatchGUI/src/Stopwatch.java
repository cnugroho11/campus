
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import static java.lang.Thread.sleep;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFileChooser;

/**
 *
 * @author cnjes
 */
public class Stopwatch extends javax.swing.JFrame {

    /**
     * Creates new form Stopwatch
     */
    public Stopwatch() {
        initComponents();
        pause.setEnabled(false);
        reset.setEnabled(false);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        h = new javax.swing.JLabel();
        m = new javax.swing.JLabel();
        s = new javax.swing.JLabel();
        ms = new javax.swing.JLabel();
        start = new javax.swing.JButton();
        reset = new javax.swing.JButton();
        save = new javax.swing.JButton();
        pause = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        h.setFont(new java.awt.Font("Tahoma", 0, 36)); // NOI18N
        h.setText("00:");

        m.setFont(new java.awt.Font("Tahoma", 0, 36)); // NOI18N
        m.setText("00:");

        s.setFont(new java.awt.Font("Tahoma", 0, 36)); // NOI18N
        s.setText("00:");

        ms.setFont(new java.awt.Font("Tahoma", 0, 24)); // NOI18N
        ms.setText("00");

        start.setText("Start");
        start.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                startActionPerformed(evt);
            }
        });

        reset.setText("Reset");
        reset.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                resetActionPerformed(evt);
            }
        });

        save.setText("Save ");
        save.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                saveActionPerformed(evt);
            }
        });

        pause.setText("Pause");
        pause.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                pauseActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(start, javax.swing.GroupLayout.PREFERRED_SIZE, 67, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(pause, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(reset))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(h)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(m)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(s)
                        .addGap(22, 22, 22)
                        .addComponent(ms)))
                .addGap(18, 18, 18)
                .addComponent(save, javax.swing.GroupLayout.DEFAULT_SIZE, 90, Short.MAX_VALUE)
                .addGap(18, 18, 18))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(h, javax.swing.GroupLayout.PREFERRED_SIZE, 52, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(s, javax.swing.GroupLayout.PREFERRED_SIZE, 52, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(ms, javax.swing.GroupLayout.PREFERRED_SIZE, 52, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(m, javax.swing.GroupLayout.PREFERRED_SIZE, 52, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(start)
                            .addComponent(reset)
                            .addComponent(pause)))
                    .addComponent(save, javax.swing.GroupLayout.PREFERRED_SIZE, 85, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(21, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    int msecond = 0;
    int second = 0;
    int minute = 0;
    int hour = 0;
    boolean st = false;
    Thread cek;

    private void startActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_startActionPerformed

        st = true;
        cek = new Thread() {
            public void run() {

                for (int i = 1; i > 0; i++) {
                    if (st == true) {
                        try {
                            sleep(1);
                            msecond++;
                            if (msecond == 99) {
                                msecond = 0;
                                second++;
                            }
                            if (second == 60) {
                                msecond = 0;
                                second = 0;
                                minute++;
                            }
                            if (minute == 60) {
                                msecond = 0;
                                second = 0;
                                minute = 0;
                                hour++;
                            }
                            if (second <= 9 && minute <= 9) {
                                ms.setText("" + msecond);
                                s.setText(":" + 0 + second);
                                m.setText(":" + 0 + minute);
                                h.setText("" + 0 + hour);
                            } else if (second >= 9 && minute <= 9) {
                                ms.setText("" + msecond);
                                s.setText(":" + second);
                                m.setText(":" + 0 + minute);
                                h.setText("" + 0 + hour);
                            } else if (minute >= 9 && second <= 9) {
                                ms.setText("" + msecond);
                                s.setText(":" + 0 + second);
                                m.setText(":" + minute);
                                h.setText("" + 0 + hour);
                            } else if (minute >= 9 && second >= 9) {
                                ms.setText("" + msecond);
                                s.setText(":" + second);
                                m.setText(":" + minute);
                                h.setText("" + 0 + hour);
                            }

                        } catch (Exception e) {

                        }
                    }
                }
            }
        };

        cek.start();
        start.setEnabled(false);
        pause.setEnabled(true);
        reset.setEnabled(true);
    }//GEN-LAST:event_startActionPerformed

    private void resetActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_resetActionPerformed
        st = false;
        cek.stop();

        msecond = 0;
        second = 0;
        minute = 0;
        hour = 0;

        ms.setText("00");
        s.setText("00:");
        m.setText("00:");
        h.setText("00:");

        start.setEnabled(true);
        pause.setEnabled(false);
    }//GEN-LAST:event_resetActionPerformed

    private void pauseActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_pauseActionPerformed
        st = false;
        cek.stop();
        start.setEnabled(true);
        pause.setEnabled(false);
    }//GEN-LAST:event_pauseActionPerformed

    private void saveActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_saveActionPerformed
        String ss = hour + ":" + minute + ":" + second + ":" + msecond;

        JFileChooser sv = new JFileChooser();
        sv.setSelectedFile(new File("WaktuSimpan.txt"));
        sv.showSaveDialog(this);

        File f = sv.getSelectedFile();

        try {
            FileWriter fw = new FileWriter(f);
            fw.write(ss);
            fw.close();

        } catch (IOException ex) {
            Logger.getLogger(Stopwatch.class.getName()).log(Level.SEVERE, null, ex);
        }

    }//GEN-LAST:event_saveActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Stopwatch.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Stopwatch.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Stopwatch.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Stopwatch.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Stopwatch().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel h;
    private javax.swing.JLabel m;
    private javax.swing.JLabel ms;
    private javax.swing.JButton pause;
    private javax.swing.JButton reset;
    private javax.swing.JLabel s;
    private javax.swing.JButton save;
    private javax.swing.JButton start;
    // End of variables declaration//GEN-END:variables
}