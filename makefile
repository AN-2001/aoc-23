# Top level makefile.
#
# By Abed Na'aran December 2023

include makefile.flags

OBJ := day.o
HEADERS := $(wildcard *.h)

all: $(OBJ) aoc

aoc: aoc.o days 
	$(CXX) $< $(OBJ) $(LIBS) -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp %.h $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

days:
	@- $(foreach DAY, $(DAYS), cd $(DAY) && make all && cd ..;)
clean:
	@rm *.o aoc
	@- $(foreach DAY, $(DAYS), cd $(DAY) && make clean && cd ..;)
