import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Boj1003{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int arr[][] = new int[41][2];
        arr[0] = new int[]{1, 0};
        arr[1] = new int[]{0, 1};
        for(int i = 2; i <= 40; i++){
            arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
            arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(br.readLine());
            sb.append(arr[a][0]).append(" ").append(arr[a][1]).append("\n");

        }
        System.out.println(sb);
    }
}