PNAME := picsort

PCXXSRC := $(wildcard src/*.cpp)

PCXXOBJS := $(PCXXSRC:.cpp=.o)

CXXFLAGS += -std=c++17 -g

LDLIBS += -lSDL2

.PHONY: all
.SILENT: all $(PCXXOBJS)

all: $(PNAME)

$(PNAME): $(PCXXOBJS)
	@-$(LINK.cc) $(PCXXOBJS) -o $(PNAME) $(LDLIBS)
	@-$(RM) $(PCXXOBJS)

clean:
	@-$(RM) $(PCXXOBJS)
	@-$(RM) $(PNAME)