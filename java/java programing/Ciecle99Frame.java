import javax.swing.*;
import java.awt.*;

public class Ciecle99Frame extends JFrame {
    public static void main(String[] args) {
        JFrame frame = new Ciecle99Frame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 800);
        frame.setVisible(true);
    }

    public Color getRandomColor(){
        return new Color((int)(Math.random()*255),
        (int)(Math.random()*255),(int)(Math.random()*255));
    }
    
    public void paint(Graphics g) {
        g.drawString("circle 99", 20, 20);

        int x0 = getSize().width / 2;
        int y0 = getSize().height / 2;
        for (int r = 0; r < getSize().height / 2 - 30; r += 10) {
            g.setColor(getRandomColor());
            g.drawOval(x0 - r, y0 - r, r * 2, r * 2);
        }
    }
}
