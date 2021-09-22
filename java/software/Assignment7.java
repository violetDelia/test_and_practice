package software;

import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Scanner;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class Assignment7 {
    public static void main(String[] args) {
        Assignment7 assignment7 = new Assignment7();
        HashMap<String, Employee> hashMap = new HashMap<>();
        System.out.println("input five employee info:");
        Scanner input = new Scanner(System.in);
        in: while (hashMap.size() < 5) {
            try {
                assignment7.getAndPut(hashMap, input);
            } catch (InputDoubleException e) {
                System.out.println(e.toString());
                System.out.println("try again");
                continue in;
            } catch (InputMismatchException e) {
                System.out.println(e.toString());
                System.out.println("try again");
                continue in;
            } catch (Exception e) {
                System.out.println(e.toString());
                System.out.println("try again");
                continue in;
            }
        }
        String filePath = "C:\\Users\\17335\\Desktop\\EmployeeInfo.txt";
        input.close();
        File file = new File(filePath);
        try {
            if (!file.exists()) {
                file.createNewFile();
            }
            FileOutputStream output = new FileOutputStream(file, true);
            byte[] b = (hashMap.toString() + "\n").getBytes();
            output.write(b);
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println(hashMap.values());
    }

    void getAndPut(HashMap<String, Employee> map, Scanner input) {
        try {
            System.out.println("input name");
            String name = input.next();
            System.out.println("input salary");
            String salary = input.next();
            try {
                map.put(name, new Employee(name, Double.parseDouble(salary)));
            } catch (NumberFormatException e) {
                throw new InputDoubleException();
            }
        } catch (Exception e) {
            throw e;
        }
    }

}

class InputDoubleException extends NumberFormatException {
    public InputDoubleException() {
        super("InputDoubleException");
    }
}