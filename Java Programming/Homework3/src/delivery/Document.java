package delivery;

public class Document extends DeliverableItem implements Deliverable{
    private double minimalDeliveryPrice;
    private double additionalDeliveryPrice;

    public Document(double minimalDeliveryPrice, double additionalDeliveryPrice) {
        super();
        this.minimalDeliveryPrice = minimalDeliveryPrice;
        this.additionalDeliveryPrice = additionalDeliveryPrice;
    }

    public double getMinimalDeliveryPrice() {
        return minimalDeliveryPrice;
    }
    public void setMinimalDeliveryPrice(double minimalDeliveryPrice) {
        this.minimalDeliveryPrice = minimalDeliveryPrice > 0 ? minimalDeliveryPrice : 1.0;
    }

    public double getAdditionalDeliveryPrice() {
        return additionalDeliveryPrice;
    }
    public void setAdditionalDeliveryPrice(double additionalDeliveryPrice) {
        this.additionalDeliveryPrice = additionalDeliveryPrice > 0 ? minimalDeliveryPrice : 1.0;
    }

    @Override
    public double deliveryPrice() {
        // Todo
        return 0;
    }
}
