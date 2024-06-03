package main.java.store.data;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

public class Receipt {
    private final int serialNumber;
    private final Cashier cashier;
    private final Date dateTime;
    private final List<PurchaseItem> purchaseItems;
    private final double total;

    public Receipt(int serialNumber, Cashier cashier, Date dateTime, List<PurchaseItem> purchaseItems) {
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

    public Cashier getCashier() {
        return cashier;
    }

    public Date getDateTime() {
        return dateTime;
    }

    public List<PurchaseItem> getPurchaseItems() {
        return purchaseItems;
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
            for (PurchaseItem item : purchaseItems) {
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

    private double calculateTotal(){
        double total = 0;
        for (PurchaseItem item : purchaseItems) {
            total += item.getPrice();
        }

        return total;
    }
}
