package main.java.store.data.interfaces;

import main.java.store.data.enums.GoodType;

import java.io.Serializable;
import java.util.Date;
import java.util.UUID;

public interface Good extends Serializable, Entity {
    UUID getId();
    String getName();
    double getUnitDeliveryPrice();
    GoodType getCategory();
    Date getExpirationDate();
    int getQuantity();
    void decreaseQuantity(int quantity);
    void increaseQuantity(int quantity);
}
