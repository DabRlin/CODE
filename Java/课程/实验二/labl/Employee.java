package 课程.实验二.labl;

public class Employee {
    private int employeeId;
    private String name;
    private double basicSalary;
    private double salaryIncreaseRate;

    public Employee() {
        this.employeeId = 1000;
        this.name = "无名氏";
    }
      public Employee(int employeeId) {
        this.employeeId = employeeId;
        this.name = "无名氏";
        this.basicSalary = 3000;
        this.salaryIncreaseRate = 0.01;
    }

    public Employee(int employeeId, String name,double basicSalary) {
        this.employeeId = employeeId;
        this.name = name;
        this.basicSalary = basicSalary;
        this.salaryIncreaseRate = 0.05; 
    }

    public Employee(int employeeId, String name, double basicSalary, double salaryIncreaseRate) {
        this.employeeId = employeeId;
        this.name = name;
        this.basicSalary = basicSalary;
        this.salaryIncreaseRate = salaryIncreaseRate;
    }

    public double calculateSalaryIncrease() {
        return basicSalary * salaryIncreaseRate;
    }

    public double calculateTotalSalary() {
        return basicSalary + calculateSalaryIncrease();
    }
}
