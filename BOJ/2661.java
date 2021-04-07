import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {

	static int N;
	static boolean finish = false;
	static int[] ret = new int[81];

	public static void main(String[] args) throws FileNotFoundException {
		//System.setIn(new FileInputStream("./src/input.txt"));
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();

		makeSequence(1, 0);
		for (int i = 1; i <= N; i++)
			System.out.print(ret[i]);
	}

	static void makeSequence(int depth, int selNum) {
		if (depth > N) finish = true;
		if (finish) return;

		for (int i = 1; i <= 3 && !finish; i++) {
			if (i == selNum) continue;
			ret[depth] = i;
			if (!checkGood(depth)) continue;
			makeSequence(depth + 1, i);
		}
	}

	static boolean checkGood(int pos) {
		for (int step = 1; pos - step * 2 >= 0; step++) {
			int idx = pos - step;
			boolean flag = true;
			for (int i = 0; i < step; i++)
				if (ret[idx - i] != ret[pos - i]) {
					flag = false;
					break;
				}
			if (flag) return false;
		}
		return true;
	}
}
