package manufacturer;

public class Manufacturer {
    private String name;
    private int additionalGuarantee;

    public Manufacturer(String name, int additionalGuarantee) {
        this.name = name;
        this.additionalGuarantee = additionalGuarantee;
    }
    public Manufacturer(Manufacturer object){
        this.name = object.name;
        this.additionalGuarantee = object.additionalGuarantee;
    }

    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }

    public int hasAdditionalGuarantee() {
        return additionalGuarantee;
    }
    public void setAdditionalGuarantee(int additionalGuarantee) {
        this.additionalGuarantee = additionalGuarantee;
    }

    @Override
    public String toString() {
        return "Manufacturer{" +
                "name='" + name + '\'' +
                ", additionalGuarantee=" + additionalGuarantee +
                '}';
    }
}
