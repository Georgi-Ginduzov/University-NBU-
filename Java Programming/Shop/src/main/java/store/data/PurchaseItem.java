package main.java.store.service;

public class PurchaseItem {
    private final int quantity;
    private final double price;
    private final String name;

    public PurchaseItem(int quantity, double price, String name) {
        this.quantity = quantity;
        this.price = price;
        this.name = name;
    }

    public int getQuantity() {
        return quantity;
    }

    public double getPrice() {
        return price;
    }

    public String getName() {
        return name;
    }
}
