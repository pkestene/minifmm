ifndef COMPILER
define compiler_help
Set COMPILER to change flags (defaulting to GNU).
Available compilers are :
	CLANG CRAY GNU INTEL

endef
$(info $(compiler_help))
COMPILER=GNU
endif

ARCH=native

COMPILER_GNU=g++
COMPILER_INTEL=icpc
COMPILER_CLANG=clang++
COMPILER_CRAY=CC
CC=$(COMPILER_$(COMPILER))

FLAGS_GNU = -O3  -Wall -march=$(ARCH)
FLAGS_INTEL = -O3  -Wall -x$(ARCH)
FLAGS_CRAY = -O3
FLAGS_CLANG = -O3
CFLAGS = $(FLAGS_$(COMPILER))

LINKER_OPTS_GNU = -Wall
LINKER_OPTS_INTEL = -Wall
LINKER_OPTS_CRAY =
LINKER_OPTS_CLANG = -Wall
LINKER_OPTS = $(LINKER_OPTS_$(COMPILER))

LIBS=
TARGET=fmm
TYPE=DOUBLE

ifeq ($(TYPE), DOUBLE)
	CFLAGS += -DUSE_DOUBLE
else
	CFLAGS += -DUSE_FLOAT
endif

LIBS += -lm

HEADERS = $(wildcard *.h)
OBJECTS=$(patsubst %.cpp, %.o, $(wildcard *.cpp))

default: $(TARGET)

$(TARGET): $(OBJECTS)	
	$(CC) $(OBJECTS) $(LINKER_OPTS) $(LIBS) -o $@

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	-rm -f *.o
	-rm -f $(TARGET)
