/*
 * Program-5 (program to illustrate compile time polymorphism)
 *
 */
import java.util.*;
public class Main {
    public static boolean substring(String a,String b)
    {
        if(b.length()>a.length())
        return false;
        int i =0;
        for(i =0;i<=a.length()-b.length();++i)
        {
            boolean x = true;
            for(int j=0;j<b.length();++j)
            {
                if(a.charAt(i+j)==b.charAt(j))
                {
                    continue;
                }
                else
                {
                    x=false;
                    break;
                }
            }
            if(x)
            {
                return true;
            }
        }  
        return false;
    }
    public static String stringreverse(String a)
    {
        if(a=="")
        return "";
        String b = "";
        for(int i =a.length()-1;i>=0;--i)
        {
            b+=a.charAt(i);
        }
        return b;
    }
    public static int min(int a,int b)
    {
        return a<b?a:b;
    }
   
    public static int min(int a,int b,int n)
    {
        if(a<b)
            return a<n?a:n;
        return b<n?b:n;
    }
    public static int usrstrcmp(String a, String b)
    {
        int s1 = a.length();
        int s2 = b.length();
        int i;
        for(i =0;i<min(s1,s2);++i)
        {
            if(a.charAt(i)<b.charAt(i))
                return -1;
            if(a.charAt(i)>b.charAt(i))
                return 1;
        }
        if(i<b.length())
            return -1;
        if(i<a.length())
            return 1;
        return 0;
    }
    public static int usrstrcmp(String a, String b,int n)
    {
        int s1 = a.length();
        int s2 = b.length();
        int i;
        for(i =0;i<min(s1,s2,n);++i)
        {
            if(a.charAt(i)<b.charAt(i))
                return -1;
            if(a.charAt(i)>b.charAt(i))
                return 1;
        }
        if(i<n){
            if(i<b.length())
                return -1;
            if(i<a.length())
                return 1;
        }
        return 0;
    }






    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the number of testcases");
        int n  = s.nextInt();
        s.nextLine();
        while(n>0){
            n-=1;
            System.out.println("ENtrer option\n1. STring Reverse\n2. Check Substring\n3.String compare first\n4.String Compare second ");
            int ch = s.nextInt();
            s.nextLine();
            if(ch==1)
            {
                System.out.println("Enter the string");
                String s1 = s.nextLine();
                System.out.println(stringreverse(s1));
            }
            if(ch==2){
                System.out.println("Enter the 2 strings");
                String s1 = s.nextLine();
                String s2 = s.nextLine();
                System.out.println(substring(s1, s2));
            }
            if(ch==3)
            {
                System.out.println("Enter the 2 strings");
                String s1 = s.nextLine();
                String s2 = s.nextLine();
                System.out.println(usrstrcmp(s1,s2));
            }
            if(ch==4)
            {
                System.out.println("Enter the 2 strings");
                String s1 = s.nextLine();
                String s2 = s.nextLine();
                System.out.println("Enter range of length");
                int NUM = s.nextInt();
                System.out.println(usrstrcmp(s1, s2, NUM));
            }
        }
        s.close();
    }


}
