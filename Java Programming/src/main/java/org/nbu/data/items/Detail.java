package org.nbu.data.items;

import org.nbu.data.items.enums.DifficultyLevel;
import org.nbu.data.materials.Material;

public class Detail {
    private String name;
    private Material material;

    private DifficultyLevel difficultyLevel;

    public Detail(String name, Material material, DifficultyLevel difficultyLevel) {
        this.name = name;
        this.material = material;
        this.difficultyLevel = difficultyLevel;
    }

    public String getName() {
        return name;
    }

    public Material getMaterial() {
        return material;
    }

    public DifficultyLevel getDifficultyLevel() {
        return difficultyLevel;
    }

    @Override
    public String toString() {
        return "Detail{" +
                "name='" + name + '\'' +
                ", material=" + material +
                '}';
    }
}
