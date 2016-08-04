OBJS = filter_and_csv.o
CXX = g++
DEBUG = -g
CXXFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
	
filter_and_csv : $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o filter_and_csv
	
filter_and_csv.o : json.hpp
	$(CXX) $(CXXFLAGS) filter_and_csv.cpp
	
clean:
	\rm *.o *~ filter_and_csv csv_data_to_import.csv results.txt
#
#tar:
#	tar cfv p1.tar Movie.h Movie.cpp Name.h Name.cpp NameList.h \
            NameList.cpp  Iterator.cpp Iterator.h
