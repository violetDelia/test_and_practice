package software;

import java.lang.Object;

public abstract class EmployeePlus {

    public static void main(String[] args) {
        EmployeePlus.test();
    }

    private double basicSalary = 4000;

    public int ID;
    public String name;
    public double salary;

    public EmployeePlus(int ID, String name) {
        this.ID = ID;
        this.name = name;
        this.salary = basicSalary;
    }

    public int getID() {
        return this.ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getSalary() {
        return this.salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    @Override
    public boolean equals(Object o) {
        if (o == this)
            return true;
        if (!(o instanceof Employee)) {
            return false;
        }
        Employee employee = (Employee) o;
        return ID == employee.ID && name.equals(employee.getName()) && salary == employee.salary;
    }

    @Override
    public String toString() {
        return " ID='" + getID() + "'" + ", name='" + getName() + "'" + ", salary='" + getSalary() + "'";
    }

    public int compareTo(Object o) {
        return this.equals(o) == true ? 1 : 0;
    }

    abstract public double getMonthlyPay();

    /**
     * test SalesEmployeePlus and Manager
     */
    static public void test() {
        SalesEmployeePlus salesEmployee = new SalesEmployeePlus(001, "testSalesEmployee");
        System.out.println(salesEmployee.toString());
        salesEmployee.setProfit(500);
        System.out.println("SalesEmployee Pay: " + salesEmployee.getMonthlyPay());
        Manager manager = new Manager(002, "testManager");
        manager.setBonus(500);
        System.out.println(manager.toString());
        System.out.println("Manager Pay: " + manager.getMonthlyPay());
        System.out.println(manager.compareTo(manager));
        System.out.println(salesEmployee.compareTo(salesEmployee));
        System.out.println(manager.compareTo(salesEmployee));
        System.out.println(salesEmployee.compareTo(manager));
        System.out.println(salesEmployee.compareTo(new SalesEmployee(001, "testSalesEmployee")));
    }

}

class SalesEmployeePlus extends EmployeePlus {

    public double profit;

    public SalesEmployeePlus(int ID, String name) {
        super(ID, name);
    }

    public double getProfit() {
        return this.profit;
    }

    public void setProfit(double profit) {
        this.profit = profit;
    }

    @Override
    public String toString() {
        return super.toString() + " profit='" + getProfit() + "'";
    }

    @Override
    public double getMonthlyPay() {

        return getProfit() * 0.2 + getSalary();
    }

}

class Manager extends EmployeePlus {

    public double bonus = 0;

    public Manager(int ID, String name) {
        super(ID, name);

    }

    public double getBonus() {
        return this.bonus;
    }

    public void setBonus(double bonus) {
        this.bonus = bonus;
    }

    @Override
    public String toString() {
        return super.toString() + " bonus='" + getBonus() + "'";
    }

    @Override
    public double getMonthlyPay() {
        return getSalary() + getBonus();
    }

}