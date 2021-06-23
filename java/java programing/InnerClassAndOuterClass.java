
public class InnerClassAndOuterClass {
    public static void main(String[] args) {
        A.B a_b = new A().new B();
        A a = new A();
        A.B ab = a.new B();
        Outer.Inter oi = new Outer.Inter();
        a_b.value = 5;
        ab.value = 5;
        a.value = 5;
        oi.value = 4;
    }
}

class A {
    int value = 1;

    class B {
        int value = 2;
    }
}

class Outer {

    static class Inter {
        int value = 4;
    }
}
