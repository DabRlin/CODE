package 实验4;

// Person 类，包含基本的学生信息
public abstract class Person {
    private int ID;
    private String name;
    private String gender;
    private int age;

    // 构造函数

    // Getter 和 Setter 方法
    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    // toString() 方法，用于打印对象信息
    @Override
    public String toString() {
        return "ID: " + ID + ", Name: " + name + ", Gender: " + gender + ", Age: " + age;
    }
    
    // 其他可能需要的方法和属性
    // 比如，你可以在这里添加一些通用的方法，或者其他你认为在 Person 类中应该有的方法
}
