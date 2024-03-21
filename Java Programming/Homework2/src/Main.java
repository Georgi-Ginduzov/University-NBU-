import manufacturer.Cooker;
import manufacturer.ElectricDevice;
import manufacturer.Manufacturer;
import manufacturer.WashingMachine;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String manufacturerName = input.nextLine();
        int providesLongTermWarranty = input.nextInt();
        int minimalWarranty = input.nextInt();
        int isGas = input.nextInt();
        int isDryer = input.nextInt();

        Manufacturer manufacturer = new Manufacturer(manufacturerName, providesLongTermWarranty);
        ElectricDevice elDevice = new ElectricDevice(manufacturer, minimalWarranty);
        Cooker cooker = new Cooker(manufacturer, minimalWarranty, isGas);
        WashingMachine washingMachine = new WashingMachine(manufacturer, minimalWarranty, isDryer);

        System.out.println(elDevice.warranty());
        System.out.println(cooker.warranty());
        System.out.println(washingMachine.warranty());
    }
}