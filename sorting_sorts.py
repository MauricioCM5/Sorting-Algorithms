
import matplotlib.pyplot as plt
import numpy as np

matrix = [
[5457, 5800, 9701, 1495, 2784, 9269 ],
[12011, 10815, 24192, 2968, 6089, 19884 ],
[17059, 16333, 37647, 4615, 10296, 31619 ],
[26216, 23428, 61084, 6078, 12543, 52946 ],
[35033, 31594, 83646, 7794, 16223, 60846 ],
[42477, 33779, 91889, 8983, 20017, 68237 ],
[46258, 38220, 108261, 10409, 23848, 91564 ],
[57402, 43058, 157592, 11911, 26341, 92419 ],
[58157, 49222, 143020, 13551, 30284, 103985 ],
[70218, 54019, 174341, 14824, 33741, 116999 ],
[70203, 60152, 178763, 16498, 37713, 129222 ],
[88128, 65031, 217595, 17910, 41822, 142925 ],
[95640, 71643, 234155, 19521, 44430, 157240 ],
[114655, 75582, 270161, 20994, 49274, 169323 ],
[113587, 79869, 271265, 22474, 53709, 182503 ]]


x = []
for i in range(8000, 128000, 8000):
    x.append(i)

y =[[],[],[],[],[],[]]

for i in range(6):
    for j in range(15):
        y[i].append(matrix[j][i])
        

config = [('c', 'quick'), ('b', "merge"), ('g', 'shell'),
          ('y', 'radix'), ('k', 'bucket'),
          ('m', 'heap')]

for i in range(6):
    plt.plot(x, y[i], color=config[i][0], label=config[i][1])
    
# plot
plt.title("Time")
plt.legend()
plt.xlabel("Number of elements")
plt.ylabel("Time in microseconds")
plt.show()
