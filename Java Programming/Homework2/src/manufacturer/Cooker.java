package manufacturer;

public class Cooker extends ElectricDevice{
    private int isGasoline;

    public Cooker(Manufacturer object, int minimalWarranty, int isGasoline) {
        super(object, minimalWarranty);
        this.isGasoline = isGasoline;
    }

    public int getIsGasoline() {
        return isGasoline;
    }
    public void setGasoline(int gasoline) {
        isGasoline = gasoline;
    }

    @Override
    public int warranty() {
        if (getIsGasoline() == 1)
            return super.warranty() + 12;
        else
            return super.warranty();
    }

    @Override
    public String toString() {
        return "Cooker{" +
                "isGasoline=" + isGasoline +
                '}';
    }
}
