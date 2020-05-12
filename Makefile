CC=gcc
CFLAGS=-D UNICODE -D _UNICODE -c -O2 -o
TARGETS=simple-1.exe simple-2.exe

%.obj: %.c 
	$(CC) $(CFLAGS) $@ $<

all: $(TARGETS)

simple-1.exe: simple-1.obj
	$(CC) -o simple-1.exe simple-1.obj

simple-2.exe: simple-2.obj
	$(CC) -o simple-2.exe simple-2.obj -s -lcomctl32

strip: $(TARGETS)
	strip $(TARGETS)
