import java.io.*;
import java.util.*;

public class Main {

	static int cnt;
	static List<Integer> pos;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String origin = br.readLine();
		String pattern = br.readLine();

		pos = new ArrayList<>();
		KMP(origin, pattern);
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(cnt + "\n");
		for (Integer i : pos)
			bw.write(i + " ");
		bw.flush();

	}

	static int[] getPi(String pattern) {
		int[] pi = new int[pattern.length()];
		int j = 0;
		for (int i = 1; i < pattern.length(); i++) {
			while (j > 0 && pattern.charAt(i) != pattern.charAt(j))
				j = pi[j - 1];
			if (pattern.charAt(i) == pattern.charAt(j)) {
				pi[i] = ++j;
			}
		}
		return pi;
	}

	static void KMP(String origin, String pattern) {
		int[] pi = getPi(pattern);
		int j = 0;
		for (int i = 0; i < origin.length(); i++) {
			if (j > 0 && origin.charAt(i) != pattern.charAt(j)) j = pi[j - 1];
			if (origin.charAt(i) == pattern.charAt(j)) {
				if (j == pattern.length() - 1) {
					cnt++;
					pos.add(i - pattern.length() + 2);
					j = pi[j];
				} else j++;
			}
		}
	}
}
