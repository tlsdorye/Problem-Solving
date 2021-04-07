import java.util.*;

class Solution {
	public int[] solution(int[] numbers) {
		int[] answer = {};

		TreeSet<Integer> set = new TreeSet<>();
		for (int i = 0; i < numbers.length; i++)
			for (int j = i + 1; j < numbers.length; j++) set.add(numbers[i] + numbers[j]);
		answer = new int[set.size()];

		int idx = 0;
		for (int x : set) answer[idx++] = x;

		return answer;
	}
}