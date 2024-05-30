package util;

import Files.BoxWithWeight;

import java.io.*;

public class SerializationBoxes {
    public static void serializeBox(String filePath, BoxWithWeight boxWithWeight){
        try (FileOutputStream fileOutputStream = new FileOutputStream(filePath);
             ObjectOutputStream objectOutputStream = new ObjectOutputStream(fileOutputStream);){
            objectOutputStream.writeObject(boxWithWeight);
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static BoxWithWeight deserializeBox(String filePath) throws ClassNotFoundException, IOException{
        try (FileInputStream fileInputStream = new FileInputStream(filePath);
        ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream){
        //return (BoxWithWeight) objectInputStream.readObject();


        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
}
