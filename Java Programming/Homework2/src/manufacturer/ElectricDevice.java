package manufacturer;

public class ElectricDevice extends Manufacturer{
    private int minimalWarranty;

    public ElectricDevice(Manufacturer object, int minimalWarranty) {
        super(object);
        this.minimalWarranty = minimalWarranty;
    }

    public int getMinimalWarranty() {
        return minimalWarranty;
    }

    public void setMinimalWarranty(int minimalWarranty) {
        if (minimalWarranty >= 6){
            this.minimalWarranty = minimalWarranty;
        }

    }

    public int warranty(){
        if (this.hasAdditionalGuarantee() == 1)
            return getMinimalWarranty() + 12;
        else
            return getMinimalWarranty();
    }

    @Override
    public String toString() {
        return "ElectricDevice{" +
                "minimalWarranty=" + minimalWarranty +
                '}';
    }
}
