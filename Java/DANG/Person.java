package DANG;

// Person 类的定义
class Person {
    private String name;
    private String gender;
    private int id;
    private int age;

    // 构造方法
    public Person(String name, String gender, int id, int age) {
        this.name = name;
        this.gender = gender;
        this.id = id;
        this.age = age;
    }

    // 设置姓名
    public void setName(String name) {
        this.name = name;
    }

    // 获取姓名
    public String getName() {
        return name;
    }

    // 设置性别
    public void setGender(String gender) {
        this.gender = gender;
    }

    // 获取性别
    public String getGender() {
        return gender;
    }

    // 设置 ID
    public void setId(int id) {
        this.id = id;
    }

    // 获取 ID
    public int getId() {
        return id;
    }

    // 设置年龄
    public void setAge(int age) {
        this.age = age;
    }

    // 获取年龄
    public int getAge() {
        return age;
    }
}

