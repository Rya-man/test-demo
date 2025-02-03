import java.util.*;
public class Main {

public static void roots(Scanner s)
{
    System.out.println("ENter the a b c values");
    float a = s.nextFloat();
    float b = s.nextFloat();
    float c = s.nextFloat();s.nextLine();
    float res = b*b -4*a*c;
    if(res==0)
    System.out.println("Real and equal");
    if(res<0)
    System.out.println("Imaginary");
    if(res>0)
    System.out.println("Real and Unequal");




}
static void prod(Scanner s)
{
    int []arr = {1,2,3,4};
    int []arr2 = {1,2,3,4};
    int []arr3 = new int[4];
    for(int i =0;i<4;++i)
    {
        arr3[i] = arr[i]*arr2[i];
        System.out.print(arr3[i]+ " ");
    }

}
static void sort(Scanner s)
{
    int n = s.nextInt();
    s.nextLine();
    int []arr = new int[n];
    for(int i =0;i<n;++i)
    {
        arr[i] = s.nextInt();
    }
    s.nextLine();
    for(int i =0;i<n;++i)
    {
        for(int j =1;j<n-i;++j)
        {
            if(arr[j-1]>arr[j])
            {
                int x = arr[j];
                arr[j] = arr[j-1];
                arr[j-1]=x;
            }
        }
    }

    for(int i =0;i<n;++i)
    {
        System.out.print(arr[i] + " ");
    }
}
 public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    System.out.println("ENter the operation to perform\n1.To calculate and display the roots of Quadratic Equation.\n2.To multiply two arrays and display the result\n3.To sort the elements in ascending and descending order using bubble sort algorithm.");
    int n = s.nextInt();s.nextLine();
    if(n==1)
        roots(s);
    if(n==2)
        prod(s);
    if(n==3)
        sort(s);
    
    
    
    s.close();
 }
    
}