
all: fmtp

clean:
	@(rm -f fmtp)
	@(rm -f fmtp.o)

fmtp: fmtp.c
	@(gcc -o fmtp ./fmtp.c)

check:
	@(./fmtp 'minptime=100' minptime)
	@(./fmtp 'minptime=100; a=2' minptime)
	@(./fmtp 'b=999; minptime=100; a=2' minptime)

