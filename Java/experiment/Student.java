package experiment;

public class Student extends Person {
    private String className;
    private double creditScore;
    private double grade;

    public Student(String ID, String name, String gender, int age, String className, double creditScore) {
        super(ID, name, gender, age);
        this.className = className;
        this.creditScore = creditScore;
    }

    public String getClassName() {
        return className;
    }

    public void setClassName(String className) {
        this.className = className;
    }

    public double getCreditScore() {
        return creditScore;
    }

    public void setCreditScore(double creditScore) {
        this.creditScore = creditScore;
    }

    public void setGrade(double Grade) {
        this.grade = Grade;
    }
}

