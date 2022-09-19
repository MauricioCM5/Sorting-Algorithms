
#cout << "n\tquick\tmerge\tshell\tradix\tbucket\theap\n";.
import matplotlib.pyplot as plt
import numpy as np
matrix = [
    [735, 1069, 646, 188, 282, 867, ],
[1187, 1581, 1653, 375, 594, 1917, ],
[1739, 2003, 2618, 564, 927, 3083, ],
[2696, 2715, 3999, 745, 1275, 4344, ],
[3192, 3385, 5040, 928, 1690, 5513, ],
[4192, 4005, 6655, 1117, 2033, 6608, ],
[4819, 4757, 7425, 1327, 2368, 7934, ],
[5460, 5777, 9493, 1509, 2824, 9117, ],
[6601, 6022, 11404, 1717, 3187, 10539, ],
[7060, 6974, 12114, 1953, 3589, 11785, ],
[7420, 7481, 12315, 2176, 3905, 13070, ],
[8723, 8069, 15893, 2308, 4449, 14502, ],
[9767, 8812, 16502, 2545, 4655, 15995, ],
[12042, 10686, 20605, 2698, 5242, 17301, ],
[11746, 12725, 19923, 2951, 5598, 18857, ]]

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
