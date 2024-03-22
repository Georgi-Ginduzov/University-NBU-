package delivery;

public class Document implements Deliverable{
    private double minimalDeliveryPrice;
    private double additionalDeliveryPrice;

    @Override
    public double deliveryPrice() {
        // Todo
        return 0;
    }
}
