from cyaron import *

for id in range(2, 3) :
  io = IO(file_prefix = "xr", data_id = id)
  n = 100000
  io.input_writeln(n)
  for i in range(1, n + 1) :
    io.input_write(randint(1, 1e18+1))
    io.input_write(" ")