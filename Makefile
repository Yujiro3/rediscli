PROGRAM = rediscli
CC = g++
CFLAGS = -L/usr/local/lib  -I/usr/local/include -Wall -levent
SRCS = main.cpp mem_redis.cpp

all:
	$(CC) $(CFLAGS) -o $(PROGRAM) $(SRCS)

clean:
	rm $(PROGRAM)
