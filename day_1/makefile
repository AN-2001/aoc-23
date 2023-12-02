# Inner makefile.
# 	
# By Abed Na'aran December 2023

include ../makefile.flags
DAY := day_1

all: $(DAY).o
	ar cr lib$(DAY).a $(DAY).o
	@echo "done with $(DAY)"

%.o: %.cpp %.h
	$(CXX) $< $(CXXFLAGS) -c -o $@

clean:
	-@rm *.o *.a
