import java.util.*;
import java.math.*;

/*

题意：有n个城市，它们由一个污水处理系统连接着，每个城市可以选择
1、将左边城市过来的污水和右边城市过来的污水连同本身的污水排到河里
2、将左边来的污水连同自己的污水排到右边
3、将右边来的污水连同自己的污水排到左边
问总共有多少种处理情况
dp[i][0] = dp[i-1][0] + dp[i-1][1]；
dp[i][1] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
dp[i][2] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
整理为：dp[i] = 3 * dp[i-1] + dp[i-2]。


*/

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		BigInteger d[] = new BigInteger[105];
		d[1] = BigInteger.ONE;
		d[2] = BigInteger.valueOf(3);
		for (int i = 3; i <= 100; ++i)
			d[i] = d[i - 1].multiply(d[2]).subtract(d[i - 2]);
		while (in.hasNext())
			System.out.println(d[in.nextInt()]);
		in.close();
	}
}
