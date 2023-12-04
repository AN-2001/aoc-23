# Top level makefile.
#
# By Abed Na'aran December 2023

include makeflags

OBJ := day.o
HEADERS := $(wildcard *.h)

all: $(OBJ) aoc

analyze:
	-@mkdir -p ./cppCheckBuild
	@cppcheck --language=c++ --error-exitcode=1 \
		     --cppcheck-build-dir=./cppCheckBuild *.cpp *.h */*.cpp */*.h \
			 2> analysis.out

aoc: aoc.o days 
	$(CXX) $< $(OBJ) $(LIBS) -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp %.h $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

days:
	-@- $(foreach DAY, $(DAYS), cd $(DAY) && $(MAKE) all && cd ..;)
clean:
	-@- $(foreach DAY, $(DAYS), cd $(DAY) && $(MAKE) clean && cd ..;)
	-@rm *.o aoc 2> /dev/null
