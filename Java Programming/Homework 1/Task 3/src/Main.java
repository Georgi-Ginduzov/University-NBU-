import java.time.LocalDate;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String name = input.nextLine();
        int yearOfHiring = input.nextInt();
        int monthOfHiring = input.nextInt();
        int dayOfHiring = input.nextInt();
        int yearOfLeaving = input.nextInt();
        int monthOfLeaving = input.nextInt();
        int dayOfLeaving = input.nextInt();

        Manager manager = new Manager(name);
        LocalDate hiringDate = LocalDate.of(yearOfHiring, monthOfHiring, dayOfHiring);
        LocalDate leavingDate = LocalDate.of(yearOfLeaving, monthOfLeaving, dayOfLeaving);
        manager.setDateOfHire(hiringDate, leavingDate);

        System.out.print(manager.getDateOfHire());
        System.out.print("\n" + manager.numberOfYearsInCompanyTill(leavingDate));

    }
}