package shop;

public class TaxiDriver extends RegisteredProvider{
    private double distance;
    private double pricePerKm;

    public TaxiDriver(String regNumber, double distance, double pricePerKm) {
        super(regNumber);
        this.distance = distance;
        this.pricePerKm = pricePerKm;
    }

    @Override
    public double earnings() {
        return this.distance * this.pricePerKm;
    }
}
