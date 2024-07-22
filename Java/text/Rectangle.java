package text;
public class Rectangle {
    private double width;
    private double height;

    // 构造方法
    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    // 计算矩形的面积
    public double calculateArea() {
        return width * height;
    }

    // 计算矩形的周长
    public double calculatePerimeter() {
        return 2 * (width + height);
    }

    public static void main(String[] args) {
        // 创建一个 Rectangle 对象
        Rectangle rectangle = new Rectangle(5.0, 3.0);

        // 计算并打印矩形的面积和周长
        double area = rectangle.calculateArea();
        double perimeter = rectangle.calculatePerimeter();

        System.out.println("矩形的面积为: " + area);
        System.out.println("矩形的周长为: " + perimeter);
    }
}
