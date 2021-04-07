import java.util.*;

class Solution {
	public String[] solution(int n, int[] arr1, int[] arr2) {
		String[] answer = new String[n];
		String[] map = new String[n];

		for (int i = 0; i < n; i++) {
			answer[i] = "";
			map[i] = Integer.toBinaryString(arr1[i]);
			while (map[i].length() < n) map[i] = "0" + map[i];
		}

		for (int i = 0; i < n; i++) {
			String s = Integer.toBinaryString(arr2[i]);
			while (s.length() < n) s = "0" + s;
			for (int j = 0; j < n; j++) {
				if (map[i].charAt(j) == '1' || s.charAt(j) == '1') answer[i] += "#";
				else if (map[i].charAt(j) == '0' && s.charAt(j) == '0') answer[i] += " ";
			}
		}
		return answer;
	}
}