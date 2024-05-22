from cyaron import *

n = 1
for id in range(1, 11) :
  io = IO(file_prefix = "xr", data_id = id)
  n = min(n, 100000)
  io.input_writeln(n)
  bt = Graph.binary_tree(n)
  io.input_writeln(bt.to_str(shulffe = True, output = Edge.unweighted_edge))
  n *= 10