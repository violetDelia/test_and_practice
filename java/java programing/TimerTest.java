import java.util.Timer;
import java.util.TimerTask;
import java.util.*;
public class TimerTest{
    public static void main(String[] args) {
        Timer timer = new Timer("display");
        TimerTask task = new TimerTestTask();
        timer.schedule(task, 1000,1000);
    }
}
class TimerTestTask extends TimerTask{
    int n = 0;
    @Override
    public void run() {
        ++n;
        System.out.println(new Date());
        System.out.println("---"+n);
    }
}