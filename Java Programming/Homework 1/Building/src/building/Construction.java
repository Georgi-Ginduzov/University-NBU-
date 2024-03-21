package building;

public class Construction {
    private double area;

    public Construction(double area) {
        this.area = area;
    }

    public double getArea() {
        return area;
    }

    public void setArea(double area) {
        this.area = area;
    }

    @Override
    public String toString() {
        return "Construction{" +
                "area=" + area +
                '}';
    }
}
