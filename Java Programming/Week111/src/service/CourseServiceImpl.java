package service;

import data.Course;
import data.CourseType;

import java.util.*;

public class CourseServiceImpl {
    private Set<Course> courseHashSet;
    private Set<Course> courseTreeSet;

    private Map<Course, Integer> courseStudentNumberHashmap;
    private Map<Course, Integer> courseStudentNumberTreemap;

    private EnumMap<CourseType, Integer> enumMapCourseMinCredits;


    public CourseServiceImpl() {
        courseHashSet = new HashSet<Course>();
        courseTreeSet = new TreeSet<>(comparatopByCourseType().thenComparing(comparatopByCourseId()));

        courseStudentNumberHashmap = new HashMap<>();
        courseStudentNumberTreemap = new TreeMap<>();

        enumMapCourseMinCredits = new EnumMap<>(CourseType.class);
    }

    public boolean addCourseToHashSet(Course course) {
        return this.courseHashSet.add(course);
    }
    public boolean addCourseToTreeSet(Course course) {
        return this.courseTreeSet.add(course);
    }

    public void printCourseHashSet() {
        for (Course course : courseHashSet) {
            System.out.println(course);
        }
    }
    public void printCourseTreeSet() {
        for (Course course : courseTreeSet) {
            System.out.println(course);
        }
    }


    public void putCourseStudentNumberToHashSet(Course course, int studentNumber) {
        this.courseStudentNumberHashmap.put(course, studentNumber);
    }
    public int putCourseTypeMinCredits(CourseType courseType, int minCredits) {
        return this.enumMapCourseMinCredits.put(courseType, minCredits);
    }

    public void printCourseStudentNumberHashMap() {
        /*Set<Map.Entry<Course, Integer>> entrySet = courseStudentNumberHashmap.entrySet();
        for (Map.Entry<Course, Integer> entry : entrySet) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }*/

        this.courseStudentNumberHashmap
                .forEach((course, studentNumber) ->
                {
                    System.out.println(course + " " + studentNumber);
                });
    }

    public Comparator<Course> comparatopByCourseType() {
        return new Comparator<Course>() {
            @Override
            public int compare(Course o1, Course o2) {
                return o1.getCourseType().compareTo(o2.getCourseType());
            }
        };
    }
    public Comparator<Course> comparatopByCourseId() {
        return new Comparator<Course>() {
            @Override
            public int compare(Course o1, Course o2) {
                return Long.compare(o1.getId(), o2.getId());
            }
        };
    }

    public void printByCoursesCredits(List<Course> courses) {
        PriorityQueue<Course> coursePriorityQueue = new PriorityQueue<>(comparatopByCourseId());
        coursePriorityQueue.addAll(courses);
    }

}
