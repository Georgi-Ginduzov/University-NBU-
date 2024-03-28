package university;

public class Course {
    private String name;
    private long id;
    private int credits;
    private CourseType courseType;

    public Course(String name, long id, int credits, CourseType courseType) {
        this.name = name;
        this.id = id;
        this.credits = credits;
        this.courseType = courseType;
    }

    public String getName() {
        return name;
    }

    public long getId() {
        return id;
    }

    public int getCredits() {
        return credits;
    }

    public CourseType getCourseType() {
        return courseType;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setId(long id) {
        this.id = id;
    }

    public void setCredits(int credits) {
        if(credits < this.courseType.getMinCredits()){
            this.credits = this.courseType.getMinCredits();
        }
        else {
            this.credits = credits;
        }
    }

    public void setCourseType(CourseType courseType) {
        this.courseType = courseType;
    }

    @Override
    public String toString() {
        return "Course{" +
                "name='" + name + '\'' +
                ", id=" + id +
                ", credits=" + credits +
                ", courseType=" + courseType +
                '}';
    }
}
