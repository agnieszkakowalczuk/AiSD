CXX = g++
LIBS =
CXXFLAGS = -Wall -std=c++11

NAME = aisd6
TARGET = $(NAME).out
OBJECT  = $(NAME).o
HEADER = $(NAME).h


.PHONY: all
all: $(TARGET)

%.o : %.cpp $(HEADER) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(TARGET) : $(OBJECT)
	$(CXX) $(CXXFLAGS) $(LIBS) $(OBJECT) -o $(TARGET)

.PHONY : run

run :
	./$(TARGET)

.PHONY : clean

clean :
	$(RM) $(TARGET) *.o core

