package main.java.store.data.observer;

import main.java.store.data.interfaces.Good;

import java.util.HashSet;
import java.util.Set;

public class InventoryManager{
    private Set<Observer> observers;
    private Set<Good> products;

    public InventoryManager() {
        observers = new HashSet<>();
        products = new HashSet<>();
    }

    public void addObserver(Observer observer) {
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

    public void addProduct(Good good) {
        products.add(good);

        for (Good item : products) {
            Good itemFromInventory = findGoodByName(item.getName());

            if(itemFromInventory != null) {
                int itemQuantity = item.getQuantity();
                itemFromInventory.increaseQuantity(itemQuantity);
            }
            else {
                addProduct(item);
            }
        }
        notifyObservers("Product added: " + good.getName());
    }

    public Good findGoodByName(String name) {
        for (Good product : getProducts()) {
            if (product.getName().equals(name)) {
                return product;
            }
        }

        return null;
    }

    public void removeProduct(Good good) {
        products.remove(good);
        notifyObservers("Product removed: " + good.getName());
    }

    public Set<Good> getProducts() {
        return products;
    }
}
