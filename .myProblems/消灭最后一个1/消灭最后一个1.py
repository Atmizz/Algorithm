from cyaron import *

for id in range(1, 11) :
  io = IO(file_prefix = "xr", data_id = id)
  n = randint(1, 2001)
  io.input_writeln(n)
  for i in range(0, n) :
    io.input_write(randint(1, 2147483648))
    io.input_write(" ")