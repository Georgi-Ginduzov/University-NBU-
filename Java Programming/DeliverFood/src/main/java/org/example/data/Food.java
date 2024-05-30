package org.example.data;

public class Food implements Deliverable{
    private String name;
    private boolean isSpicy;
    private int maxMinutes;
    private FoodType FoodType;

    public Food(String name, boolean isSpicy, int maxMinutes, FoodType foodType) {
        this.name = name;
        this.isSpicy = isSpicy;
        this.maxMinutes = maxMinutes;
        FoodType = foodType;
    }

    public String getName() {
        return name;
    }

    public boolean isSpicy() {
        return isSpicy;
    }

    public org.example.data.FoodType getFoodType() {
        return FoodType;
    }


    @Override
    public String toString() {
        return "Food{" +
                "name='" + name + '\'' +
                ", isSpicy=" + isSpicy +
                ", FoodType=" + FoodType +
                '}';
    }

    @Override
    public int getMaxMinutes() {
        return maxMinutes;
    }
}
