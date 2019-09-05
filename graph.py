import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import csv

labels = ['Random', 'Ordenado Crescente', 'Ordenado Decrescente', 'Crescente/Decrescente', 'Decrescente/Crescente']
Random = []
Crescente = []
Decrescente = []
CresDecre = []
DecreCres = []

with open('result.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        Random.append(float(row[0]))
        Crescente.append(float(row[1]))
        Decrescente.append(float(row[2]))
        CresDecre.append(float(row[3]))
        DecreCres.append(float(row[4]))

def Average(lst): 
    return round(sum(lst)/len(lst),5)

Random = Average(Random)
Crescente = Average(Crescente)
Decrescente = Average(Decrescente)
CresDecre = Average(CresDecre)
DecreCres = Average(DecreCres)


x = np.arange(len(labels))  # the label locations
width = 0.5  # the width of the bars

fig, ax = plt.subplots()
rects1 = ax.bar(x[0], Random, width, label='Random')
rects2 = ax.bar(x[1], Crescente, width, label='Crescente')
rects3 = ax.bar(x[2], Decrescente, width, label='Decrescente')
rects4 = ax.bar(x[3], CresDecre, width, label='CresDecre')
rects5 = ax.bar(x[4], DecreCres, width, label='DecreCres')

# Add some text for labels, title and custom x-axis tick labels, etc.
ax.set_ylabel('Tempo')
ax.set_title('Tempo de acordo com o tipo')
ax.set_xticks(x)
ax.set_xticklabels(labels)
ax.legend(labels)


def autolabel(rects):
    """Attach a text label above each bar in *rects*, displaying its height."""
    for rect in rects:
        height = rect.get_height()
        ax.annotate('{}'.format(height),
                    xy=(rect.get_x() + rect.get_width() / 2, height),
                    xytext=(0, 3),  # 3 points vertical offset
                    textcoords="offset points",
                    ha='center', va='bottom')


autolabel(rects1)
autolabel(rects2)
autolabel(rects3)
autolabel(rects4)
autolabel(rects5)

fig.tight_layout()

plt.show()