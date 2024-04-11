import Files.BoxWithWeight;
import exceptions.IllegalIncreaseValueException;
import informatics.Box;
import util.SerializationBoxes;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class Main {
    public static void main(String[] args) {
        Box box = new Box(2, 3, 4);
        System.out.println(box  );

        String filePath = "BoxWithWeight.ser";

        BoxWithWeight boxWithWeight = new BoxWithWeight(1, 2, 3, 5);

        SerializationBoxes.serializeBox(filePath, boxWithWeight);

        try {
            box.increaseDimentions(2);
        } catch (IllegalIncreaseValueException e) {
            throw new RuntimeException(e);
        }
        System.out.println(box);

        try {
            box.increaseDimentions(-10);
        } catch (IllegalIncreaseValueException e) {
            System.out.println(e.getMessage());
        }
        System.out.println(box);
    }
}