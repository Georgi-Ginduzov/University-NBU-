class Result {
    private int bottom;
    private int top;
    private int difference;

    public Result(int bottom, int top, int difference) {
        this.bottom = bottom;
        this.top = top;
        this.difference = difference;
    }

    // TODO: implement a function which calculates the digit count
    //  and returns the limit of an for loop

    public int swapDigitsPosition(int number){
        int temp = number, digits = 0, rem = 0;
        System.out.print("Begin swapping. Number = " + number);
        while(temp>0){
            temp /= 10;
            digits++;
        }

        if (digits < 2){
            return number;
        }
        else {
            temp = number;
            while(temp>0)
            {
                rem = temp%10;
                rev = (rev*10) + rem;
                temp = temp/10;
            }
            if(digits==2)
            {
                System.out.println("\nFirst and Last Digit Interchanged Successfully!");
                System.out.println("\nThe New Number = " + number);
            }
            else
            {

            }
        }
        System.out.println("\nFirst and Last Digit Interchanged Successfully!");
        System.out.println("\nThe new number = " + number);
        return number;
    }

    public int countNumbers(int bottom, int top, int difference) {
        int validNumberCount = 0;
        int swappedPositionNumber = 0;

        for (int i = top; i > bottom; i--){
            swappedPositionNumber = this.swapDigitsPosition(i);
            if (swappedPositionNumber - i >= difference){
                validNumberCount++;
            }
        }
        return validNumberCount;
    }

}

public class Main {
    public static void main(String[] args) {
        int bottom = 1180, top = 1200, difference = 700;
        Result result = new Result(bottom, top, difference);

        int count = result.countNumbers(bottom, top, difference);

        System.out.print(count);

    }
}