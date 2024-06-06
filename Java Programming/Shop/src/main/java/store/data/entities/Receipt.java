package main.java.store.data.entities;

import main.java.store.data.interfaces.ItemInCart;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Serializable;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

public final class Receipt implements Serializable {
    private final int serialNumber;
    private final Cashier cashier;
    private final Date dateTime;
    private final List<ItemInCart> purchaseItems;
    private final double total;

    public Receipt(int serialNumber, Cashier cashier, Date dateTime, List<ItemInCart> purchaseItems) {
        this.serialNumber = serialNumber;
        this.cashier = cashier;
        this.dateTime = dateTime;
        this.purchaseItems = purchaseItems;
        this.total = calculateTotal();
        saveToFile();
    }

    public int getSerialNumber() {
        return serialNumber;
    }

    public double getTotal() {
        return total;
    }

    private void saveToFile() {
        String directoryPath = "src/main/java/store/data/receipts/";

        File directory = new File(directoryPath);
        if (!directory.exists()) {
            directory.mkdirs();
        }

        String fileName = directoryPath + "receipt_" + serialNumber + ".txt";

        try (FileWriter writer = new FileWriter(fileName)) {
            writer.write("-------------------------------------------" + "\n");
            writer.write("               STORE RECEIPT                \n");
            writer.write("-------------------------------------------" + "\n");
            writer.write("Receipt Serial Number: " + serialNumber + "\n");
            writer.write("Cashier: " + cashier.getName() + "\n");
            writer.write("Date: " + new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(dateTime) + "\n");
            writer.write("-------------------------------------------" + "\n");
            writer.write(String.format("%-20s %10s %10s\n", "Item", "Quantity", "Price"));
            writer.write("-------------------------------------------" + "\n");
            for (ItemInCart item : purchaseItems) {
                writer.write(String.format("%-20s %10d %10.2f\n", item.getName(), item.getQuantity(), item.getPrice()));
            }
            writer.write("-------------------------------------------" + "\n");
            writer.write(String.format("%-20s %20.2f\n", "Total:", total));
            writer.write("*******************************************" + "\n");
            writer.write("            THANK YOU COME AGAIN           \n");
            writer.write("*******************************************" + "\n");
            writer.write("        CREATED BY: GEORGI GINDUZOV       \n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("-------------------------------------------" + "\n");
        sb.append("               STORE RECEIPT                \n");
        sb.append("-------------------------------------------" + "\n");
        sb.append("Receipt Serial Number: " + serialNumber + "\n");
        sb.append("Cashier: " + cashier.getName() + "\n");
        sb.append("Date: " + new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(dateTime) + "\n");
        sb.append("-------------------------------------------" + "\n");
        sb.append(String.format("%-20s %10s %10s\n", "Item", "Quantity", "Price"));
        sb.append("-------------------------------------------" + "\n");
        for (ItemInCart item : purchaseItems) {
            sb.append(String.format("%-20s %10d %10.2f\n", item.getName(), item.getQuantity(), item.getPrice()));
        }
        sb.append("-------------------------------------------" + "\n");
        sb.append(String.format("%-20s %20.2f\n", "Total:", total));
        sb.append("*******************************************" + "\n");
        sb.append("            THANK YOU COME AGAIN           \n");
        sb.append("*******************************************" + "\n");
        sb.append("        CREATED BY: GEORGI GINDUZOV       \n");

        return sb.toString();
    }

    private double calculateTotal(){
        double total = 0;
        for (ItemInCart item : purchaseItems) {
            total += item.getPrice();
        }

        return total;
    }
}
