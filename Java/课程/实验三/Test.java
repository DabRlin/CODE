package 课程.实验三;

// 抽象类 Person
abstract class Person {
    protected String name;
    protected int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public abstract void work();

    public void show() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

// 学生类
class Student extends Person {
    private String school;

    public Student(String name, int age, String school) {
        super(name, age);
        this.school = school;
    }

    @Override
    public void work() {
        System.out.println("I'm a student at " + school + ". I'm studying.2211650110陈泓源");
    }

    @Override
    public void show() {
        super.show();
        System.out.println("School: " + school);
    }

    public void gotoClassroom() {
    }
}

// 抽象类 Employee
abstract class Employee extends Person {
    protected double salary;

    public Employee(String name, int age, double salary) {
        super(name, age);
        this.salary = salary;
    }

    public abstract double getSalary();
}

// 老师类
class Teacher extends Employee {
    public Teacher(String name, int age, double salary) {
        super(name, age, salary);
    }

    @Override
    public double getSalary() {
        return salary;
    }

    @Override
    public void work() {
        System.out.println("I'm a teacher. I'm teaching in the classroom.2211650110陈泓源");
    }

    public void gotoClassroom() {
    }
}

// 软件工程师类
class SoftwareEngineer extends Employee {
    public SoftwareEngineer(String name, int age, double salary) {
        super(name, age, salary);
    }

    @Override
    public double getSalary() {
        return salary;
    }

    @Override
    public void work() {
        System.out.println("I'm a software engineer. I'm writing code.2211650110陈泓源");
    }
}

// 接口 ICampus
interface ICampus {
    void gotoClassroom();
}

// 测试类
public class Test {
    public static void main(String[] args) {
        // 模拟教师和学生
        Teacher teacher = new Teacher("John", 35, 50000);
        Student[] students = new Student[30];
        for (int i = 0; i < students.length; i++) {
            students[i] = new Student("Student " + (i + 1), 20, "Example School");
        }

        // 模拟上课情况
        teacher.work();
        teacher.gotoClassroom();

        for (Student student : students) {
            student.work();
            student.gotoClassroom();
        }
    }
}
