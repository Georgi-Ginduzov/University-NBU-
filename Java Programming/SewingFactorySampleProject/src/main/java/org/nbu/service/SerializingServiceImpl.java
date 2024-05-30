package org.nbu.service;

import java.io.*;

public class SerializingServiceImpl {
    public <T extends Serializable> void serialize(String filePath, T obj) {
        try(FileOutputStream fos = new FileOutputStream(filePath); ObjectOutputStream oos = new ObjectOutputStream(fos)) {
            oos.writeObject(obj);
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public <T extends Serializable> T deserialize(String filePath) throws IOException, ClassNotFoundException, FileNotFoundException, IOException, ClassNotFoundException {
        try (FileInputStream fileInputStream = new FileInputStream(filePath);
             ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream)) {
            return (T) objectInputStream.readObject();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
}
