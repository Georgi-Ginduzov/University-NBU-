package building;

public class Building {
    private double buildingArea;

    public Building(double buildingArea) {
        this.buildingArea = buildingArea;
    }

    public double getbuildingArea() {
        return buildingArea;
    }

    public void setbuildingArea(double buildingArea) {
        this.buildingArea = buildingArea;
    }

    @Override
    public String toString() {
        return "Building{" +
                "buildingArea=" + buildingArea +
                '}';
    }
}
