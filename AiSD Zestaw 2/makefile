CXX = g++
LIBS =
CXXFLAGS = -Wall -std=c++11

NAME1 = aisd2_1
TARGET1 = $(NAME1).exe
OBJECT1  = $(NAME1).o
HEADER1 = $(NAME1).h


.PHONY: all
all: $(TARGET1) 

%.o : %.cpp $(HEADER1) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(TARGET1) : $(OBJECT1)
	$(CXX) $(CXXFLAGS) $(LIBS) $(OBJECT1) -o $(TARGET1)


.PHONY : clean

clean :
	$(RM) $(TARGET1) *.o core