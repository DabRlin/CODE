package gaonan;
public abstract class Person {
    private int id;
    private String name;
    private String gender;
    private int age;

    public Person(int id, String name, String gender, int age) {
        this.id = id;
        this.name = name;
        this.gender = gender;
        this.age = age;
    }

    // Getters and Setters
    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getGender() {
        return gender;
    }

    public int getAge() {
        return age;
    }

    // Additional setters for Person attributes
    public void setName(String name) {
    }

    public void setGender(String gender) {
    }

    public void setAge(int age) {
    }
}
