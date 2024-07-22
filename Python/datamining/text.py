import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# 加载数据
data = {
    '地区': ['北京', '辽宁', '上海', '江西', '河南', '贵州', '陕西'],
    '人均GDP': [22460, 11226, 34547, 4851, 5444, 2662, 4549],
    '人均消费水平': [7326, 4490, 11546, 2396, 2208, 1608, 2035]
}

df = pd.DataFrame(data)

# 绘制散点图
plt.figure(figsize=(8, 6))
plt.scatter(df['人均GDP'], df['人均消费水平'], color='blue')
plt.title('Scatter Plot of GDP per Capita vs. Consumption per Capita')
plt.xlabel('GDP per Capita (元)')
plt.ylabel('Consumption per Capita (元)')
plt.grid(True)
plt.show()

# 计算相关系数
correlation = np.corrcoef(df['人均GDP'], df['人均消费水平'])[0, 1]
print("相关系数:", correlation)

# 进行线性回归分析
X = df['人均GDP'].values.reshape(-1, 1)
y = df['人均消费水平'].values

model = LinearRegression()
model.fit(X, y)

# 估计的回归方程
intercept = model.intercept_
slope = model.coef_[0]
print("截距:", intercept)
print("斜率:", slope)

# 解释回归系数的实际意义
print("每增加一单位的人均GDP，人均消费水平增加约", slope, "元.")

# 预测人均消费水平
new_GDP = 5000
predicted_consumption = model.predict([[new_GDP]])[0]
print("预测人均消费水平为5000元的地区:", predicted_consumption, "元.")
