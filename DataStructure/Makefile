cc=gcc
exec=queue
objs=queue.o
cflags+=
ldflags+=

all:$(exec)
$(exec):$(objs)
	$(cc) $(ldflags) -o $@ $(objs)
clean:
	rm -f $(exec) *.elf *.gdb *.o
