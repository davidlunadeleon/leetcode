CXX = g++
CLEANEXTS = o a
INSTALLDIR = ../../bin
OUTPUTFILE = treeUtils.a
OBJECTS = treeNode/treeNode.o treeFunctions/treeFunctions.o

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