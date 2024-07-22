import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score
from sklearn.model_selection import GridSearchCV

# 读取训练集和测试集数据
train_data_path = 'C:\\Users\\dangh\\Downloads\\train-iris-knn.csv'
test_data_path = 'C:\\Users\\dangh\\Downloads\\test-iris-knn.csv'

train_data = pd.read_csv(train_data_path)
test_data = pd.read_csv(test_data_path)

# 分离特征和标签
X_train = train_data.drop('species', axis=1)
y_train = train_data['species']
X_test = test_data.drop('species', axis=1)
y_test = test_data['species']

# 训练KNN分类器
knn = KNeighborsClassifier()
knn.fit(X_train, y_train)

# 预测测试集结果
y_pred = knn.predict(X_test)

# 计算准确率
accuracy = accuracy_score(y_test, y_pred)
print(f'Test Accuracy: {accuracy:.4f}')

# 调参以提高精度
param_grid = {
    'n_neighbors': range(1, 20),
    'weights': ['uniform', 'distance'],
    'metric': ['euclidean', 'manhattan', 'minkowski']
}

grid_search = GridSearchCV(KNeighborsClassifier(), param_grid, cv=5, scoring='accuracy')
grid_search.fit(X_train, y_train)

best_knn = grid_search.best_estimator_
best_accuracy = grid_search.best_score_
best_params = grid_search.best_params_

# 在测试集上评估最佳模型
y_best_pred = best_knn.predict(X_test)
best_test_accuracy = accuracy_score(y_test, y_best_pred)

print(f'Best Test Accuracy: {best_test_accuracy:.4f}')
print(f'Best Parameters: {best_params}')
