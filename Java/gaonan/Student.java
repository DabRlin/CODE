package gaonan;
public class Student extends Person {
    private String className;
    private double gpa;

    public Student(int id, String name, String gender, int age, String className, double gpa) {
        super(id, name, gender, age);
        this.className = className;
        this.gpa = gpa;
    }

    // Getters and Setters
    public String getClassName() {
        return className;
    }

    public double getGpa() {
        return gpa;
    }

    // Additional setters
    public void setClassName(String className) {
        this.className = className;
    }

    public void setGpa(double gpa) {
        this.gpa = gpa;
    }

    @Override
    public void setName(String name) {
        super.setName(name);
    }

    @Override
    public void setGender(String gender) {
        super.setGender(gender);
    }

    @Override
    public void setAge(int age) {
        super.setAge(age);
    }
}
