package manufacturer;

public class WashingMachine extends ElectricDevice{
    private int canDryClothes;

    public WashingMachine(Manufacturer object, int minimalWarranty, int canDryClothes) {
        super(object, minimalWarranty);
        this.canDryClothes = canDryClothes;
    }

    public int getCanDryClothes() {
        return canDryClothes;
    }

    @Override
    public int warranty(){
        if (getCanDryClothes() == 1)
            return super.warranty() + (int)(0.5 * getMinimalWarranty());
        else
            return super.warranty();
    }
}
