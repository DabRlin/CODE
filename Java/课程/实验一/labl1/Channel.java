package 课程.实验一.labl1;

public class Channel { // 描述要发送的消息通道
	private Message message ; // 消息
	public Channel(String title, String content) {
		this.message = new Message(this, title, content) ;
		this.message.send() ; // 消息发送
	}
	public boolean connect() {	// 通道的连接
		System.out.println("【Channel】建立消息的发送通道...") ;
		return true ;
	}
	public void close() {	// 关闭通道
		System.out.println("【Channel】关闭消息通道...") ;
	}
}

