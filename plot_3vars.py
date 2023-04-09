"""

E. Wes Bethel, Copyright (C) 2022

October 2022

Description: This code loads a .csv file and creates a 3-variable plot

Inputs: the named file "sample_data_3vars.csv"

Outputs: displays a chart with matplotlib

Dependencies: matplotlib, pandas modules

Assumptions: developed and tested using Python version 3.8.8 on macOS 11.6

"""

import pandas as pd
import matplotlib.pyplot as plt


# MFLOP/s plot
fname_mflop = "sample_data_mflop.csv"
df_mflop = pd.read_csv(fname_mflop, comment="#")

var_names_mflop = list(df_mflop.columns)
problem_sizes_mflop = df_mflop[var_names_mflop[0]].values.tolist()
code1_mflop = df_mflop[var_names_mflop[1]].values.tolist()
code2_mflop = df_mflop[var_names_mflop[2]].values.tolist()
code3_mflop = df_mflop[var_names_mflop[3]].values.tolist()

plt.figure()
plt.title("MFLOP/s Comparison")
plt.xlabel("Problem Size")
plt.ylabel("MFLOP/s")
plt.plot(problem_sizes_mflop, code1_mflop, "r-o")
plt.plot(problem_sizes_mflop, code2_mflop, "b-x")
plt.plot(problem_sizes_mflop, code3_mflop, "g-^")
plt.legend(var_names_mflop[1:], loc="best")
plt.grid(axis='both')

# Memory Bandwidth plot
fname_mem_bw = "sample_data_mem_bw.csv"
df_mem_bw = pd.read_csv(fname_mem_bw, comment="#")

var_names_mem_bw = list(df_mem_bw.columns)
problem_sizes_mem_bw = df_mem_bw[var_names_mem_bw[0]].values.tolist()
code1_mem_bw = df_mem_bw[var_names_mem_bw[1]].values.tolist()
code2_mem_bw = df_mem_bw[var_names_mem_bw[2]].values.tolist()
code3_mem_bw = df_mem_bw[var_names_mem_bw[3]].values.tolist()

plt.figure()
plt.title("Memory Bandwidth Comparison")
plt.xlabel("Problem Size")
plt.ylabel("% Peak Memory Bandwidth")
plt.plot(problem_sizes_mem_bw, code1_mem_bw, "r-o")
plt.plot(problem_sizes_mem_bw, code2_mem_bw, "b-x")
plt.plot(problem_sizes_mem_bw, code3_mem_bw, "g-^")
plt.legend(var_names_mem_bw[1:], loc="best")
plt.grid(axis='both')

# Memory Latency plot
fname_mem_lat = "sample_data_mem_lat.csv"
df_mem_lat = pd.read_csv(fname_mem_lat, comment="#")

var_names_mem_lat = list(df_mem_lat.columns)
problem_sizes_mem_lat = df_mem_lat[var_names_mem_lat[0]].values.tolist()
code1_mem_lat = df_mem_lat[var_names_mem_lat[1]].values.tolist()
code2_mem_lat = df_mem_lat[var_names_mem_lat[2]].values.tolist()
code3_mem_lat = df_mem_lat[var_names_mem_lat[3]].values.tolist()

plt.figure()
plt.title("Memory Latency Comparison")
plt.xlabel("Problem Size")
plt.ylabel("Memory Latency (ns)")
plt.plot(problem_sizes_mem_lat, code1_mem_lat, "r-o")
plt.plot(problem_sizes_mem_lat, code2_mem_lat, "b-x")
plt.plot(problem_sizes_mem_lat, code3_mem_lat, "g-^")
plt.legend(var_names_mem_lat[1:], loc="best")
plt.grid(axis='both')

plt.show()


# EOF
