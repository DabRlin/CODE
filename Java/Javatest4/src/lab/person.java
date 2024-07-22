package lab;

public abstract class person {
    private int id, age;
    private String name;
    String gender;

    public person(int id, int age, String name, String gender) {
        this.id = id;
        this.age = age;
        this.name = name;
        this.gender = gender;
    }

    public person(int id, int age, String name) {
        this(id, age, name, "M");
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
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

    @Override
    public String toString() {
        return  "学号：" + id +
                ", 姓名：'" + name + '\'' +
                ", 年龄：" + age +
                ", 性别：'" + gender + '\'';
    }
}
