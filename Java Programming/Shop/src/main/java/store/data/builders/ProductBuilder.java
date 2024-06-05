package main.java.store.data.builders;

import main.java.store.data.Food;
import main.java.store.data.NonFood;
import main.java.store.data.enums.GoodType;
import main.java.store.data.interfaces.Entity;

import java.util.Date;
import java.util.UUID;

public class ProductBuilder extends Builder {
    private final UUID id; // uuid
    private final String name;
    private final double unitDeliveryPrice;
    private final GoodType type;
    private final Date expirationDate;
    private int quantity;
    private double foodTurover;
    private double nonFoodTurover;

    public ProductBuilder(String name, double unitDeliveryPrice, GoodType type, Date expirationDate, int quantity) {
        this.id = UUID.randomUUID();
        this.name = name;
        this.unitDeliveryPrice = unitDeliveryPrice;
        this.type = type;
        this.expirationDate = expirationDate;
        this.quantity = quantity;
    }

    public UUID getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getUnitDeliveryPrice() {
        return unitDeliveryPrice;
    }

    public GoodType getType() {
        return type;
    }

    public Date getExpirationDate() {
        return expirationDate;
    }

    public int getQuantity() {
        return quantity;
    }

    @Override
    public Entity build() {
        if (this.getType() == GoodType.EDIBLE){
            return new Food(this);
        }
        else {
            return new NonFood(this);
        }
    }
}
