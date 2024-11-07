CXX = g++
LIBS =
CXXFLAGS = -Wall -std=c++11

NAME1 = aisd1_1
TARGET1 = $(NAME1).out
OBJECT1  = $(NAME1).o

NAME2 = aisd1_2
TARGET2 = $(NAME2).out
OBJECT2  = $(NAME2).o

.PHONY: all
all: $(TARGET1) $(TARGET2)


$(TARGET1) : $(OBJECT1)
	$(CXX) $(CXXFLAGS) $(LIBS) $(OBJECT1) -o $(TARGET1)

$(TARGET2) : $(OBJECT2)
	$(CXX) $(CXXFLAGS) $(LIBS) $(OBJECT2) -o $(TARGET2)


.PHONY : clean

clean :
	$(RM) $(TARGET1) $(TARGET2) *.o core