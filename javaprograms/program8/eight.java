import java.util.Scanner;

public class eight {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            // Read two integers from the user
            System.out.print("Enter numerator (positive integer): ");
            int numerator = scanner.nextInt();

            // Check for negative input
            if (numerator < 0) throw new Exception("Negative number input.");

            System.out.print("Enter denominator (positive integer, non-zero): ");
            int denominator = scanner.nextInt();

            // Check for zero denominator
            if (denominator == 0) throw new ArithmeticException("Divide by zero exception.");

            // Perform division
            int result = numerator / denominator;
            System.out.println("Result: " + result);

        } catch (Exception e) {
            System.out.println(e.getMessage());
        } finally {
            scanner.close();
        }
    }
}
