import java.math.BigDecimal;

public class Studio {
    private final int id;
    private BigDecimal rentPerHour;
    private BigDecimal maxDailyRentHours;
    private BigDecimal todaysRentHours;
    private BigDecimal minimalRentPerHour;
    private BigDecimal bgnToEuro;

    public Studio(int id, BigDecimal maxDailyRentHours) {
        this.id = id;
        setMaxDailyRentHours(maxDailyRentHours);
    }

    public void setMinimalRentPerHour(BigDecimal minimalRentPerHour) {
        if (minimalRentPerHour.compareTo(BigDecimal.valueOf(0)) < 0){
            this.minimalRentPerHour = BigDecimal.valueOf(0);
        }
        else {
            this.minimalRentPerHour = minimalRentPerHour;
        }
    }
    public void setRentPerHour(BigDecimal rentPerHour){
        if (rentPerHour.compareTo(this.minimalRentPerHour) < 0) {
            this.rentPerHour = this.minimalRentPerHour;
        }
        else {
            this.rentPerHour = rentPerHour;
        }
    }
    public void setTodaysRentHours(BigDecimal todaysRentHours){
        if (todaysRentHours.compareTo(this.maxDailyRentHours) > 0) {
            this.todaysRentHours = this.maxDailyRentHours;
        }
        else {
            this.todaysRentHours = todaysRentHours;
        }
    }
    public void setBgnToEuro(BigDecimal bgnToEuro){
        this.bgnToEuro = bgnToEuro;
    }
    public void setMaxDailyRentHours(BigDecimal maxDailyRentHours){
        if (maxDailyRentHours.compareTo(BigDecimal.valueOf(24)) > 0){
            this.maxDailyRentHours = BigDecimal.valueOf(24);
        } else if (maxDailyRentHours.compareTo(BigDecimal.valueOf(0)) < 0) {
            this.maxDailyRentHours = BigDecimal.valueOf(24);
        }
        else {
            this.maxDailyRentHours = maxDailyRentHours;
        }
    }

    public int getId() {
        return id;
    }
    public BigDecimal getRentPerHour() {
        return rentPerHour;
    }
    public BigDecimal getMaxDailyRentHours() {
        return maxDailyRentHours;
    }
    public BigDecimal getTodaysRentHours() {
        return todaysRentHours;
    }
    public BigDecimal getMinimalRentPerHour() {
        return minimalRentPerHour;
    }
    public BigDecimal getBgnToEuro() {
        return bgnToEuro;
    }

    public BigDecimal dailyEarningsInBgn(){
        return getRentPerHour().multiply(getTodaysRentHours());
    }
    public  BigDecimal dailyEarningsInEuro(){
        return dailyEarningsInBgn().multiply(getBgnToEuro());
    }
    public Studio moreExpensiveStudio(Studio studio){
        int comparisson = getRentPerHour().compareTo(studio.getRentPerHour());
        if (comparisson > 0){
            return this;
        }
        else {
            return studio;
        }
    }
    public boolean studioWithMoreEarnings(Studio studio){
        BigDecimal currentStudiosEarnings = getRentPerHour().multiply(getTodaysRentHours());
        BigDecimal otherStudiosEarnings = studio.getRentPerHour().multiply(studio.getTodaysRentHours());

        if (currentStudiosEarnings.compareTo(otherStudiosEarnings) > 0){
            return true;
        }
        else {
            return false;
        }
    }
}
