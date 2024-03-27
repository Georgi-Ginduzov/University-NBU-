package delivery;

public class DeliverableItem implements Deliverable{
    private int deliverToClient;
    private double additionalPrice;

    public DeliverableItem(int deliverToClient) {
        this.deliverToClient = deliverToClient;
    }


    @Override
    public double deliveryPrice() {
        //TOdo
        double price = 0;
        return 0;
    }
}
