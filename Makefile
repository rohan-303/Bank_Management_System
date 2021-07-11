CC=g++

CFLAGS=-c -Wall

all: banking

banking: main.o account.o bankfnct.o customerfnct.o intro.o
	$(CC) main.o account.o bankfnct.o customerfnct.o intro.o -o banking
	./banking

main.o:main.cpp 
	$(CC) $(CFLAGS) main.cpp

account.o:account.cpp
	$(CC) $(CFLAGS) account.cpp

bankfnct.o:bankfnct.cpp
	$(CC) $(CFLAGS) bankfnct.cpp

customerfnct.o:customerfnct.cpp
	$(CC) $(CFLAGS) customerfnct.cpp	

intro.o:intro.cpp
	$(CC) $(CFLAGS) intro.cpp


clean:
	rm -rf *o banking	
