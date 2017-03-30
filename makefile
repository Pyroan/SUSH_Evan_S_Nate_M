OBJS=sush.o tokenizer.o

all: sush sush-debug

clean:
	rm -f *.o sush sush-debug

sush: $(OBJS)
	$(CC) -o sush $(OBJS)

sush-debug: $(OBJS)
	$(CC) -g sush-debug $(OBJS)

