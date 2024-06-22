public class 카드뭉치 {
    static class Solution {

        public String solution(String[] cards1, String[] cards2, String[] goal) {
            String answer = "Yes";
            int idx_1 = 0;
            int idx_2 = 0;
            for(String str: goal){
                 if (idx_1 < cards1.length && str.equals(cards1[idx_1])){
                     idx_1++;
                 } else if (idx_2 < cards2.length && str.equals(cards2[idx_2])){
                     idx_2++;
                 } else{
                     return "No";
                 }
            }
            return answer;
        }
    }

    public static void main(String[] args) {
        System.out.println(new Solution().solution(new String[]{"i", "drink", "water"},new String[]{"want", "to"}, new String[]{"i", "want", "to", "drink", "water"}));
    }
}
