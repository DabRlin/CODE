package DANG;

// Student 类继承自 Person
class Student extends Person {
    private String className;
    private double creditPoints;

    // 构造方法
    public Student(String name, String gender, int id, int age, String className, double creditPoints) {
        super(name, gender, id, age);
        this.className = className;
        this.creditPoints = creditPoints;
    }

    // 设置班级
    public void setClassName(String className) {
        this.className = className;
    }

    // 获取班级
    public String getClassName() {
        return className;
    }

    // 设置学分绩
    public void setCreditPoints(double creditPoints) {
        this.creditPoints = creditPoints;
    }

    // 获取学分绩
    public double getCreditPoints() {
        return creditPoints;
    }
}
