"""

E. Wes Bethel, Copyright (C) 2022

October 2022

Description: This code loads a .csv file and creates a 3-variable plot, and saves it to a file named "myplot.png"

Inputs: the named file "sample_data_3vars.csv"

Outputs: displays a chart with matplotlib

Dependencies: matplotlib, pandas modules

Assumptions: developed and tested using Python version 3.8.8 on macOS 11.6

"""

import pandas as pd
import matplotlib.pyplot as plt

# Create a 3-variable chart showing problem size vs. MFLOP/s

plot_fname = "myplot_mflops.png"

fname = "sample_data_3vars.csv"
df = pd.read_csv(fname, comment="#")
print(df)

var_names = list(df.columns)

print("var names =", var_names)

# split the df into individual vars
# assumption: column order - 0=problem size, 1=blas time, 2=basic time

problem_sizes = df[var_names[0]].values.tolist()
mflops_code1 = df[var_names[4]].values.tolist()
mflops_code2 = df[var_names[5]].values.tolist()
mflops_code3 = df[var_names[6]].values.tolist()

plt.figure()

plt.title("Comparison of 3 Codes: MFLOP/s")

xlocs = [i for i in range(len(problem_sizes))]

plt.xticks(xlocs, problem_sizes)

plt.plot(mflops_code1, "r-o")
plt.plot(mflops_code2, "b-x")
plt.plot(mflops_code3, "g-^")

#plt.xscale("log")
#plt.yscale("log")

plt.xlabel("Problem Sizes")
plt.ylabel("MFLOP/s")

varNames = [var_names[4], var_names[5], var_names[6]]
plt.legend(varNames, loc="best")

plt.grid(axis='both')

# save the figure before trying to show the plot
plt.savefig(plot_fname, dpi=300)

plt.show()

# Create a 3-variable chart showing problem size vs. % peak memory bandwidth utilized

plot_fname = "myplot_mem_bw.png"

fname = "sample_data_3vars.csv"
df = pd.read_csv(fname, comment="#")
print(df)

var_names_bw = list(df.columns)

print("var names =", var_names_bw)

# split the df into individual vars
# assumption: column order - 0=problem size, 1=blas time, 2=basic time, 3=total bytes, 4=GB/s, 5=% peak

problem_sizes_bw = df[var_names_bw[0]].values.tolist()
mem_bw_code1 = df[var_names_bw[5]].values.tolist()
mem_bw_code2 = df[var_names_bw[6]].values.tolist()
mem_bw_code3 = df[var_names_bw[7]].values.tolist()

plt.figure()

plt.title("Comparison of 3 Codes: Memory Bandwidth")

xlocs_bw = [i for i in range(len(problem_sizes_bw))]

plt.xticks(xlocs_bw, problem_sizes_bw)

plt.plot(mem_bw_code1, "r-o")
plt.plot(mem_bw_code2, "b-x")
plt.plot(mem_bw_code3, "g-^")

#plt.xscale("log")
#plt.yscale("log")

plt.xlabel("Problem Sizes")
plt.ylabel("% Peak Memory Bandwidth")

varNames_bw = [var_names_bw[5], var_names_bw[6], var_names_bw[7]]
plt.legend(varNames_bw, loc="best")

plt.grid(axis='both')

# save the figure before trying to show the plot
plt.savefig(plot_fname, dpi=300)

plt.show()

# Create a 3-variable chart showing problem size vs. memory latency

plot_fname = "myplot_mem_lat.png"

fname = "sample_data_3vars.csv"
df = pd.read_csv(fname, comment="#")
print(df)

var_names_lat = list(df.columns)

print("var names =", var_names_lat)

# split the df into individual vars
# assumption: column order - 0=problem size, 4=memory latency

problem_sizes_lat = df[var_names_lat[0]].values.tolist()
code1_latency = df[var_names_lat[4]].values.tolist()
code2_latency = df[var_names_lat[5]].values.tolist()
code3_latency = df[var_names_lat[6]].values.tolist()

plt.figure()

plt.title("Comparison of 3 Codes (Memory Latency)")

xlocs_lat = [i for i in range(len(problem_sizes_lat))]

plt.xticks(xlocs_lat, problem_sizes_lat)

plt.plot(code1_latency, "r-o")
plt.plot(code2_latency, "b-x")
plt.plot(code3_latency, "g-^")

plt.xlabel("Problem Sizes")
plt.ylabel("Latency (ns)")

varNames_lat = [var_names_lat[4], var_names_lat[5], var_names_lat[6]]
plt.legend(varNames_lat, loc="best")

plt.grid(axis='both')

# save the figure before trying to show the plot
plt.savefig(plot_fname, dpi=300)

plt.show()

# EOF
