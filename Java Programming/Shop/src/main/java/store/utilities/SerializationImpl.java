package main.java.store.service;

import java.io.*;

public class SerializationImpl {
    private static final String directoryPath = "src/main/java/store/data/database/";

    public static void save(Object obj, String fileName) throws IOException {
        if (obj == null) {
            throw new IllegalArgumentException("Object cannot not be null during serialization.");
        }

        if (fileName == null) {
            throw new IllegalArgumentException("File name cannot not be null during serialization.");
        }

        File directory = new File(directoryPath);
        if (!directory.exists()) {
            directory.mkdirs();
        }

        File filePath = new File(directoryPath + fileName);

        if (obj instanceof Serializable) {
            try (FileOutputStream fileOut = new FileOutputStream(filePath);
                 ObjectOutputStream out = new ObjectOutputStream(fileOut)) {
                out.writeObject(obj);
            }
            catch (IOException ex) {
                System.err.println("IO error: " + ex.getMessage());
            }
            System.out.println("Object written to: " + fileName);
        }


    }

    public static Object load(String fileName) throws IOException, ClassNotFoundException {
        try (FileInputStream fileIn = new FileInputStream(fileName);
             ObjectInputStream in = new ObjectInputStream(fileIn)) {
            return (Object) in.readObject();
        }
    }
}
