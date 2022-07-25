import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int base;
		while(true){
			base = cin.nextInt();
			if(base == 0) break;
			BigInteger a = cin.nextBigInteger(base);
			BigInteger b = cin.nextBigInteger(base);
			BigInteger c = a.mod(b);
			System.out.println(c.toString(base));
		}
	}
}

