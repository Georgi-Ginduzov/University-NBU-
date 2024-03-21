package building;

public class Room {
    private double roomArea;
    private Building building;

    public Room(double roomArea, Building building) {
        this.roomArea = roomArea;
        this.building = building;
    }

    public double getRoomArea() {
        return roomArea;
    }

    public void setRoomArea(double roomArea) {
        this.roomArea = roomArea;
    }

    public Building getBuilding() {
        return building;
    }

    public void setBuilding(Building building) {
        this.building = building;
    }

    @Override
    public String toString() {
        return "Room{" +
                "roomArea=" + roomArea +
                ", building=" + building +
                '}';
    }
}
