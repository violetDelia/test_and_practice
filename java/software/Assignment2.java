package software;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Assignment2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BubbleSort bubbleSort = new BubbleSort();
        for (int i = 0; i < 10; ++i) {
            bubbleSort.add(scanner.nextInt());
        }
        scanner.close();
        bubbleSort.sort();
        bubbleSort.out();
    }
}

class BubbleSort {
    private List<Integer> list = new ArrayList<>();

    public BubbleSort() {
    };

    void add(int n) {
        list.add(n);
    }

    void sort() {
        int size = list.size();
        boolean isSorted = false;
        while (size > 1 && isSorted == false) {
            isSorted = true;
            for (int i = 1; i < size; ++i) {
                int left = list.get(i - 1);
                int right = list.get(i);
                if (left > right) {
                    list.set(i, left);
                    list.set(i - 1, right);
                    isSorted = false;
                }
            }
            --size;
        }
    }

    void out() {
        for (int n : list) {
            System.out.print(n + " ");
        }
    }
}