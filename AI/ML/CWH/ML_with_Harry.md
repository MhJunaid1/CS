Video # 3 https://www.youtube.com/watch?v=6pUkiLnpYC4&list=PLu0W_9lII9ai6fAMHp-acBmJONT7Y4BSG&index=3&pp=iAQB
What Are Features And Labels In ML? 
In machine learning (ML), **features** and **labels** are two fundamental concepts:

1. **Features**: These are the input variables or independent variables that the machine learning model uses to make predictions. Features are the characteristics or attributes of the data that are used to inform the model. In a dataset, features are often represented as columns. For example, in a dataset predicting house prices, features could include the size of the house, the number of bedrooms, the location, etc.

2. **Labels**: These are the output variables or dependent variables that the model is trying to predict. Labels are the known outcomes in supervised learning and are used to train the model. In the house price prediction example, the label would be the actual price of the house.

In summary:
- **Features** are the inputs to the model.
- **Labels** are the outputs the model aims to predict.


Linear Regression using Python

import matplotlib.pyplot as plt
import numpy as np
from sklearn import datasets, linear_model
from sklearn.metrics import  mean_squared_error

diabetes = datasets.load_diabetes()

diabetes_X = diabetes.data

diabetes_X_train = diabetes_X[:-30]
diabetes_X_test = diabetes_X[-30:]

diabetes_y_train = diabetes.target[:-30]
diabetes_y_test = diabetes.target[-30:]

model = linear_model.LinearRegression()

model.fit(diabetes_X_train, diabetes_y_train)

diabetes_y_predicted = model.predict(diabetes_X_test)

print("Mean squared error is: ", mean_squared_error(diabetes_y_test, diabetes_y_predicted))

print("Weights: ", model.coef_)
print("Intercept: ", model.intercept_)

# plt.scatter(diabetes_X_test, diabetes_y_test)
# plt.plot(diabetes_X_test, diabetes_y_predicted)
#
# plt.show()

# Mean squared error is:  3035.0601152912695
# Weights:  [941.43097333]
# Intercept:  153.39713623331698



Multiple Regression Model
Loss Function and Gradient Descent
Mini Batch and Stockchastic Gradient Descent


Supervised Learning
Classification
Knearest Neighbor Classification

# Loading required modules
from sklearn import datasets
from sklearn.neighbors import KNeighborsClassifier

# Loading Dataset
iris  = datasets.load_iris()

# Printing features and labels
features = iris.data
labels = iris.target
# print(iris.DESCR)

# print(features[0],labels[0])

# Training the classifier

clf = KNeighborsClassifier()
clf.fit(features, labels)

preds = clf.predict([[9.1, 9.5, 6.4, 0.2]])
print(preds)


OverFitting And UnderFitting In Models
Techniques to avoid OverFitting
Resamping
Holding a validation dataset