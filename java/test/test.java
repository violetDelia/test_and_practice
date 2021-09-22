package test;

import java.util.HashMap;
import java.util.Map;

public class test {
    public static void main(String[] args) {
        Map<String, String> a = new HashMap<String, String>();
        for (int i = 0; i < 10; ++i) {
            a.put(Integer.toString(i), Integer.toString(i * 100));
        }
        for (int i = 0; i < 10; ++i) {
            System.out.println(a.get(Integer.toString(i)));
        }
    }

}
