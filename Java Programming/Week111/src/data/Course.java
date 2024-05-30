package data;

import java.util.Objects;

public class Course implements Comparable<Course> {
    private int id;
    private String name;
    private int numberOfCredits;
    private CourseType courseType;

    public Course(int id, String name, int numberOfCredits, CourseType courseType) {
        this.id = id;
        this.name = name;
        this.numberOfCredits = numberOfCredits;
        this.courseType = courseType;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public int getNumberOfCredits() {
        return numberOfCredits;
    }

    public CourseType getCourseType() {
        return courseType;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Course course = (Course) o;
        return id == course.id && numberOfCredits == course.numberOfCredits && Objects.equals(name, course.name) && courseType == course.courseType;
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, name, numberOfCredits, courseType);
    }

    @Override
    public String toString() {
        return "Course{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", numberOfCredits=" + numberOfCredits +
                ", courseType=" + courseType +
                '}';
    }

    @Override
    public int compareTo(Course o) {
        return Long.compare(this.id, o.id);
    }
}
