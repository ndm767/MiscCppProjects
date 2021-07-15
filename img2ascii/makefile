PNAME := img2ascii

PCXXSRC := $(wildcard src/*.cpp)

PCXXOBJS := $(PCXXSRC:.cpp=.o)

CXXFLAGS += -std=c++17

LDLIBS += 

.PHONY: all
.SILENT: all $(PCXXOBJS)

all: $(PNAME)

$(PNAME): $(PCXXOBJS)
	@-$(LINK.cc) $(PCXXOBJS) -o $(PNAME) $(LDLIBS)
	@-$(RM) $(PCXXOBJS)

clean:
	@-$(RM) $(PNAME)
	@-$(RM) $(PCXXOBJS)