package main.java.store.data.observer;

import main.java.store.data.interfaces.Client;
import main.java.store.data.interfaces.Good;
import main.java.store.data.interfaces.ItemInCart;

import java.io.Serializable;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class InventoryManager implements Serializable {
    private Set<Client> observers;
    private Set<Good> products;
    private Set<ItemInCart> cart;

    public InventoryManager() {
        observers = new HashSet<>();
        products = new HashSet<>();
    }

    public void addObserver(Client observer) {
        observers.add(observer);
    }

    public void removeObserver(Observer observer) {
        observers.remove(observer);
    }

    public void notifyObservers(String message) {
        for (Observer observer : observers) {
            observer.update(message);
        }
    }

    public void addProductInStockroom(Good good) {
        products.add(good);

        for (Good item : products) {
            Good itemFromInventory = findGoodByName(item.getName());

            if(itemFromInventory != null) {
                int itemQuantity = item.getQuantity();
                itemFromInventory.increaseQuantity(itemQuantity);
            }
            else {
                addProductInStockroom(item);
            }
        }
        notifyObservers("Product added: " + good.getName());
    }

    public void addProductToCart(ItemInCart item) {
        cart.add(item);
    }

    public void removeProductFromCart(ItemInCart item) {
        cart.remove(item);
    }

    public Good findGoodByName(String name) {
        for (Good product : getProducts()) {
            if (product.getName().equals(name)) {
                return product;
            }
        }

        return null;
    }

    public void removeProductFromStockroom(Good good) {
        products.remove(good);
        notifyObservers("Product removed: " + good.getName());
    }

    public Set<Good> getProducts() {
        return products;
    }

    public Set<ItemInCart> getCart() {
        return cart;
    }

    public Set<Client> getObservers() {
        return observers ;
    }
}
