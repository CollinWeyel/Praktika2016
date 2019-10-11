OUTPUT = $(shell basename $(CURDIR))
ODIR = build
SDIR = src

CFLAGS = -Wall -g

_OBJS = main.o ui.o save.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(OUTPUT): $(OBJS)
	g++ $(OBJS) -o $(OUTPUT) $(CFLAGS)

$(ODIR)/%.o: $(SDIR)/%.cpp
	g++ -c -o $@ $< $(CFLAGS)

$(ODIR):
	mkdir $@

all: $(OUTPUT) doc

clean:
	rm -f $(ODIR)/*.o $(OUTPUT)

doc:
	doxygen doxygen.conf

.PHONY: clean doc