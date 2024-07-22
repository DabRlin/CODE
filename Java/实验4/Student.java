package 实验4;

// Student 类，继承自 Person 类，包含学生特有的信息
public class Student extends Person {
    private String className;
    private double creditScore;

    // 构造函数

    public Student(int id, String name, String string, int age, String className2, double creditScore2) {
    }

    // Getter 和 Setter 方法
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

    // 重写 toString() 方法，用于打印学生对象信息
    @Override
    public String toString() {
        return super.toString() + ", Class: " + className + ", Credit Score: " + creditScore;
    }

    // 其他可能需要的方法和属性
    // 比如，你可以在这里添加一些特定于学生的方法，或者其他你认为在 Student 类中应该有的方法
}
