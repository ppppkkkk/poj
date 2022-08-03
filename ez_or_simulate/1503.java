import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger sum = BigInteger.valueOf(0);
        BigInteger a;
        a = cin.nextBigInteger();
        while (true) {
            sum = sum.add(a);
            if (a.compareTo(BigInteger.valueOf(0)) == 0)
                break;
            a = cin.nextBigInteger();
        }
        System.out.println(sum);
    }
}
