package shop;

public abstract class Goods implements ProduceableAndSellable{
    private double overcharge;

    public Goods(double overcharge) {
        this.overcharge = overcharge;
    }

    public double getOvercharge() {
        return overcharge;
    }

    public abstract double productionPrice();
    @Override
    public double sellingPrice(){
        return ((this.overcharge/100) * this.productionPrice()) + this.productionPrice();
    }

    @Override
    public String toString() {
        return "Goods{" +
                "overcharge=" + overcharge +
                '}';
    }
}
