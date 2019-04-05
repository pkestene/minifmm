default: fmm

include $(KOKKOS_PATH)/Makefile.kokkos

ifndef COMPILER
define compiler_help
Set COMPILER to change flags (defaulting to GNU).
Available compilers are :
	GNU INTEL

endef
$(info $(compiler_help))
COMPILER=GNU
endif

ifndef TARGET
define target_help
Set TARGET to change device (defaulting to CPU)
Available targets are :
	CPU GPU
endef
$(info $(target_help))
TARGET=CPU
endif

ARCH=native

COMPILER_GNU=g++
COMPILER_INTEL=icpc
CC=$(COMPILER_$(COMPILER))

FLAGS_GNU = -O3 -std=gnu++11 -Wall -march=$(ARCH)
FLAGS_INTEL = -O3 -std=gnu++11 -Wall -x$(ARCH)
CFLAGS = $(FLAGS_$(COMPILER))

LINKER_OPTS_GNU = -Wall
LINKER_OPTS_INTEL = -Wall
LINKER_OPTS = $(LINKER_OPTS_$(COMPILER))

CFLAGS += $(KOKKOS_CPPFLAGS) $(KOKKOS_CXXFLAGS)
LIBS += $(KOKKOS_LDFLAGS) $(KOKKOS_LIBS)

EXE=fmm
TYPE=DOUBLE

ifeq ($(TYPE), DOUBLE)
	CFLAGS += -DUSE_DOUBLE
else
	CFLAGS += -DUSE_FLOAT
endif

LIBS += -lm

REF_DIR=$(abspath $(shell pwd)/../ref)
CFLAGS += -I $(REF_DIR)

HEADERS=$(wildcard $(REF_DIR)/*.h)
HEADERS+=$(wildcard *.hpp)
REF_SRCS=$(wildcard $(REF_DIR)/*.cpp)
DIFF_SRCS=$(wildcard *.cpp)

SRCS = $(addprefix $(REF_DIR)/, $(filter-out $(DIFF_SRCS), $(notdir $(REF_SRCS))))
SRCS += $(DIFF_SRCS)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

print-%  : ; @echo $* = $($*)

$(EXE): $(OBJS)
	$(CC) $(OBJS) $(LINKER_OPTS) $(LIBS) -o $@

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS)
	-rm -f $(EXE)
