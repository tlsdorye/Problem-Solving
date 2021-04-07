import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static int N, M;
	static char[][] grid;

	public static void main(String[] args) throws FileNotFoundException {
		//System.setIn(new FileInputStream("./src/input.txt"));
		Scanner sc = new Scanner(System.in);

		N = sc.nextInt();
		M = sc.nextInt();

		grid = new char[N][M];
		for (int i = 0; i < N; i++) {
			String s = sc.next();
			for (int j = 0; j < M; j++)
				grid[i][j] = s.charAt(j);
		}

		boolean[] Rempty = new boolean[N];
		boolean[] Cempty = new boolean[M];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (grid[i][j] == 'X') {
					Rempty[i] = true;
					Cempty[j] = true;
				}

		int rcnt = 0, ccnt = 0;
		for (int i = 0; i < N; i++)
			if (!Rempty[i]) rcnt++;
		for (int j = 0; j < M; j++)
			if (!Cempty[j]) ccnt++;
		if(rcnt < ccnt) rcnt = ccnt;
		System.out.println(rcnt);
	}
}
