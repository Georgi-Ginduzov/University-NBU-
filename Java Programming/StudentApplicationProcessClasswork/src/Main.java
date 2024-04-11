import university.Course;
import university.CourseType;
import university.Program;
import university.ProgramType;

public class Main {
    public static void main(String[] args) {
        Course course1 = new Course("CITB408", 1, 6, CourseType.REQUIRED);
        Course course2 = new Course("CITB525", 2, 3, CourseType.REQUIRED);
        Course course3 = new Course("CITB869", 3, 3, CourseType.REQUIRED);
        Course course4 = new Course("CITB112", 4, 6, CourseType.ELECTIVE);

        System.out.println(course1);
        System.out.println(course2);
        System.out.println(course3);
        System.out.println(course4);

        System.out.println(CourseType.REQUIRED.getMinCredits());
        System.out.println(CourseType.ELECTIVE.getMinCredits());
        CourseType.REQUIRED.setMinCredits(9);
        System.out.println(CourseType.REQUIRED.getMinCredits());

        Program program = new Program("Informatics", ProgramType.MAJOR);
        System.out.println(program);
        program.addCOurse(course1);
        program.addCOurse(course1);
        program.addCOurse(course2);
        program.addCOurse(course3);
        program.printCoursesByType(CourseType.REQUIRED);
    }
}