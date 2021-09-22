package software;

import java.util.Scanner;

public class Assignment6 {
    public static void main(String[] args) {
        System.out.println("start test");
        try {
            Scanner input = new Scanner(System.in);
            ExceptionTest exceptionTest = new ExceptionTest(input.nextInt(), input.nextInt());
            input.close();
            exceptionTest.doTest();
        } catch (OverFlowException e) {
            System.out.println(e.toString());
        } catch (UnderFlowException e) {
            System.out.println(e.toString());
        } catch (Exception e) {
            System.out.println("unknown exception");
        }
    }
}

class OverFlowException extends RuntimeException {

    public OverFlowException(Long value) {
        super("Value is Under Err: " + value);
    }
}

class UnderFlowException extends RuntimeException {

    public UnderFlowException(Long value) {
        super("Value is Over Err: " + value);
    }

}

class ExceptionTest {
    protected int intMath1;
    protected int intMath2;

    public ExceptionTest(int intMath1, int intMath2) {
        this.intMath1 = intMath1;
        this.intMath2 = intMath2;
    }

    void doTest() throws UnderFlowException, OverFlowException {
        Long value = (long) intMath1 - (long) intMath2;
        if (value <= 0) {
            throw new UnderFlowException(value);
        }
        if (value >= 1000) {
            throw new OverFlowException(value);
        }
        System.out.println("no exception");
    }
}