import java.util.Scanner;
public class InputScanner {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("输入一个数\n");
        int a = input.nextInt();
        System.out.printf("%d的平方是%d\n",a,a*a);
        System.out.print("输入一个小数\n");
        double b = input.nextDouble();
        System.out.printf("%f的平方是%f\n",b,b*b);
        System.out.print("输入一个单词\n");
        String c = input.next();
        System.out.printf("%s\n",c);
        input.close();
    }

}
