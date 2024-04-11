package university;

public enum CourseType {
    REQUIRED(6), ELECTIVE(3);
    private int minCredits;

    CourseType(int minCredits){
        this.minCredits = minCredits;
    }

    public int getMinCredits() {
        return minCredits;
    }

    public void setMinCredits(int minCredits) {
        this.minCredits = minCredits;
    }
}
