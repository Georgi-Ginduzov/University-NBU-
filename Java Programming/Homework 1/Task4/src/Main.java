import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int id = input.nextInt();
        BigDecimal maxWorkingHours = input.nextBigDecimal();
        BigDecimal minPricePerHour = input.nextBigDecimal();
        BigDecimal currencyEuro = input.nextBigDecimal();
        BigDecimal pricePerHour = input.nextBigDecimal();
        BigDecimal workedHours = input.nextBigDecimal();

        Studio studio1 = new Studio(id, maxWorkingHours);
        studio1.setBgnToEuro(currencyEuro);
        studio1.setMinimalRentPerHour(minPricePerHour);
        studio1.setRentPerHour(pricePerHour);
        studio1.setTodaysRentHours(workedHours);

        id = input.nextInt();
        maxWorkingHours = input.nextBigDecimal();
        pricePerHour = input.nextBigDecimal();
        workedHours = input.nextBigDecimal();

        Studio studio2 = new Studio(id, maxWorkingHours);
        studio2.setMinimalRentPerHour(minPricePerHour);
        studio2.setRentPerHour(pricePerHour);
        studio2.setBgnToEuro(currencyEuro);
        studio2.setTodaysRentHours(workedHours);

        System.out.print(studio1.dailyEarningsInBgn() + "\n");
        System.out.print(studio1.dailyEarningsInEuro()+ "\n");
        System.out.print(studio1.moreExpensiveStudio(studio2).getId()+ "\n");
        System.out.print(studio1.studioWithMoreEarnings(studio2));


    }
}
