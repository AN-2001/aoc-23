# Inner makefile.
# 	
# By Abed Na'aran December 2023

include ../makeflags
DAY := day_T

all: $(DAY).o
	ar cr lib$(DAY).a $(DAY).o
	@echo "done with $(DAY)"

%.o: %.cpp %.h
	$(CXX) $< $(CXXFLAGS) -c -o $@

clean:
	-@rm *.o *.a 2> /dev/null
