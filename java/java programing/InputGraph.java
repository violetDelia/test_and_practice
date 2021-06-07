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
    JButton btn = new JButton("求平方");
    JLabel out = new JLabel("用于显示结果的标签");

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
            out.setText(d + "的平方是：" + sq);
        });
        setSize(400, 100);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setVisible(true);
    }

    /*
     * class BtnActionAdapter implements ActionListener { public void
     * actionPerformed(ActionEvent e) { String s = in.getText(); double d =
     * Double.parseDouble(s); double sq = d * d; out.setText(d + "的平方是：" + sq); } }
     */
}