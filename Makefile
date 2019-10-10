OUTPUT = $(shell basename $(CURDIR))
ODIR = build
SDIR = src

CFLAGS = -Wall

_OBJS = main.o ui.o save.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

#all: $(OUTPUT) doc

$(OUTPUT): $(OBJS)
	g++ $(OBJS) -o $(OUTPUT)

$(ODIR)/%.o: $(SDIR)/%.cpp
	g++ -c -o $@ $< $(CFLAGS)

$(ODIR):
	mkdir $@

clean:
	rm -f $(ODIR)/*.o $(OUTPUT)

doc:
	doxygen doxygen.conf

.PHONY: clean doc