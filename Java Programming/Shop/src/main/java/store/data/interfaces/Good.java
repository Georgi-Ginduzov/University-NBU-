package main.java.store.data.interfaces;

import main.java.store.data.enums.GoodType;

import java.util.Date;
import java.util.UUID;

public interface Good {
    UUID getId();
    String getName();
    double getUnitDeliveryPrice();
    GoodType getType();
    Date getExpirationDate();
    int getQuantity();
}
