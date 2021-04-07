import java.math.BigInteger;
import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.next();
		
		BigInteger N = new BigInteger(input);
		BigInteger S = BigInteger.ONE;
		BigInteger E = new BigInteger(input);
		BigInteger TWO = new BigInteger("2");
		BigInteger M = null;
		
		while(S.compareTo(E) <= 0) {
			M = (S.add(E)).divide(TWO);
			int ret = (M.multiply(M)).compareTo(N);
			
			if(ret == 0) break;
			else if(ret < 0) S = M.add(BigInteger.ONE);
			else if(ret > 0) E = M.subtract(BigInteger.ONE);
		}
		System.out.println(M);
	}
}