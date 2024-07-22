import pandas as pd

# 创建sales_data DataFrame
data = {
    '订单编号': [1001, 1002, 1003, 1004, 1005],
    '日期': ['2023-01-15', '2023-01-16', '2023-01-17', '2023-01-18', '2023-01-19'],
    '产品名称': ['商品A', '商品B', '商品A', '商品C', '商品B'],
    '数量': [10, 5, 8, 12, 7],
    '销售额': [500, 250, 400, 600, 350]
}

sales_data = pd.DataFrame(data)

# 从sales_data中抽取日期在2023-01-16及以后的销售订单数据
recent_sales = sales_data[sales_data['日期'] >= '2023-01-16']
print("最近的销售订单数据:")
print(recent_sales)

# 计算每个产品的销售总额
product_sales = sales_data.groupby('产品名称')['销售额'].sum().reset_index()
print("\n每个产品的销售总额:")
print(product_sales)

# 删除销售额不足300的订单
sales_data = sales_data[sales_data['销售额'] >= 300]

# 添加一笔销售订单
new_order = pd.DataFrame({'订单编号': [1006],
                          '日期': ['2023-01-20'],
                          '产品名称': ['商品A'],
                          '数量': [15],
                          '销售额': [750]})

sales_data = pd.concat([sales_data, new_order], ignore_index=True)

# 根据销售额升序排序
sales_data = sales_data.sort_values(by='销售额')
print("\n按销售额升序排序的销售订单数据:")
print(sales_data)

# 计算平均销售额，最大销售额和最小销售额
average_sales = sales_data['销售额'].mean()
max_sales = sales_data['销售额'].max()
min_sales = sales_data['销售额'].min()

print(f"\n平均销售额: {average_sales}")
print(f"最大销售额: {max_sales}")
print(f"最小销售额: {min_sales}")

# 使用Pandas筛选出销售额大于等于500的订单数据
high_sales_orders = sales_data[sales_data['销售额'] >= 500]
print("\n销售额大于等于500的订单数据:")
print(high_sales_orders)
