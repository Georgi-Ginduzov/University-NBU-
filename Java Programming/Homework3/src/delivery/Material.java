package delivery;

public class Material {
    private String name;
    private int fragile;

    public Material(String name, int fragile) {
        this.name = name;
        this.fragile = fragile;
    }

    public boolean isFragile(int input){
        if (input == 1)
            return true;
        else
            return false;
    }
}
