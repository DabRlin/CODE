import cv2
import os

def extract_frames(video_path, output_folder):
    # 打开视频文件
    cap = cv2.VideoCapture(video_path)

    # 确保视频文件打开成功
    if not cap.isOpened():
        print("Error: 无法打开视频文件.")
        return

    # 确保输出文件夹存在
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    # 获取视频的帧速率
    fps = cap.get(cv2.CAP_PROP_FPS)

    # 循环读取视频帧
    frame_count = 0
    while True:
        ret, frame = cap.read()

        # 如果没有帧可读，退出循环
        if not ret:
            break

        # 保存帧为图像文件
        frame_count += 1
        frame_filename = os.path.join(output_folder, f"frame_{frame_count}.png")
        cv2.imwrite(frame_filename, frame)

    # 释放视频捕捉对象
    cap.release()

    print(f"视频帧抽取完成，共抽取了 {frame_count} 帧.")

# 示例用法
video_path = "C:/Users/dangh/Downloads/1.mp4"
output_folder = "C:/Users/dangh/Downloads/video"
extract_frames(video_path, output_folder)
