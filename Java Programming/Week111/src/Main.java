import data.Course;
import data.CourseType;
import service.CourseServiceImpl;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Course course1 = new Course(1, "Java", 6, CourseType.REQUIRED);
        Course course2 = new Course(2, "C++", 6, CourseType.REQUIRED);
        Course course3 = new Course(3, "OOP", 3, CourseType.REQUIRED);
        Course course4 = new Course(4, "Java", 3, CourseType.ELECTIVE);
        Course course5 = new Course(5, "Python", 6, CourseType.ELECTIVE);

        CourseServiceImpl courseService = new CourseServiceImpl();

        courseService.addCourseToHashSet(course1);
        courseService.addCourseToHashSet(course2);
        courseService.addCourseToHashSet(course3);
        courseService.addCourseToHashSet(course4);
        courseService.addCourseToHashSet(course5);
        courseService.addCourseToHashSet(course5);

        courseService.printCourseHashSet();

        System.out.println();

        courseService.addCourseToTreeSet(course4);
        courseService.addCourseToTreeSet(course2);
        courseService.addCourseToTreeSet(course5);
        courseService.addCourseToTreeSet(course1);
        courseService.addCourseToTreeSet(course3);

        courseService.printCourseTreeSet();
        System.out.println();


        courseService.putCourseStudentNumberToHashSet(course1, 150);
        courseService.putCourseStudentNumberToHashSet(course1, 200);
        courseService.putCourseStudentNumberToHashSet(course2, 20);
        courseService.putCourseStudentNumberToHashSet(course3, 150);
        courseService.putCourseStudentNumberToHashSet(course4, 200);

        courseService.printCourseTreeSet();


    }
}