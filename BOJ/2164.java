import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int X = 1;
		while(N > X) X*=2;
		System.out.println(X - (X - N) * 2);
	}
}