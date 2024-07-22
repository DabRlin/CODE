import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score
from sklearn import tree
import matplotlib.pyplot as plt

# 读取训练集和测试集数据
train_data = pd.read_csv(r'C:\Users\dangh\Downloads\train-iris-knn.csv')
test_data = pd.read_csv(r'C:\Users\dangh\Downloads\test-iris-knn.csv')

# 分离特征和标签
X_train = train_data.drop('species', axis=1)
y_train = train_data['species']
X_test = test_data.drop('species', axis=1)
y_test = test_data['species']

# 训练决策树分类器
clf = DecisionTreeClassifier(random_state=42)
clf.fit(X_train, y_train)

# 预测测试集结果
y_pred = clf.predict(X_test)

# 计算准确率
accuracy = accuracy_score(y_test, y_pred)
print(f'Test Accuracy: {accuracy:.4f}')

# 可视化决策树
plt.figure(figsize=(20,10))
tree.plot_tree(clf, filled=True, feature_names=X_train.columns, class_names=clf.classes_)
plt.show()
