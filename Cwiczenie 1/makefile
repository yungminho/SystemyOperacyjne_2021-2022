DIR = 'basename $(CURDIR)'
###############################################################################
NAME1 = a
NAME2 = b
NAME3 = c
NAME4 = d
NAME5 = e
###############################################################################
EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x
EXEC3 = $(NAME3).x
EXEC4 = $(NAME4).x
EXEC5 = $(NAME5).x
###############################################################################
OBJS1 = $(NAME2).o
OBJS2 = $(NAME2).o
OBJS3 = $(NAME3).o
OBJS4 = $(NAME4).o
OBJS5 = $(NAME5).o
###############################################################################
CFLAGS = -Wall -std=c99 -pedantic -O
LFLAGS = $(CFLAGS)

CO = gcc
LD = $(CO)

AR = ar

ARFLAGS = rsv
###############################################################################
%.o: %.c
	$(CO) $(CFLAGS) -c $<

###############################################################################
.PHONY: all

all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4) $(EXEC5)

$(EXEC1): $(OBJS1)
	$(CO) -o $@ $(CFLAGS) $^

$(EXEC2): $(OBJS2)
	$(CO) -o $@ $(CFLAGS) $^

$(EXEC3): $(OBJS3)
	$(CO) -o $@ $(CFLAGS) $^

$(EXEC4): $(OBJS4)
	$(CO) -o $@ $(CFLAGS) $^

$(EXEC5): $(OBJS5)
	$(CO) -o $@ $(CFLAGS) $^

###############################################################################
.PHONY: runA runB runC runD runE

runA: $(EXEC1)
	clear
	./$(EXEC1)

runB: $(EXEC2)
	clear
	./$(EXEC2)

runC: $(EXEC3)
	clear
	./$(EXEC3)

runD: $(EXEC4)
	clear
	./$(EXEC4)

runE: $(EXEC5)
	clear
	./$(EXEC5)

###############################################################################
.PHONY: clean tar

clean:
	rm -f *.o *~ *.a *.so *.x core core* a.out; rm -rf $(LIB_DIR)

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz		$(DIR))
