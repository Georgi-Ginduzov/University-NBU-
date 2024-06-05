package main.java.store.data.interfaces;

import java.io.Serializable;

public interface ItemInCart extends Serializable, Entity {
    int getQuantity();
    double getPrice();
    String getName();
}
