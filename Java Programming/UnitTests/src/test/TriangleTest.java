package test;

import shapes.Triangle;

import org.junit.jupiter.api.Test;
import shapes.Triangle;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class TriangleTest {
    @Test
    void perimeter(){
        // given
        Triangle triangle = new Triangle(4, 5, 6);

        // when
        int actual = triangle.perimeter();

        // then
        int expected = 12;
        assertEquals(expected, actual);
    }

}
