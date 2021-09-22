package software;

import java.lang.Object;

public class Employee {
    private double basicSalary = 4000;
    private static int ID_base = 0;
    public int ID;
    public String name;
    public double salary;

    public Employee(int ID, String name) {
        this.ID = ID;
        this.name = name;
        this.salary = basicSalary;
    }

    public Employee(String name, double salary) {
        this.ID = ID_base++;
        this.name = name;
        this.salary = salary;
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

}

class SalesEmployee extends Employee {

    public double profit;

    public SalesEmployee(int ID, String name) {
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

}
