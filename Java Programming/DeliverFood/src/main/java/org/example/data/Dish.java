package org.example.data;

import java.util.ArrayList;
import java.util.List;

public class Dish implements Deliverable, Eatable{
    private String name;
    private double price;
    private int maxMinutes;
    private List<Eatable> foodList;

    public Dish(String name, double price, int maxMinutes) {
        this.name = name;
        this.price = price;
        this.maxMinutes = maxMinutes;
        this.foodList = new ArrayList<Eatable>();
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public List<Food> getFoodList() {
        return foodList;
    }

    @Override
    public String toString() {
        return "Dish{" +
                "price=" + price +
                ", name='" + name + '\'' +
                '}';
    }

    @Override
    public int getMaxMinutes() {
        return this.maxMinutes  ;
    }
}
