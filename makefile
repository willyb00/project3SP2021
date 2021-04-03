OBJS	= PriorityQueue.o PriorityQueueDr.o
SOURCE	= PriorityQueue.cpp PriorityQueueDr.cpp
HEADER	= PriorityQueue.h
OUT	= PriorityQueueDr
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

PriorityQueue.o: PriorityQueue.cpp
	$(CC) $(FLAGS) PriorityQueue.cpp 

PriorityQueueDr.o: PriorityQueueDr.cpp
	$(CC) $(FLAGS) PriorityQueueDr.cpp 

clean:
	rm -f $(OBJS) $(OUT)
