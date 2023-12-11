from cyaron import * # 引入CYaRon的库



# while True:
#
#     input_io = IO("test1.in", "test1.out")
#     # test_data = IO(file_prefix="heat", data_id=i)
#     # input_io.input_writeln(randint(1,100000000))
#     input_io.input_writeln(10)
#     for i in range(10):
#         input_io.input_writeln(randint(1, 100000000))
#     # input_io.output_gen("1002_1.exe")
#     Compare.program("1002.exe", input=input_io, std_program="1002_1.exe")
#
#     exit(0)


while True:
    io = IO("test1.in", "test1.out")
    io.input_writeln(10)
    for i in range(10):
        io.input_writeln(randint(1,1000000000000000000))
    # io.output_gen("1002_1.exe")
    Compare.program("1002.exe", input=io, std_program="1002_1.exe")
    exit(0)