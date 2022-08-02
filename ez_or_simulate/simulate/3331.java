import java.io.*;
import java.util.*;
import java.math.*;

public class Main 
{
     static public void main(String[] args)
    {
         Scanner cin = new Scanner(new BufferedInputStream(System.in));
         int t = cin.nextInt();
         while (t-- != 0)
        {
            int a = cin.nextInt();
            String s = cin.next();
            char ch = s.charAt(0);
            BigInteger ans = new BigInteger("1");
            for (int i = 2; i <= a; i++)
                ans = ans.multiply(BigInteger.valueOf(i));
            s = ans.toString();
            int len = s.length();
            int x = 0;
            for (int i = 0; i < len; i++)
            if (s.charAt(i) == ch)
                    x++;
            System.out.println(x);
        }
    }
}
