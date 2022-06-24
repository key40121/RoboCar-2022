CPP = g++
CPPFLAGS = -fPIC -g -pthread
INCLUDES = -I/usr/local/include/opencv2 -I/usr/local/include/opencv -I/usr/local/include/zmp/rc110_v2
LIBS = -L/usr/local/lib/zmp/rc110_v2 -lBaseboard -lRcControl -lpthread -L/usr/local/lib/ -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio -lopencv_imgcodecs

TARGET = sample 
OBJS = sample.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPP) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)
clean:
	rm -rf $(OBJS) $(TARGET)

.cpp.o: $*.h
	$(CPP) $(CPPFLAGS) $(INCLUDES) -c $<
