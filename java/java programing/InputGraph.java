import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.*;
import javax.swing.*;

public class InputGraph {
    public static void main(String[] args) {
        new Appframe();
    }
}

class Appframe extends JFrame {
    JTextField in = new JTextField(10);
    JButton btn = new JButton("��ƽ��");
    JLabel out = new JLabel("������ʾ����ı�ǩ");

    public Appframe() {
        setLayout(new FlowLayout());
        getContentPane().add(in);
        getContentPane().add(btn);
        getContentPane().add(out);
        // btn.addActionListener(new BtnActionAdapter());
        btn.addActionListener(e -> {
            String s = in.getText();
            double d = Double.parseDouble(s);
            double sq = d * d;
            out.setText(d + "��ƽ���ǣ�" + sq);
        });
        setSize(400, 100);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setVisible(true);
    }

    /*
     * class BtnActionAdapter implements ActionListener { public void
     * actionPerformed(ActionEvent e) { String s = in.getText(); double d =
     * Double.parseDouble(s); double sq = d * d; out.setText(d + "��ƽ���ǣ�" + sq); } }
     */
}