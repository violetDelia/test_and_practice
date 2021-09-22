package software;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

public class Assignment1 {
    public static void main(String[] args) {
        System.out.println("输入一个非负数: ");
        long n = -1;
        reInput: while (n < 0) {
            try {
                Scanner scanner = new Scanner(System.in);
                n = scanner.nextLong();
                if (n < 0) {
                    System.out.println("负数，请重新输入");
                    continue reInput;
                }
                scanner.close();
            } catch (InputMismatchException e) {
                System.out.println("不是数字，请重新输入");
                continue reInput;
            } catch (Exception e) {
                System.out.println("未知错误");
                continue reInput;
            }
        }
        Fibonacci fibonacci = new Fibonacci(n);
        fibonacci.init();
        fibonacci.out();
    }

}

class Fibonacci {
    private long size;
    private List<Long> list;

    public Fibonacci(Long n) {
        this.size = n;
        list = new ArrayList<>();

    }

    void init() {
        if (this.size >= 1) {
            list.add((long) 1);
        }
        if (this.size >= 2) {
            list.add((long) 1);
        }
        for (int i = 1; i < size - 1; ++i) {
            list.add(list.get(i) + list.get(i - 1));
        }
    }

    void out() {
        int count = 0;
        for (long n : list) {
            System.out.print(n + " ");
            count++;
            if (count % 10 == 0) {
                System.out.print("\n");
            }
        }
    }
}
