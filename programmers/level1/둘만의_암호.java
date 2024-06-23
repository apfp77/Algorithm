public class 둘만의_암호 {
    static class Solution {
        public String solution(String s, String skip, int index) {
            StringBuilder answer = new StringBuilder();
            for (char c: s.toCharArray()) {
                char tmp = c;
                int i = 0;
                while (i < index){
                    tmp =  tmp == 'z' ? 'a' : (char) (tmp + 1);
                    if (skip.indexOf(tmp) > -1) {
                        continue;
                    }
                    i++;
                }
                answer.append(tmp);
            }
            return answer.toString();
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution("aukks","wbqd",5));
    }
}
