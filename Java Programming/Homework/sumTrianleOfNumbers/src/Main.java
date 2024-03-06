import java.util.Scanner;

public class Main {

    public static int rowSum(int limitNumber, int n){
        int sum = 0;

        for (int i = limitNumber; i <= n; i++)
        {
            sum += i;
        }
        for (int j = n; j >= limitNumber; j--) // Does it need to be >= 0?
        {
            sum += j;
        }

        return sum;
    }
    public static int calculateSum(int n) {
        int sum = 0;

        for (int i = 1; i <= n; i++){
            sum += rowSum(i, n);

        }
        for (int j = n - 1; j > 0; j--){
            sum += rowSum(j, n);
        }

        return sum;
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        int n = Integer.parseInt(myObj.nextLine());

        if (n >= 1 && n <= 9){
            int sum = calculateSum(n);
            System.out.print(sum);
        }
        else{
            System.out.print(0);
        }
    }
}