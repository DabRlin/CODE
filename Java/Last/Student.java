package Last;

class Student extends Person {
    private String className;
    private double GPA;

    public Student(String ID, String name, String gender, int age, String className, double GPA) {
        super(ID, name, gender, age);
        this.className = className;
        this.GPA = GPA;
    }

    public String getClassName() {
        return className;
    }

    public void setClassName(String className) {
        this.className = className;
    }

    public double getGPA() {
        return GPA;
    }

    public void setGPA(double GPA) {
        this.GPA = GPA;
    }

    @Override
    public String toString() {
        return super.toString() + ", Class: " + className + ", GPA: " + GPA;
    }

}
