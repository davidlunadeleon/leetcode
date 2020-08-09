CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic-errors -g -O2
CLEANEXTS = o a
INSTALLDIR = ../../bin
OUTPUTFILE = vectorUtils.a
OBJECTS = vectorFunctions/vectorFunctions.o

.PHONY: all
all: $(OUTPUTFILE) install clean

$(OUTPUTFILE): $(OBJECTS)
	ar rvs $@ $^

.PHONY: install
install: 
	mkdir -p $(INSTALLDIR)
	cp -p $(OUTPUTFILE) $(INSTALLDIR)

.PHONY: clean
clean: 
	find . -type f -name '*.a' -delete
	find . -type f -name '*.o' -delete