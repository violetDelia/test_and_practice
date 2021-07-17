package test;

public class test {
    public static void main(String[] args) { 
       System.out.println(test.getVal(154)); 
    }

    public static long getVal(long x) {
        long n = x - 1;
        System.out.println(Long.toBinaryString(n));
        System.out.println(Long.toBinaryString(n>>1));
        System.out.println("\n");
        n |= n >>> 1;
        System.out.println(Long.toBinaryString(n));
        System.out.println(Long.toBinaryString(n>>2));
        System.out.println("\n");
        n |= n >>> 2;
        System.out.println(Long.toBinaryString(n));
        System.out.println(Long.toBinaryString(n>>4));
        System.out.println("\n");
        n |= n >>> 4;
        System.out.println(Long.toBinaryString(n));
        System.out.println(Long.toBinaryString(n>>8));
        System.out.println("\n");
        n |= n >>> 8;
        System.out.println(Long.toBinaryString(n));
        System.out.println(Long.toBinaryString(n>>16));
        System.out.println("\n");
        n |= n >>> 16;
        System.out.println(Long.toBinaryString(n));
        System.out.println("\n");
        System.out.println(n<0);
        return n < 0 ? 1 : n + 1;
    }
}
