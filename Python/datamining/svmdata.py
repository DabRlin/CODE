import pandas as pd
from sklearn.svm import SVC
from sklearn.model_selection import GridSearchCV
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt

# 加载数据
train_data = pd.read_csv(r'C:\Users\dangh\Downloads\svmdata3.csv')
val_data = pd.read_csv(r'C:\Users\dangh\Downloads\svmdata3val.csv')

# 数据拆分为特征和标签
X_train = train_data.iloc[:, :-1]
y_train = train_data.iloc[:, -1]
X_val = val_data.iloc[:, :-1]
y_val = val_data.iloc[:, -1]

# 定义参数网格
param_grid = {
    'C': [0.1, 1, 10, 100],
    'gamma': [1, 0.1, 0.01, 0.001],
    'kernel': ['linear', 'rbf']
}

# 实例化SVM模型
svm = SVC()

# 使用GridSearchCV来搜索最佳参数
grid_search = GridSearchCV(svm, param_grid, refit=True, verbose=2, cv=5)
grid_search.fit(X_train, y_train)

# 打印最佳参数
print("Best Parameters:", grid_search.best_params_)

# 使用最佳参数训练模型
best_svm = grid_search.best_estimator_

# 在验证集上进行预测
y_pred = best_svm.predict(X_val)

# 计算精度
accuracy = accuracy_score(y_val, y_pred)
print("Validation Accuracy:", accuracy)

# 可视化预测结果
plt.figure(figsize=(10, 6))
plt.scatter(X_val.iloc[:, 0], X_val.iloc[:, 1], c=y_pred, cmap='viridis', marker='o', label='Predicted Labels')
plt.scatter(X_val.iloc[:, 0], X_val.iloc[:, 1], c=y_val, cmap='coolwarm', marker='x', label='True Labels')

plt.xlabel('Feature 1')
plt.ylabel('Feature 2')
plt.legend()
plt.title('SVM Predictions vs True Labels on Validation Data')
plt.show()
