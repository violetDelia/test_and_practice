package software;

public class test3 {
    public static void main(String[] args) {
        // 常量池

        String a = "abc";
        String b = "abc";
        String c = new String("abc");
        String d = new String("abc");
        System.out.println(a == b);
        System.out.println(c == d);
        Integer e = 200;
        Integer f = 200;

        System.out.println(e.intValue() == f.intValue());
        System.out.println(e.equals(f));
        System.out.println(e == f);
        //
    }
}
