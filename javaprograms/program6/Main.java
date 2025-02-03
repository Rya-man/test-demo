import java.util.Scanner;

abstract class Bank {

    String name;
    int accno;
    float bal;
    public Bank(String n,int a,float b){
        name = n;
        accno = a;
        bal = b;
    }
    public Bank readBank(Scanner s)
    {
        System.out.println("Enter name accno and bal");
        name = s.nextLine();
        accno = s.nextInt();s.nextLine();
        bal = s.nextFloat();s.nextLine();
    }
    void displayDetails() {
        System.out.println("Customer Name: " + name);
        System.out.println("Account Number: " + accno);
        System.out.println("Balance: " + bal);
    }
    abstract float roi();
}
class banka extends Bank{
    banka(String a,int b,float c)
    {
        super(a, b, c);
    }
    float roi(){
        return 4*bal;
    }
}
class bankb extends Bank{
    bankb(String a,int b,float c)
    {
        super(a, b, c);
    }
    float roi(){
        return 14*bal;
    }
}class bankc extends Bank{
    bankc(String a,int b,float c)
    {
        super(a, b, c);
    }
    float roi(){
        return 3*bal;
    }
}