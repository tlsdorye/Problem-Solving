import java.util.*;

class Solution {
	public String solution(String[] participant, String[] completion) {
		String answer = "";

		HashMap<String, Integer> map = new HashMap<String, Integer>();
		for (String c : completion) {
			map.computeIfPresent(c, (k, v) -> v + 1);
			map.computeIfAbsent(c, (k) -> 1);
		}
		
		for(String p : participant) {
			map.computeIfPresent(p, (k, v) -> v - 1);
			if(!map.containsKey(p) || map.get(p) < 0) {
				answer = p;
				break;
			}
		}

		return answer;
	}
}