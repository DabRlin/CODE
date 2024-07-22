package 课程.实验二.test;

import 课程.实验二.labl.Address;
import 课程.实验二.labl.Employee;
import 课程.实验二.labl.User;

public class Main {
    public static void main(String[] args) {
        
        Address address = new Address("China", "Beijing", "Beijing", "Main Street", "100000");
        System.out.println("Full Address: " + address.getFullAddress());

        Employee employee1 = new Employee();
        Employee employee2 = new Employee(11650110);
        Employee employee3 = new Employee(11650110, "陈泓源", 5000.00);
        Employee employee4 = new Employee(11650110, "陈泓源", 6000.00, 0.03); // 3%

        System.out.println("Employee 1 Salary Increase: " + employee1.calculateSalaryIncrease());
        System.out.println("Employee 2 Salary Increase: " + employee2.calculateSalaryIncrease());
        System.out.println("Employee 3 Total Salary: " + employee3.calculateTotalSalary());
        System.out.println("Employee 4 Total Salary: " + employee4.calculateTotalSalary());

        User user1 = new User();
        User user2 = new User("大数据2201陈泓源");
        User user3 = new User("大数据2201陈泓源", "2211650110");

        System.out.println("User 1 Info: " + user1.getUserInfo());
        System.out.println("User 2 Info: " + user2.getUserInfo());
        System.out.println("User 3 Info: " + user3.getUserInfo());

        String inputPassword = "2211650110";
        String inputPassword2 = "passward";
        System.out.println("User 3 Authentication: " + user3.authenticate(inputPassword));
        System.out.println("User 3 Authentication: " + user3.authenticate(inputPassword2));
    }
}

