package main.java.store.data.interfaces;

import java.io.Serializable;

public interface StoreEquipment extends Serializable {
    Staff getCurrentStaff();
    void setCurrentStaff(Staff staff);
    void changeOccupation();
}
