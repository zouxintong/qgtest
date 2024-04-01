import numpy as np
import matplotlib.pyplot as plt
from tqdm import tqdm


def update(x):
    epsilon = 0.01  # 小的随机扰动的大小
    return np.array([np.mean(x[np.abs(x - xi) < 1]) + epsilon * np.random.randn() for xi in x]) + epsilon * np.random.randn(len(x))


L_values = np.arange(0, 51, 0.1)
num_agents = 5000
num_simulations = 10
num_steps = 5000

L_points = []
x_points = []

for L in tqdm(L_values, desc="Processing L values"):
    for _ in range(num_simulations):
        x = np.linspace(0, L, int(L * num_agents))

        for _ in range(num_steps):
            x = update(x)

        x = x - L / 2

        L_points.extend([L] * len(x))
        x_points.extend(x)

plt.figure(figsize=(10, 8))
plt.plot(L_values, [0] * len(L_values), '--', color='black', linewidth=0.8)
plt.plot(L_values, L_values / 2, '--', color='black', linewidth=0.8)
plt.plot(L_values, -L_values / 2, '--', color='black', linewidth=0.8)

plt.plot(L_points, x_points, '.', color='darkblue', markersize=0.1, alpha=0.1)

plt.xlim(0, 50)
plt.ylim(-25, 25)
plt.xlabel('L')
plt.ylabel('x - L/2')
plt.title("Blondel et al.'s Multi-Agent Consensus Model with Random Perturbation for Horizontal Linkage")
plt.show()