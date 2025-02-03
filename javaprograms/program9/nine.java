// Interface with the abstract method 'convert'
interface Compute {
    double convert(double value);
}

// Class to convert Gigabytes to Bytes
class GigaToBytes implements Compute {
    @Override
    public double convert(double gigaBytes) {
        return gigaBytes * 1024 * 1024 * 1024; // 1 GB = 1024^3 bytes
    }
}

// Class to convert Euros to Rupees
class EuroToRupees implements Compute {
    @Override
    public double convert(double euros) {
        return euros * 90; // Example conversion rate: 1 Euro = 90 Rupees
    }
}

public class nine {
    public static void main(String[] args) {
        // Create objects for both conversions
        Compute gigaToBytes = new GigaToBytes();
        Compute euroToRupees = new EuroToRupees();

        // Demonstrate the conversions
        System.out.println("5 Gigabytes = " + gigaToBytes.convert(5) + " Bytes");
        System.out.println("50 Euros = " + euroToRupees.convert(50) + " Rupees");
    }
}
