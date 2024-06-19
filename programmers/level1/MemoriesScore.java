import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
                int[] answer = new int[photo.length];
        int i = 0;
        for(String[] str: photo){
            HashMap<String, Integer> map = new HashMap<String, Integer>();
            for (String node: str){
                map.compute(node, (k, v) -> (v == null) ? 1 : v + 1);
            }
            for (int j = 0; j < name.length; j++) {
                Integer value = map.get(name[j]);
                if (value != null) answer[i] += value * yearning[j];
            }
            i++;
        }
        return answer;
    }
}


class MemoriesScore{
	public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(Arrays.toString(s.solution(new String[]{"may", "kein", "kain", "radi"}, new int[]{5, 10, 1, 3}, 
        new String[][]{{"may", "kein", "kain", "radi"},{"may", "kein", "brin", "deny"}, {"kon", "kain", "may", "coni"}})));

        System.out.println(Arrays.toString(s.solution(new String[]{"kali", "mari", "don"}, new int[]{11, 1, 55}, 
        new String[][]{{"kali", "mari", "don"},{"pony", "tom", "teddy"}, {"con", "mona", "don"}})));
        
        System.out.println(Arrays.toString(s.solution(new String[]{"may", "kein", "kain", "radi"}, new int[]{5, 10, 1, 3}, 
        new String[][]{{"may"},{ "kein", "deny", "may"}, {"kon", "coni"}})));
    }
} 