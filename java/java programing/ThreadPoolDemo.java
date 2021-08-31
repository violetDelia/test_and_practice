import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ThreadPoolDemo {
    public static void main(String[] args) {
        ExecutorService pool = Executors.newCachedThreadPool();
        MyTask t1 = new MyTask(5);
        MyTask t2 = new MyTask(10);
        MyTask t3 = new MyTask(15);
        pool.execute(t1);
        pool.execute(t2);
        pool.execute(t3);
        pool.shutdown();
    }
}

class MyTask implements Runnable {
    int n = 10;

    public MyTask(int n) {
        this.n = n;
    }

    @Override
    public void run() {
        for (int i = 0; i < n; i++)
            System.out.println(i);
    }
}