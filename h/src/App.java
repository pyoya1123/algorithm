import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        String[] arr = s.split("\\(");
        arr[arr.length-1] = arr[arr.length-1].split("\\)")[0];

        long tmp = (long)(Math.log10(Integer.parseInt(arr[arr.length-1])) + 1);
        for(int i=arr.length-2;i>=0;i--){
            long t = Integer.parseInt(arr[i]);
            tmp *= (t%10);
            if(t >= 10) {
                tmp += (long)(Math.log10((t/10))) + 1;
            } 
        }
        System.out.println(tmp);
    }
}
