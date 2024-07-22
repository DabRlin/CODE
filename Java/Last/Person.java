package Last;

abstract class Person {
    private String ID;
    private String name;
    private String gender;
    private int age;

    public Person(String ID, String name, String gender, int age) {
        this.ID = ID;
        this.name = name;
        this.gender = gender;
        this.age = age;
    }

    // Getters and setters
    public String getID() {
        return ID;
    }

    public void setID(String ID) {
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

    @Override
    public String toString() {
        return "ID: " + ID + ", Name: " + name + ", Gender: " + gender + ", Age: " + age;
    }

}

