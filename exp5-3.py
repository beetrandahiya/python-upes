a=[('V', 62), ('VI', 68), ('VII', 72), ('VIII', 70), ('IX', 74), ('X', 65)]
a_vals=[x[1] for x in a]
min_max= lambda a_vals: (min(a_vals) , max(a_vals))
print(min_max(a_vals))