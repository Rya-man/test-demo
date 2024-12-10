import java.util.*;

public class Main {

    public static float Area(Scanner s)
    {
        float a = s.nextFloat();
        s.nextLine();
        float b = s.nextFloat();
        return a*b;
    }

    public static void Arrayops(Scanner s)
    {
        int size = s.nextInt();s.nextLine();
        int[] a1 = new int[size];
        int[] a2 = new int[size];
        int[] b = new int[size];
        for(int i =0;i<size;++i)
        {
            a1[i]=s.nextInt();
            s.nextLine();
        }
        for(int i =0;i<size;++i)
        {
            a2[i]=s.nextInt();
            s.nextLine();
            b[i]=a1[i]*a2[i];
        }
        for(int i =0;i<size;++i)
        System.out.print(b[i]+" ");

        for(int i =0;i<size;++i)
        {
            for(int j =0;j<size-i-1;++j)
            if(b[j]<b[j+1])
            {
                int ax = b[j];
                b[j]=b[j+1];
                b[j+1]=ax;
            }
        }
        for(int i =0;i<size;++i)
        System.out.print(b[i]+" ");

    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Arrayops(s);
        System.out.println(Area(s));
    }


}