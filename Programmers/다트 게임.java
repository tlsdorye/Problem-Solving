import java.util.*;

class Solution {

	public void getBouns(ArrayList<Integer> point, char c) {
		int lastIdx = point.size() - 1;
		int p = point.get(lastIdx);
		if (c == 'S') return;
		else if (c == 'D') point.set(lastIdx, p * p);
		else if (c == 'T') point.set(lastIdx, p * p * p);
	}

	public void getOption(ArrayList<Integer> point, char c) {
		int lastIdx = point.size() - 1;
		int p = point.get(lastIdx);
		if (c == '*') {
			point.set(lastIdx, p * 2);
			if (lastIdx > 0) point.set(lastIdx - 1, point.get(lastIdx - 1) * 2);
		}
		else if (c == '#') point.set(lastIdx, -p);
	}

	public int solution(String dartResult) {
		int answer = 0;

		ArrayList<Integer> point = new ArrayList<Integer>();

		String stk = "";
		for (int i = 0; i < dartResult.length(); i++) {
			char c = dartResult.charAt(i);
			if ('0' <= c && c <= '9') stk += c;
			else {
				if (!"".equals(stk)) {
					int cur = Integer.parseInt(stk);
					point.add(cur);
					stk = "";
				}

				if (c == 'S' || c == 'D' || c == 'T') getBouns(point, c);
				else if (c == '*' || c == '#') getOption(point, c);
			}

		}
		for (int x : point) answer += x;

		return answer;
	}
}