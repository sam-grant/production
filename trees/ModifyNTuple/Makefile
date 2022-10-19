C++ = g++

ROOTFLAGS = $(shell root-config --cflags)
ROOTLIBS  = $(shell root-config --libs)

Target = ModifyNTuple.exe ModifyQualityNTuple.exe

all:$(Target)

ModifyNTuple.exe: ModifyNTuple.C
	${C++} -o $@ ModifyNTuple.C $(Objects) $(ROOTFLAGS) $(ROOTLIBS)

ModifyQualityNTuple.exe: ModifyQualityNTuple.C
	${C++} -o $@ ModifyQualityNTuple.C $(Objects) $(ROOTFLAGS) $(ROOTLIBS)

clean:
	rm *exe
