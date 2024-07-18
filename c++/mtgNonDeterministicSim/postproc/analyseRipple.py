import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv("results/rippleSimRes.csv",sep=";")

# ax = data.plot.hist(column="nmbRipple",bins=32,density=True)
# plt.show()

print(data["nmbRipple"].value_counts(normalize=True))