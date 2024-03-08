import People.Adult;
import videos.Video;
import java.math.BigDecimal;
import java.time.LocalDate;

public class Main {
    /*public static boolean isLeapYear(int year){
        return (year % 4 ==0 && year % 100 != 0) || year % 400 == 0;
    }

    public static int[] numberDivisors(int number){
        int[] divisors = {0, 1, 2};
        int count = 0;

        for (int i = 1; i < number; i++){
            if (number % i == 0){
                divisors[count] = i;
                count++;
            }
        }
        return divisors;
    }*/

    public static void main(String[] args) {
        // Calculate random number
        /*int bottom = 10_000;
        int top = 99_999;
        int randomNumber = (int)(Math.random() * (top - bottom) + bottom);
        System.out.print( randomNumber + "\n");*/

        Video video1 = new Video(1);
        //System.out.print(video1);

        Video video2 = new Video("Video 2", BigDecimal.valueOf(2.5), 10, 2);
        Video video3 = new Video("Video 3", BigDecimal.valueOf(4.5), 10, 3);

        BigDecimal sum = video2.getDuration().add(video3.getDuration());
        //System.out.print("Sum" + sum);

        LocalDate dateUpload = LocalDate.now();
        LocalDate dateUpload2 = LocalDate.of(2024, 6, 6);

        Adult adult = new Adult("Ivan", LocalDate.of(2021, 3
                , 4), BigDecimal.valueOf(1000), BigDecimal.ZERO, false);
        System.out.print(adult);

    }


}