package org.nbu.data.materials;

public class Material {
    private String name;

    public Material(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Material{" +
                "name='" + name + '\'' +
                '}';
    }
}
