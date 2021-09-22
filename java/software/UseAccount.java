package software;

import java.util.InputMismatchException;
import java.util.Scanner;

public class UseAccount {
    public static void main(String[] args) {
        System.out.println("UseAccount");
        System.out.println("Please set the account want to operate.");
        BankAccount bankAccount;
        while (true) {
            try {
                System.out.println("Input the deposit and rate.");
                Scanner input = new Scanner(System.in);
                double deposit = 0;
                double rate = 0;
                if (input.hasNext()) {
                    deposit = input.nextDouble();
                }
                if (input.hasNext()) {
                    rate = input.nextDouble();
                }
                bankAccount = new BankAccount(deposit, rate);
                input.close();
                break;
            } catch (InputMismatchException e) {
                System.out.println("Input is not the number,please try again!");
            }
        }
        System.out.println(bankAccount.balanceInquiry());
        bankAccount.deposit(100);
        System.out.println(bankAccount.deposit);
        bankAccount.withdrawal(50);
        System.out.println(bankAccount.deposit);
        bankAccount.setInterestRate(5);
        System.out.println(bankAccount.interestRateInquiry());
    }
}

class BankAccount {

    protected double deposit;
    protected double interestRate;

    public BankAccount() {
        this.deposit = 0;
        this.interestRate = 0;
    }

    public BankAccount(double deposit, double interestRate) {
        if (deposit < 0) {
            System.out.println("The account deposit is 0");
            this.deposit = 0;
        } else {
            this.deposit = deposit;
        }
        this.interestRate = interestRate;
    };

    public double getDeposit() {
        return this.deposit;
    }

    public void setDeposit(double deposit) {
        this.deposit = deposit;
    }

    public double getInterestRate() {
        return this.interestRate;
    }

    /**
     * set the interest rate
     * 
     * @param interestRate the rate
     */
    public void setInterestRate(double interestRate) {
        this.interestRate = interestRate;
    }

    /**
     * Get the balance of this account
     * 
     * @return deposit of this account
     */
    public double balanceInquiry() {
        return getDeposit();
    }

    /**
     * Save the money in this account
     * 
     * @param money the money will save
     */
    public void deposit(double money) {
        setDeposit(getDeposit() + money);
    }

    /**
     * Withdrawal the money from this account
     * 
     * @param money the money will withdrawal
     */
    public void withdrawal(double money) {
        if (money > this.deposit) {
            System.out.println("insufficient fund");
        } else {
            setDeposit(getDeposit() - money);
        }
    }

    /**
     * Get the interest rate of the account
     * 
     * @return the interest rate
     */
    public double interestRateInquiry() {
        return getInterestRate();
    }

}