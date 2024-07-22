import pandas as pd

file_path = 'data.xlsx'
df = pd.read_excel(file_path)

chinese_mean = df['语文成绩'].mean()
print(f'1. 语文成绩的平均分是：{chinese_mean:.2f}')

math_max = df['数学成绩'].max()
print(f'2. 数学成绩的最高分是：{math_max}')

english_min = df['英语成绩'].min()
print(f'3. 英语成绩的最低分是：{english_min}')

beijing_students = df[df['出生地'] == '北京']
num_beijing_students = len(beijing_students)
print(f'4. 有{num_beijing_students}位学生来自北京')

num_students_above_20 = len(df[df['年龄'] >= 20])
print(f'5. 有{num_students_above_20}位学生的年龄大于等于20岁')

math_std = df['数学成绩'].std()
print(f'6. 数学成绩的标准差是：{math_std:.2f}')

chinese_median = df['语文成绩'].median()
print(f'7. 语文成绩的中位数是：{chinese_median}')

highest_english_score_student = df[df['英语成绩'] == df['英语成绩'].max()]['学生姓名'].values[0]
print(f'8. 英语成绩最高的学生是：{highest_english_score_student}')

unique_birthplaces = df['出生地'].unique()
print(f'9. 学生的出生地有以下不同取值：{", ".join(unique_birthplaces)}')

math_mean = df['数学成绩'].mean()
print(f'10. 数学成绩的平均值是：{math_mean:.2f},数学成绩的标准差是：{math_std:.2f}')