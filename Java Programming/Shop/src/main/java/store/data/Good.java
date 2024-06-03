package main.java.store.data;

import main.java.store.data.enums.GoodType;

import java.util.Date;
import java.util.UUID;

public class Good{
    private final UUID id; // uuid
    private final String name;
    private double unitDeliveryPrice;
    private final GoodType type;
    private final Date expirationDate;
    private int quantity;

    public Good(String name, double unitDeliveryPrice, GoodType type, Date expirationDate, int quantity) {
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

    public double getSellingPrice(double turnover, double discount, int expirationDaysForDiscount) {

        double sellingPrice = unitDeliveryPrice * turnover;



        long daysToExpirationDate = ((new Date().getTime() - expirationDate.getTime()) / (1000 * 60 * 60 * 24));

        if (daysToExpirationDate < expirationDaysForDiscount) {
            // Transform discount
            while(discount > 1) {
                discount /= 10;
            }

            sellingPrice *= discount;
        } else if (daysToExpirationDate < 0) {
            sellingPrice *= -1;
        }

        return sellingPrice;
    }

    // Decrease the quantity in stock
    public void decreaseQuantity(int amount) {
        this.quantity -= amount;
    }
    public void increaseQuantity(int amount) {
        this.quantity += amount;
    }
}
