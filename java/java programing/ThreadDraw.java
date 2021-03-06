import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class ThreadDraw extends JFrame {
    public static void main(String[] args) {
        ThreadDraw f = new ThreadDraw();
        f.init();
    }

    MovingShape[] shapes;

    public void init() {
        setLayout(null);
        setSize(426, 426);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);

        shapes = new MovingShape[10];
        for (int i = 0; i < shapes.length; ++i) {
            shapes[i] = new MovingShape(this);
            shapes[i].start();
        }
    }
}

class MovingShape extends Thread {
    private int size = 100;
    private int speed = 10;
    private Color color;
    private int type;
    private int x, y, w, h, dx, dy;
    protected java.awt.Component app;
    public boolean stopped;

    MovingShape(JFrame app) {
        this.app = app;
        x = (int) (Math.random() * app.getSize().width);
        y = (int) (Math.random() * app.getSize().height);
        w = (int) (Math.random() * size);
        h = (int) (Math.random() * size);
        dx = (int) (Math.random() * speed);
        dy = (int) (Math.random() * speed);
        color = new Color((int) (Math.random() * 128 + 128), (int) (Math.random() * 128 + 128),
                (int) (Math.random() * 128 + 128));
        type = (int) (Math.random() * 2);
    }

    @Override
    public void run() {
        
        super.run();
       
        while (true) {
            if (stopped)
                break;
            SwingUtilities.invokeLater(() -> {
                draw();
            });
            try {
                Thread.sleep(130);
            } catch (InterruptedException e) {
            
            }
        }
    }

    int S = 10;

    void draw() {
        x += dx;
        y += dy;
        if (x < 0 || x + w > app.getSize().width)
            dx = -dx;
        if (y < 0 || y + h > app.getSize().height)
            dy = -dy;
        Graphics g = app.getGraphics();
        switch (type) {
            case 0:
                g.setColor(color);
                g.fillRect(x, y, w, h);
                g.setColor(Color.black);
                g.drawRect(x, y, w, h);
                break;
            case 1:
                g.setColor(color);
                g.fillOval(x, y, w, h);
                 g.setColor(Color.black);
                g.drawOval(x, y, w, h);
                break;
        }
    }
}