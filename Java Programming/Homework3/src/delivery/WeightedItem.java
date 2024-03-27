package delivery;

import java.util.Map;

public class WeightedItem extends Material implements Deliverable {
    private double weightKilograms;
    private double deliveryPricePerKilogram;

    public WeightedItem(String name, int fragile, double weightKilograms, double deliveryPricePerKilogram) {
        super(name, fragile);
        this.weightKilograms = weightKilograms;
        this.deliveryPricePerKilogram = deliveryPricePerKilogram;
    }

    @Override
    public double deliveryPrice() {

        return 0;
    }
}
