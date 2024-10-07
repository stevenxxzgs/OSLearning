import numpy as np
import matplotlib.pyplot as plt

def weierstrass(x, a, b, N):
    return sum(a**n * np.cos(b**n * np.pi * x) for n in range(N))

a = 0.5
b = 3
N = 100
x = np.linspace(0, 1, 1000)
y = [weierstrass(xi, a, b, N) for xi in x]

plt.plot(x, y)
plt.title('Weierstrass Function')
plt.xlabel('x')
plt.ylabel('W(x)')
plt.show()