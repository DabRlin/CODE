package 课程.实验二.labl;

public class User {
    private String username;
    private String password;

    public User() {
        this.username = "";
        this.password = "";
    }

    public User(String username) {
        this.username = username;
        this.password = "";
    }

    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }

    public String getUsername() {
        return username;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getUserInfo() {
        return "Username: " + username + ", Password: " + password;
    }

    public boolean authenticate(String inputPassword) {
        return this.password.equals(inputPassword);
    }
}