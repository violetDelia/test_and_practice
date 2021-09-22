package software;

public class TaxCalculateTest {
    public static void main(String[] args) {
        Calculate test = null;
        test = new USCalculate();
        test.CalculateTax(0);
        test = new MexicoCalculate();
        test.CalculateTax(0);
        test = new CanadaCalculate();
        test.CalculateTax(0);
    }
}

interface Calculate {
    public double CalculateTax(double amount);
}

class USCalculate implements Calculate {

    @Override
    public double CalculateTax(double amount) {
        System.out.println("USCalculateTax called");
        return 0;
    }

}

class MexicoCalculate implements Calculate {

    @Override
    public double CalculateTax(double amount) {
        System.out.println("MexicoCalculateTax called");
        return 0;
    }

}

class CanadaCalculate implements Calculate {

    @Override
    public double CalculateTax(double amount) {
        System.out.println("CanadaCalculateTax called");
        return 0;
    }

}
