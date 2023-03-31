import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.pyplot as plt2
from sklearn.metrics import r2_score
from sklearn.metrics import mean_squared_error
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

filename = ("D:\python\pythonProject3\house_data.csv")
boston_data = pd.read_csv(filename)

x = boston_dataMEDV_boston_data = boston_data['MEDV']  # 房价



# 根据散点图判断，'LSTAT', 'CRIM', 'RM'与 'MEDV'关联性更大
new_boston_data = boston_data[['LSTAT', 'CRIM', 'RM', 'MEDV']]  # 获得与房价相关的数据

# 处理房价异常数据
for i in new_boston_data.index:
    if new_boston_data.loc[i, 'MEDV'] > 45:
        new_boston_data = new_boston_data.drop(i)

# print(new_boston_data['MEDV'])

y = np.array((new_boston_data['MEDV']))  # 房价数据
new_boston_df = new_boston_data.drop(["MEDV"], axis=1)
x = np.array(new_boston_df)
# 划分数据，70%用于训练，30%用于测试
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3)

# 线性回归模型
lr = LinearRegression()
lr.fit(x_train, y_train)  # 训练数据
y_predict = lr.predict(x_test)  # 预测

# 与验证值作比较
error = mean_squared_error(y_test, y_predict).round(5)  # 平方差
score = r2_score(y_test, y_predict).round(5)  # 相关系数

print('score : ', score)

# 绘制真实值和预测值的对比图

fig = plt.figure(figsize=(13, 7))
plt.rcParams['font.family'] = "sans-serif"
plt.rcParams['font.sans-serif'] = "SimHei"
plt.rcParams['axes.unicode_minus'] = False  # 绘图
plt.plot(range(y_test.shape[0]), y_test, color='red', linewidth=1, linestyle='-')
plt.plot(range(y_test.shape[0]), y_predict, color='blue', linewidth=1, linestyle='dashdot')
plt.legend(['真实值', '预测值'])
plt.title("190512213", fontsize=20)
error = "标准差d=" + str(error) + "\n" + "相关指数R^2=" + str(score)
plt.xlabel(error, size=18, color="green")
plt.grid()
plt.show()

plt2.rcParams['font.family'] = "sans-serif"
plt2.rcParams['font.sans-serif'] = "SimHei"
plt2.title('190512213', fontsize=24)
xx = np.arange(0, 40)
yy = xx
plt2.xlabel('* truth *', fontsize=14)
plt2.ylabel('* predict *', fontsize=14)
plt2.plot(xx, yy)
plt2.scatter(y_test, y_predict, color='red')
plt2.grid()
plt2.show()
