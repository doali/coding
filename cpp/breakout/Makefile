# titi $> alias breakout='[ -f breakout ] && rm breakout && make && date || (make && date)'
# titi $> breakout
CC=g++
DEBUG_FLAG=-ggdb
CPPUNIT_CFLAGS=`pkg-config --cflags cppunit`
CPPUNIT_LDFLAGS=`pkg-config --libs cppunit`
EXE=breakout

all: $(EXE)

$(EXE): *.cpp
	$(CC) $(DEBUG_FLAG) $^ -o $(EXE) $(CPPUNIT_CFLAGS) $(CPPUNIT_LDFLAGS)

clean:
	rm $(EXE)
