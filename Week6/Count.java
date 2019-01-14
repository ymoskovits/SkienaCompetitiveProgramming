import java.util.*;
import java.math.BigInteger;
import java.io.*;
class Main{
	public static void main(String[] args){
		BigInteger[] ans = new BigInteger[2002];
		int num, highest_solved = 3;
		ans[1] = new BigInteger("2");
		ans[2] = new BigInteger("5");
		ans[3] = new BigInteger("13"); 
		Scanner in = new Scanner(System.in);

		while(in.hasNextInt()){
			num = in.nextInt();
			while(highest_solved <= num){
				highest_solved++;
				ans[highest_solved] = ans[highest_solved - 1].add(ans[highest_solved - 1]).add(ans[highest_solved - 2]).add(ans[highest_solved - 3]);
			}
			System.out.println(ans[num]);
		}
	}
}