package main.java.store.data.entities;

import main.java.store.data.interfaces.ItemInCart;

public final class CartItem implements ItemInCart {
    private final int quantity;
    private final double price;
    private final String name;

    public CartItem(int quantity, double price, String name) {
        this.quantity = quantity;
        this.price = price;
        this.name = name;
    }

    @Override
    public int getQuantity() {
        return quantity;
    }

    @Override
    public double getPrice() {
        return price;
    }

    @Override
    public String getName() {
        return name;
    }
}
