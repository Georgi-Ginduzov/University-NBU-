import delivery.Deliverable;
import delivery.Document;
import delivery.WeightedItem;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String nameOfMaterial = input.nextLine();
        int fragility = input.nextInt();
        int deliverToAddress = input.nextInt();
        int minimalPrice = input.nextInt();
        int weight = input.nextInt();
        double pricePerKilogram = input.nextDouble();
        int additionalPrice = input.nextInt();

        Deliverable document = new Document(minimalPrice, additionalPrice);
        System.out.println(document.deliveryPrice());

        Deliverable weightedItem = new WeightedItem(nameOfMaterial, fragility, weight, pricePerKilogram);
        System.out.println(weightedItem.deliveryPrice());
    }
}