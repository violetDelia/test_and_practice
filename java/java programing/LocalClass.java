public class LocalClass {
    public static void main(String[] args) {
        Outer2 a = new Outer2();
        System.out.println(a.toString());
        System.out.println("\n");
        System.out.println(a.makeTheLocal(3));
    }

}
class Outer2 {
    private int test1 = 5;
    public String toString(){
        return "123";
    }
    public Object makeTheLocal(int LocalVar) {
        final int test2 = 99;
        class Local {
            public String toString123(){
                return this.toString()+"make";
            }
            public String toString() {
                String a = "InnerSize: " + test1 + "   localVar: " + LocalVar + "   test2: " + test2;
                return a;
            }
        }
        Local b = new Local();
        System.out.println(b.toString123());
        return b;
    }
    
}
