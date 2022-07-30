import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
    public static void main(String Agrs[])
    {
        BigInteger[] data = new BigInteger[300];
        BigInteger two = new BigInteger("2");
        Scanner cin = new Scanner(System.in);

        data[0] = new BigInteger("1");
        data[1] = new BigInteger("1");
        data[2] = new BigInteger("3");

        for (int i = 3; i < 255; i++)
        {
            data[i] = (data[i-2].multiply(two).add(data[i-1]));
        }
        while (cin.hasNext())
        {
            int n = cin.nextInt();
            System.out.println(data[n]);
        }
    }
}
