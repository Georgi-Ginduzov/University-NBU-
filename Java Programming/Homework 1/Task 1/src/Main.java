import java.util.Scanner;

public class Main {
    public static int moveDigitsPosition(int number){
        char[] originalNumbers = String.valueOf(number).toCharArray();
        char[] movedDigitsNumber = new char[originalNumbers.length];

        char firstDigit = originalNumbers[0];
        for (int i = 0; i < originalNumbers.length - 1; i++){
            movedDigitsNumber[i] = originalNumbers[i+1];
        }
        movedDigitsNumber[movedDigitsNumber.length - 1] = firstDigit;

        return Integer.parseInt(String.valueOf(movedDigitsNumber));
    }
    public static int countNumbers(int bottom, int top, int difference) {
        int validNumberCount = 0;
        int swappedDigitsPositionNumber = 0;

        for (int i = top; i > bottom; i--){
            swappedDigitsPositionNumber = moveDigitsPosition(i);
            if (swappedDigitsPositionNumber - i > difference){
                validNumberCount++;
            }
        }
        return validNumberCount;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int bottom = input.nextInt();
        int top = input.nextInt();
        int difference = input.nextInt();
        int validNumbers = 0;

        if (bottom >= 0 && top >= 0){
            validNumbers = countNumbers(bottom, top, difference);
        }

        System.out.print(validNumbers);
    }
}