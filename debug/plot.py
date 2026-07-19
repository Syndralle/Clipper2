import matplotlib.pyplot as plt

A = [(2,2),(8,5),(4,10),(2,2)]
B = [(5,1),(11,7),(6,11),(5,1)]

ax = plt.gca()

ax.plot(*zip(*A))
ax.plot(*zip(*B))

ax.set_aspect("equal")
ax.grid(True)

plt.show()
