CPP = g++
CPPFLAGS = -fPIC -g -pthread
INCLUDES = -I/usr/local/include/zmp/rc110_v2 -I/usr/local/include/urg_cpp
LIBS = -L/usr/local/lib/zmp/rc110_v2 -lRcControl -lLaserRangeSensor -lpthread -lurg_cpp

TARGET = SampleLRS
OBJS = SampleLRS.o


all: $(TARGET) 


$(TARGET): $(OBJS)
	$(CPP) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)


clean:
	rm      -rf $(OBJS) $(TARGET)


#libIpm.a: $(OBJS)
#	ar crv $@ $(OBJS)
#


.cpp.o: $*.h
	$(CPP) $(CPPFLAGS) $(INCLUDES) -c $<



