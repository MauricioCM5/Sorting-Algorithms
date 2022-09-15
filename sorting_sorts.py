
#cout << "n\tquick\tmerge\tshell\tradix\tbucket\theap\n";.
import matplotlib.pyplot as plt
import numpy as np
matrix = [
[44, 85, 37, 28, 29, 66 ],
[74, 128, 100, 41, 47, 130 ],
[136, 193, 136, 60, 71, 210 ],
[201, 252, 228, 77, 104, 294 ],
[216, 313, 261, 96, 124, 380 ],
[286, 374, 348, 114, 154, 475 ],
[317, 450, 406, 133, 194, 571 ],
[384, 515, 543, 156, 222, 670 ],
[517, 577, 745, 170, 245, 758 ],
[561, 640, 652, 203, 278, 867 ],
[557, 709, 740, 207, 320, 960 ],
[744, 767, 813, 226, 331, 1061 ],
[715, 862, 1074, 284, 394, 1281 ],
[923, 948, 895, 263, 391, 1273 ],
[837, 976, 1056, 281, 442, 1467 ]]

x = []
for i in range(100, 1600, 100):
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
plt.show()
