import matplotlib.pyplot as plt
import numpy as np

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False 

x = np.arange(0, 2 * np.pi, 0.01)
y = np.sin(x)

plt.plot(x, y, label='sin(x) 曲线', color='b')
plt.xlabel('X轴')
plt.ylabel('Y轴')
plt.title('Sin 函数图表')
plt.legend()
plt.grid(True)

plt.show()
