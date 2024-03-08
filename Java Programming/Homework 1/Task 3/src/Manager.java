import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Manager{
    private String name;
    private LocalDate dateOfHire;

    public Manager(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public LocalDate getDateOfHire() {
        return dateOfHire;
    }
    public void setDateOfHire(LocalDate dateOfHire, LocalDate dateOfLeaving) {
        if(dateOfHire.isAfter(dateOfLeaving)){
            System.out.print("Enter valid date of leaving!");
            return;
        }

        this.dateOfHire = dateOfHire;
    }

    public long numberOfYearsInCompanyTill(LocalDate futureDate)
    {
        return ChronoUnit.YEARS.between(getDateOfHire(), futureDate);
    }

}
