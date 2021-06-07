import java.io.BufferedReader;

import java.io.InputStreamReader;

public class InputBufferreader {
    public static void main(String[] args) {
        String s = " ";
        int n = 0;
        double c = 0;
        System.out.print("输入一行：");
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            s = in.readLine();
        } catch (Exception e) {
        }
        System.out.print(s + "\n");
        System.out.print("输入一个数：");
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            s = in.readLine();
            n = Integer.parseInt(s);
            c = Double.parseDouble(s);
        } catch (Exception e) {
        }
        System.out.print(s + "\n");
        System.out.println(n + "\n");
        System.out.println(c);
    }
}
