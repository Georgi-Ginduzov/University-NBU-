package university;

import java.util.ArrayList;
import java.util.List;

public class Program {
    private String name;
    private ProgramType programType;
    private List<Course> courses;
    private List<Student> students;

    public Program(String name, ProgramType programType) {
        this.name = name;
        this.programType = programType;
        this.courses = new ArrayList<>();
        this.students = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public ProgramType getProgramType() {
        return programType;
    }

    public List<Course> getCourses() {
        return courses;
    }

    public boolean addCOurse(Course course){
        if (!this.courses.contains(course))
            return this.courses.add(course);
        return false;
    }
    public boolean removeCourse(Course course){
        return this.courses.remove(course);
    }

    public void printCoursesByType(CourseType courseType){
        for (Course course : this.courses){
            if (course.getCourseType().equals(courseType))
                System.out.println(course);
        }
    }

    @Override
    public String toString() {
        return "Program{" +
                "name='" + name + '\'' +
                ", programType=" + programType +
                '}';
    }
}
