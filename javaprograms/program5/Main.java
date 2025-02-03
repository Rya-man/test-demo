import java.util.*;

public class Main {
    public static int usrstrcmp(String a,String b)
    {
        for(int i =0;i<Math.min(a.length(),b.length());++i)
        {
            if(a.charAt(i)<b.charAt(i))
            return -1;
            if(a.charAt(i)>b.charAt(i))
            return 1;
        }
        if(a.length()<b.length())
        return -1;
        if(a.length()>b.length())
        return 1;
        return 0;
    }

    public static int usrstrcmpn(String a,String b,int n)
    {
        if (n>a.length() || n>b.length())
        return usrstrcmp(a, b);
        for(int i =0;i<n;++i)
        {
            if(a.charAt(i)<b.charAt(i))
            return -1;
            if(a.charAt(i)>b.charAt(i))
            return 1;
        }
        return 0;
    }

    public static void main(String[] args) {
        
    }
    
}