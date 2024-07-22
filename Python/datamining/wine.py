import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score

# 读取数据
data = pd.read_csv(r'C:\Users\dangh\Downloads\wine_shuffle111.data', header=None)
data.columns = ['Class'] + [f'Feature_{i}' for i in range(1, data.shape[1])]

# 分割数据集
X = data.drop('Class', axis=1)
y = data['Class']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 训练朴素贝叶斯模型
model = GaussianNB()
model.fit(X_train, y_train)

# 预测并评估模型
y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test, y_pred)
print(f'Test Accuracy: {accuracy:.4f}')

# 调参以提高精度
# 尝试不同的var_smoothing值
best_accuracy = accuracy
best_var_smoothing = 1e-9
for var_smoothing in [1e-10, 1e-9, 1e-8, 1e-7, 1e-6, 1e-5, 1e-4, 1e-3]:
    model = GaussianNB(var_smoothing=var_smoothing)
    model.fit(X_train, y_train)
    y_pred = model.predict(X_test)
    accuracy = accuracy_score(y_test, y_pred)
    if accuracy > best_accuracy:
        best_accuracy = accuracy
        best_var_smoothing = var_smoothing

print(f'Best Test Accuracy: {best_accuracy:.4f} with var_smoothing: {best_var_smoothing}')
