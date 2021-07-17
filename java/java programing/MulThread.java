import java.text.SimpleDateFormat;
import java.util.Date;
import java.lang.Thread;

public class MulThread {
    public static void main(String[] args) {
        Couter c1 = new Couter(1);
        Thread t1 = new Thread(c1);
        Thread t2 = new Thread(c1);
        Thread t3 = new Thread(c1);
        Couter c2 = new Couter(2);
        Thread t4 = new Thread(c2);
        Thread t5 = new Thread(c2);
        Thread t6 = new Thread(c2);
        TimeDisplay timer = new TimeDisplay();
        Thread t7 = new Thread(timer);
        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
        t6.start();
        t7.start();
    }
}

class Couter implements Runnable {
    int id;

    Couter(int id) {
        this.id = id;
    }

    @Override
    public void run() {
        // TODO Auto-generated method stub
        int i = 0;
        while (i++ <= 10) {
            System.out.println("ID: " + id + " No. " + i);
            try {
                Thread.sleep(30);
            } catch (InterruptedException e) {
                // TODO: handle exception

            }
        }
    }

}

class TimeDisplay implements Runnable {
    @Override
    public void run() {
        int i = 0;
        // TODO Auto-generated method stub
        while (i++ <= 30) {
            new SimpleDateFormat().format(new Date());
        }
        try {
            Thread.sleep(40);
        } catch (InterruptedException e) {
            // TODO: handle exception
        }
    }
}