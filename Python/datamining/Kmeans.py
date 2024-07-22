import pandas as pd
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.metrics import silhouette_score

# 读取数据
data = pd.read_csv("C:/Users/dangh/Downloads/ex7data2.csv")

# 显示前几行数据
data.head()

# 使用肘部法则确定最佳K值
sse = []
k_values = range(1, 11)

for k in k_values:
    kmeans = KMeans(n_clusters=k, random_state=0).fit(data)
    sse.append(kmeans.inertia_)

# 画肘部法则图
plt.figure(figsize=(8, 5))
plt.plot(k_values, sse, marker='o')
plt.xlabel('Number of clusters')
plt.ylabel('SSE')
plt.title('Elbow Method for Determining Optimal k')
plt.show()
# 选择最佳K值
optimal_k = 3

# 对数据进行KMeans聚类
kmeans = KMeans(n_clusters=optimal_k, random_state=0).fit(data)
data['cluster'] = kmeans.labels_

# 可视化聚类结果
plt.figure(figsize=(8, 5))
colors = ['r', 'g', 'b', 'y', 'c', 'm']

for i in range(optimal_k):
    cluster_data = data[data['cluster'] == i]
    plt.scatter(cluster_data['X1'], cluster_data['X2'], label=f'Cluster {i+1}', c=colors[i])

plt.xlabel('X1')
plt.ylabel('X2')
plt.legend()
plt.title('KMeans Clustering Results')
plt.show()
