package main.java.store.data.entities;

import main.java.store.data.builders.ProductBuilder;
import main.java.store.data.enums.GoodType;
import main.java.store.data.interfaces.Good;

import java.util.Date;
import java.util.UUID;

public abstract class Product implements Good {
    private final UUID id; // uuid
    private final String name;
    private final double unitDeliveryPrice;
    private final GoodType type;
    private final Date expirationDate;
    private int quantity;

    public Product(ProductBuilder builder) {
        this.id = builder.getId();
        this.name = builder.getName();
        this.unitDeliveryPrice = builder.getUnitDeliveryPrice();
        this.type = builder.getType();
        this.expirationDate = builder.getExpirationDate();
        this.quantity = builder.getQuantity();
    }

    @Override
    public UUID getId() {
        return id;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public double getUnitDeliveryPrice() {
        return unitDeliveryPrice;
    }

    @Override
    public GoodType getCategory() {
        return type;
    }

    @Override
    public Date getExpirationDate() {
        return expirationDate;
    }

    public int getQuantity() {
        return quantity;
    }

    // Decrease the quantity in stock
    public void decreaseQuantity(int amount) {
        this.quantity -= amount;
    }
    public void increaseQuantity(int amount) {
        this.quantity += amount;
    }
}
