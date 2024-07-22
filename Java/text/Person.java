package text;

public class Person {
    // 属性
    private String name;
    private int age;

    // 构造方法
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // 打印详细信息的方法
    public void printInfo() {
        System.out.println("姓名: " + name);
        System.out.println("年龄: " + age);
    }

    public static void main(String[] args) {
        // 创建一个 Person 对象并设置属性
        Person person = new Person("John", 30);

        // 调用打印信息方法
        person.printInfo();
    }
}
