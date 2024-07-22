import numpy as np
import matplotlib.pyplot as plt
from scipy import stats

# 定义年龄和身体肥胖数据
age = np.array([23, 23, 27, 27, 39, 41, 47, 49, 50, 52, 54, 54, 56, 57, 58, 58, 60, 61])
fat_percent = np.array([9.5, 26.5, 7.8, 17.8, 31.4, 25.9, 27.4, 27.2, 31.2, 34.6, 42.5, 28.8, 33.4, 30.2, 34.1, 32.9, 41.2, 35.7])

# (a) 计算均值、中位数和标准差
age_mean = np.mean(age)
age_median = np.median(age)
age_std = np.std(age)

fat_mean = np.mean(fat_percent)
fat_median = np.median(fat_percent)
fat_std = np.std(fat_percent)

print("Age: Mean =", age_mean, "Median =", age_median, "Standard Deviation =", age_std)
print("%Fat: Mean =", fat_mean, "Median =", fat_median, "Standard Deviation =", fat_std)

# (b) 绘制盒图
plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
plt.boxplot(age)
plt.title('Age Boxplot')
plt.ylabel('Age')

plt.subplot(1, 2, 2)
plt.boxplot(fat_percent)
plt.title('%Fat Boxplot')
plt.ylabel('%Fat')

plt.show()

# (c) 绘制散点图和q-q图
plt.figure(figsize=(10, 5))

plt.subplot(1, 2, 1)
plt.scatter(age, fat_percent)
plt.title('Scatter Plot')
plt.xlabel('Age')
plt.ylabel('%Fat')

plt.subplot(1, 2, 2)
stats.probplot(age, dist="norm", plot=plt)
plt.title('Q-Q Plot for Age')

plt.tight_layout()
plt.show()
