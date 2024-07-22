package lab;

import java.util.Objects;

public class Student extends person{
    private int classId;
    private double GPA;
    public Student(int id, int age, String name, String gender) {
        this(id, age, name, gender, 0, 0);
    }
    public Student(int id, int age, String name, String gender, int classId, double GPA) {
        super(id, age, name, gender);
        this.classId = classId;
        this.GPA = GPA;
    }

    public Student(int id, String name, int age, double score){
        this(id, age, name, "M", 0, score);
    }

    public int getClassId() {
        return classId;
    }

    public void setClassId(int classId) {
        this.classId = classId;
    }

    public double getGPA() {
        return GPA;
    }

    public void setGPA(double GPA) {
        this.GPA = GPA;
    }

    public boolean isMan(){
        return Objects.equals(gender, "M");
    }

    @Override
    public String toString() {
        return super.toString() +
                ",班级：" + classId +
                ",成绩：" + GPA;
    }
}
