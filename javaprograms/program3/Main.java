class ComplexNumber {
    private double real;
    private double imaginary;

    public ComplexNumber(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    public double getReal() {
        return real;
    }

    public double getImaginary() {
        return imaginary;
    }

    public void setReal(double real) {
        this.real = real;
    }

    public void setImaginary(double imaginary) {
        this.imaginary = imaginary;
    }

    public ComplexNumber add(ComplexNumber other) {
        double realSum = this.real + other.getReal();
        double imaginarySum = this.imaginary + other.getImaginary();
        return new ComplexNumber(realSum, imaginarySum);
    }

    public ComplexNumber subtract(ComplexNumber other) {
        double realDiff = this.real - other.getReal();
        double imaginaryDiff = this.imaginary - other.getImaginary();
        return new ComplexNumber(realDiff, imaginaryDiff);
    }

    public boolean equals(ComplexNumber other) {
        return this.real == other.getReal() && this.imaginary == other.getImaginary();
    }

    public void display() {
        System.out.println(real + " + " + imaginary + "i");
    }
}

public class Main {
    public static void main(String[] args) {
        ComplexNumber c1 = new ComplexNumber(4, 5);
        ComplexNumber c2 = new ComplexNumber(1, 2);

        System.out.print("Complex Number 1: ");
        c1.display();
        System.out.print("Complex Number 2: ");
        c2.display();

        ComplexNumber sum = c1.add(c2);
        System.out.print("Addition result: ");
        sum.display();

        ComplexNumber difference = c1.subtract(c2);
        System.out.print("Subtraction result: ");
        difference.display();

        if (c1.equals(c2)) {
            System.out.println("The complex numbers are equal.");
        } else {
            System.out.println("The complex numbers are not equal.");
        }
    }
}
