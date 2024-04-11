package shapes;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class StageTrianglesTest {
    List<Triangle> triangles;
    StageTriangles stageTriangles;

    @BeforeEach
    void init(){
        Triangle triangle1 = new Triangle(4, 5, 6);
        Triangle triangle2 = new Triangle(2, 2, 3);
        Triangle triangle3 = new Triangle(4, 5, 6);

        StageTriangles stageTriangles = new StageTriangles();
        stageTriangles.addTriangle(triangle1);
        stageTriangles.addTriangle(triangle2);
        stageTriangles.addTriangle(triangle3);
    }


    @Test
    void addTriangle() {

    }

    @Test
    void totalPerimeter() {
        Triangle triangle1 = new Triangle(4, 5, 6);
        Triangle triangle2 = new Triangle(2, 2, 3);
        Triangle triangle3 = new Triangle(4, 5, 6);

        StageTriangles stageTriangles = new StageTriangles();
        stageTriangles.addTriangle(triangle1);
        stageTriangles.addTriangle(triangle2);
        stageTriangles.addTriangle(triangle3);

        assertEquals(10, stageTriangles.totalPerimeter());
    }

    @Test
    void TrianglesWithPerimeterGreaterThan() {
        List<Triangle> actual = stageTriangles.TrianglesWithPerimeterGreaterThan(8);
        Triangle triangle1 = new Triangle(4, 5, 6);
        Triangle triangle2 = new Triangle(4, 5, 6);

        List<Triangle> expected = new ArrayList<>();
        expected.add(triangle1);
        expected.add(triangle2);

        assertIterableEquals(expected, actual);
    }
}