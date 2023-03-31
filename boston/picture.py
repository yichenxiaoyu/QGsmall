import numpy as np
import matplotlib
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.pyplot import MultipleLocator


filename = ("D:\\python\\pythonProject3\\house_data.csv")
boston_data = pd.read_csv(filename)

# 各个特征和MEDV房价的散点图

boston_df_xTitle = ['CRIM', 'ZN', 'INDUS', 'CHAS', 'NOX', 'RM', 'AGE', 'DIS', 'RAD', 'TAX', 'PTRATIO', 'B', 'LSTAT']




MEDV_boston_data = boston_data['MEDV']  # 房价

# 获取房价的数据
y = np.array(MEDV_boston_data)
# 去除房价的数据
x = boston_data.drop(["MEDV"], axis=1)
plt.xlabel("x -- DATA")
plt.ylabel("y -- MEDV")
# 画各个数据与房价的散点图
for i in range(0, len(boston_df_xTitle)):
    plt.scatter(x[str(boston_df_xTitle[i])], y, s=5)
plt.show()

# 画各个数据与房价的散点图
for i in range(0, len(boston_df_xTitle)):
    plt.figure(facecolor='white')

    plt.scatter(boston_data[str(boston_df_xTitle[i])], boston_data['MEDV'], s=30, edgecolor='white')

    plt.title(str(boston_df_xTitle[i]) + '--------MEDV')

    plt.xlabel(str(boston_df_xTitle[i]))

    plt.ylabel('MEDV')

    plt.show()


# plt.figure(figsize=(20, 15))
# y_major_locator = MultipleLocator(5)
# ax = plt.gca()
# ax.yaxis.set_major_locator(y_major_locator)
# plt.ylim(0, 51)
# plt.grid()
# for i in range(len(MEDV_boston_data)):
#     plt.scatter(i, MEDV_boston_data[i], s=20)
# plt.show()

# # 根据散点图判断，'LSTAT', 'CRIM', 'RM'与 'MEDV'关联性更大
# new_boston_df = boston_data[['LSTAT', 'CRIM', 'RM', 'MEDV']]
# # print(new_boston_df.describe())
#
#
# # 获得目标值 MEDV
# y = np.array((new_boston_df['MEDV']))
# # 从数据去除MEDV
# new_boston_df = new_boston_df.drop(["MEDV"], axis=1)
#
# # 获得特征值
# X = np.array(new_boston_df)
# # print(new_boston_df)
# # print('X :', X, '\n\n')
#
# # 划分数据，70%用于训练，30%用于测试
# X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3)
# # print(X_train.shape, X_test.shape, y_train.shape, y_test.shape)  # 行和列的大小
#
#
# # 线性回归
# lr = LinearRegression()
# lr.fit(X_train, y_train)  # 将训练数据放入，进行参数估计
# # 输出线性回归的系数
# # print('线性回归的系数为：\n w=%s\n b=%s ' % (lr.coef_, lr.intercept_))
# lr_ref_pre = lr.predict(X_test)
#
# # 使用测试数据进行回归预测
# y_test_pred = lr.predict(X_test)
# print('y_test_pred: ', y_test_pred)
#
# # 训练数据的预测值
# y_train_pred = lr.predict(X_train)
# print('y_train_pred: ', y_train_pred)
#
# # 绝对误差
# train_MAE = mean_absolute_error(y_train, y_train_pred)
# print('MAE为：', train_MAE)
#
# # 均方误差
# train_MSE = mean_squared_error(y_train, y_train_pred)
# print('MSE为：', train_MSE)
