import pandas as pd
from mlxtend.preprocessing import TransactionEncoder
from mlxtend.frequent_patterns import apriori

trans = [
    ['M', 'O', 'N', 'K', 'E', 'Y'],
    ['D', 'O', 'N', 'K', 'E', 'Y'],
    ['M', 'A', 'K', 'E'],
    ['M', 'U', 'C', 'K', 'Y'],
    ['C', 'O', 'K', 'Y']
]
te = TransactionEncoder()
te_ary = te.fit_transform(trans)
df = pd.DataFrame(te_ary, columns=te.columns_)
print(df, end = "\n\n")
# 使用Apriori算法计算频繁项集
min_sup = 0.6  # 最小支持度阈值
frequent_itemsets = apriori(df, min_support=min_sup, use_colnames=True)
print("频繁项集(Apriori):")
print(frequent_itemsets)
