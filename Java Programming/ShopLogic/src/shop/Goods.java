package shop;

public class Goods {
    private double overcharge;

    public double productionPrice();
    public double sellingPrice(){
        return this.overcharge * this.productionPrice();
    }


}
