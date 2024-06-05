package main.java.store.data.entities;

import main.java.store.data.interfaces.Staff;
import main.java.store.data.interfaces.StoreEquipment;

public abstract class Equipment implements StoreEquipment {
    private Staff currentStaff;
    private boolean isOccupied;

    public Equipment() {
        isOccupied = false;
        currentStaff = null;
    }

    @Override
    public Staff getCurrentStaff() {
        return currentStaff;
    }

    @Override
    public void setCurrentStaff(Staff staff) {
        if (staff == null) {
            throw new IllegalArgumentException("Staff cannot be null");
        }

        currentStaff = staff;
        changeOccupation();
    }

    @Override
    public void changeOccupation(){
        isOccupied = !isOccupied;
    }
}
