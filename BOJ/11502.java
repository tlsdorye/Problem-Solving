import java.io.*;
import java.util.*;

public class Main {
	static Vector<Integer> v = new Vector<Integer>();

	static void getPrime() {
		boolean primeCheck[] = new boolean[1000];
		v.add(2);
		for (int i = 3; i < primeCheck.length; i += 2) {
			if (!primeCheck[i]) {
				v.add(i);
				for (int j = 2; i * j < primeCheck.length; j++)
					primeCheck[i * j] = true;
			}
		}
		return;
	}

	static void solve(int num) {
		int size = v.size();
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				for (int k = 0; k < size; k++) {
					if (num == v.elementAt(i) + v.elementAt(j) + v.elementAt(k)) {
						System.out.println(v.elementAt(i) + " " + v.elementAt(j) + " " + v.elementAt(k));
						return;
					}
				}
		System.out.println(0);
		return;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		getPrime();
		int T = sc.nextInt();
		for (int k = 0; k < T; k++) {
			int num = sc.nextInt();
			solve(num);
		}
	}
}