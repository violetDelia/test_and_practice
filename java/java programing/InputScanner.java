import java.util.Scanner;
public class InputScanner {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("����һ����\n");
        int a = input.nextInt();
        System.out.printf("%d��ƽ����%d\n",a,a*a);
        System.out.print("����һ��С��\n");
        double b = input.nextDouble();
        System.out.printf("%f��ƽ����%f\n",b,b*b);
        System.out.print("����һ������\n");
        String c = input.next();
        System.out.printf("%s\n",c);
        input.close();
    }

}
