package main.java.store.data;

import main.java.store.data.enums.GoodType;

import java.util.Date;

public class Food extends Product{
    public Food(String name, double unitDeliveryPrice, GoodType type, Date expirationDate, int quantity) {
        super(name, unitDeliveryPrice, type, expirationDate, quantity);
    }

}
