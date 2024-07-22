// package 课程.实验三;

// class Book {
// 	private String title ;
// 	private String author ;
// 	private double price ;
// 	public Book(String title, String author, double price) {
// 		this.title = title ;
// 		this.author = author ;
// 		this.price = price ;
// 	}
// 	public String getInfo() {
// 		return "图书名称：" + this.title + "、图书作者：" + this.author + "、图书价格：" + this.price ;
// 	}
// }
// public class YootkDemo1 { // 李兴华编程训练营：edu.yootk.com
// 	public static void main(String args[]) {
// 		// 动态初始化的对象数组所有元素的内容全部为null
// 		Book [] books = new Book[3] ; // 开辟3个长度的对象数组
// 		books[0] = new Book("Java从入门到项目实战", "李兴华", 99.8) ; // 对象实例化
// 		books[1] = new Book("Python从入门到项目实战", "李兴华", 99.8) ; // 对象实例化
// 		books[2] = new Book("GO从入门到项目实战", "李兴华", 99.8) ; // 对象实例化
// 		for (Book book : books) {
// 			System.out.println(book.getInfo()) ;
// 		}
// 	}
// }