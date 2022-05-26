COMPILER = g++
OBJS = HealthPoints.o
EXEC = Test
DEBUG_FLAG = -g
COMP_FLAG = -std=c++11 -Wall -Werror

$(EXEC) : $(OBJS)
	$(COMPILER) $(DEBUG_FLAG) $(OBJS) -o $@
HealthPoints.o: HealthPoints.h HealthPoints.cpp
	$(COMPILER) -c $(DEBUG_FLAG) $(COMP_FLAG) HealthPoints.cpp

clean:
	rm -f $(OBJS) $(EXEC)
	