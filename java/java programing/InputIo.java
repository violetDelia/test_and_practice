
public class InputIo {
    public static void main(String[] args) {
        char c = ' ';
        System.out.print("input a char : ");
        try {
            c = (char)System.in.read();
        } catch (Exception e) {
            System.out.println("you have entered: " + c);
        }
        System.out.println(c);
    }
}
