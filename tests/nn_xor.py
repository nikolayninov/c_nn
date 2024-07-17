from cnn import Sequential, Dense, Input, Sigmoid, ReLU
import numpy as np

relu = ReLU()
sigmoid = Sigmoid()
model = Sequential(0.5)

inpt = Input(2)
d1 = Dense(2, relu)
d2 = Dense(2, relu)
d3 = Dense(1, sigmoid)

model.add_layer(inpt)
model.add_layer(d1)
model.add_layer(d2)
model.add_layer(d3)

x_train = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
y_train = np.array([0, 1, 1, 0])

model.run(x_train, y_train, 5000, 1)
model.save("test_xor.cnn")
print(x_train)
print(y_train)
print("Prediction:")
print(model.predict(x_train))

new_model = Sequential(0.5)
new_model.load("test_xor.cnn")
print("Prediction (loaded):")
print(new_model.predict(x_train))
