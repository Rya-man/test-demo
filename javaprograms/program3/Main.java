import java.util.ArrayList;
import java.util.Scanner;


class ComplexNumber {
   private int real;
   private int imaginary;


   public ComplexNumber() {
       real = 0;
       imaginary = 0;
   }


   public ComplexNumber(int real, int imaginary) {
       this.real = real;
       this.imaginary = imaginary;
   }


   public ComplexNumber sum(ComplexNumber other) {
       return new ComplexNumber(this.real + other.real, this.imaginary + other.imaginary);
   }


   public ComplexNumber diff(ComplexNumber other) {
       return new ComplexNumber(this.real - other.real, this.imaginary - other.imaginary);
   }


   public boolean compare(ComplexNumber other) {
       return this.real == other.real && this.imaginary == other.imaginary;
   }


   public void display() {
       System.out.println(real + " + " + imaginary + "i");
   }


   public void incrementReal(int a)
   {
       real += a;
   }


   public void decrementReal(int a)
   {
       real -= a;
   }
   public void incrementImaginary(int a)
   {
       imaginary += a;
   }


   public void decrementImaginary(int a)
   {
       imaginary -= a;
   }
}


public class Main{
   public static void main(String[] args) {
       Scanner scanner = new Scanner(System.in);
       System.out.println("Enter the number of complex numbers to operate on:");
       int n = scanner.nextInt();
       ArrayList<ComplexNumber> nums = new ArrayList<>();


       for (int i = 0; i < n; i++) {
           System.out.println("Enter real and imaginary parts for complex number " + (i + 1) + ":");
           int real = scanner.nextInt();
           int imaginary = scanner.nextInt();
           nums.add(new ComplexNumber(real, imaginary));
       }


       while (true) {
           System.out.println("\n\nEnter operation and indices to perform operation on:");
           System.out.println("1. Addition");
           System.out.println("2. Subtraction");
           System.out.println("3. Comparison");
           System.out.println("4. IncrementReal");
           System.out.println("5. IncrementImaginary");
           System.out.println("6. DecrementReal");
           System.out.println("7. DecrementImaginary");
           System.out.println("For 4 to 7 the second input will be the offset with which increment or decrement is done");
           System.out.println("Any other number to break.");
          
           int operation = scanner.nextInt();
           if (operation < 1 || operation > 3) {
               break;
           }
          
           System.out.println("Enter the indices of the complex numbers:");
           int i1 = scanner.nextInt();
           int i2 = scanner.nextInt();


           // Validate indices
           if (i1 < 0 || i1 >= nums.size() || i2 < 0 || i2 >= nums.size()) {
               System.out.println("Invalid indices. Please try again.");
               continue;
           }


           switch (operation) {
               case 1:
                   ComplexNumber sumResult = nums.get(i1).sum(nums.get(i2));
                   System.out.print("\nSum: ");
                   sumResult.display();
                   break;
               case 2:
                   ComplexNumber diffResult = nums.get(i1).diff(nums.get(i2));
                   System.out.print("\nDifference: ");
                   diffResult.display();
                   break;
               case 3:
                   boolean comparisonResult = nums.get(i1).compare(nums.get(i2));
                   System.out.println("\nAre equal? " + comparisonResult);
                   break;
               case 4:
                   nums.get(i1).incrementReal(i2);
               case 5:
                   nums.get(i1).incrementImaginary(i2);
               case 6:
                   nums.get(i1).decrementReal(i2);
               case 7:
                   nums.get(i1).decrementImaginary(i2);
           }
       }


       scanner.close();
   }
}

