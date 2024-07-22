import numpy as np

# 定义两个被元组表示的对象
obj1 = np.array([22, 1, 42, 10])
obj2 = np.array([20, 0, 36, 8])

# (a) 计算欧几里得距离
euclidean_dist = np.linalg.norm(obj1 - obj2)

# (b) 计算曼哈顿距离
manhattan_dist = np.sum(np.abs(obj1 - obj2))

# (c) 使用q=3 计算闵可夫斯基距离
minkowski_dist = np.linalg.norm(obj1 - obj2, ord=3)

print("欧几里得距离:", euclidean_dist)
print("曼哈顿距离:", manhattan_dist)
print("闵可夫斯基距离 (q=3):", minkowski_dist)
