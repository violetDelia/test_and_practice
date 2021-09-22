package software;

import java.lang.System;

public class test2 {
    public static void main(String[] args) {
        final long A = 24 * 60 * 60 * 1000 * 1000;// int溢出(默认int类型)
        final long B = 24 * 60 * 60 * 1000;
        System.out.println(A / B);
    }
}
