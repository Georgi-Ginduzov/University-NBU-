package delivery;

public class Material {
    private String name;
    private int fragile;

    public Material(String name, int fragile) {
        this.name = name;
        this.fragile = fragile;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getFragile() {
        return fragile;
    }

    public void setFragile(int fragile) {
        this.fragile = fragile;
    }

    public boolean isFragile(int input){
        return input == 1;
    }
}
