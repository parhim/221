CC=g++
CFLAGS=-Wall -O3
PROG=LQueue_driver
OBJS=LQueue_driver.o LQueue.o

runway: runway.o AQueue.o
	$(CC) -o $(PROG) $(OBJS)

.C.o:
	$(CC) $(CFLAGS) -c $*.C

LQueue.o: LQueue.C LQueue.h
AQueue.o: AQueue.C AQueue.h
LQueue_driver.o:	LQueue_driver.C LQueue.o LQueue.h

clean:
	rm *.o core
