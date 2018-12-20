CC := g++
CC += -g

ROOT_DIR	= $(shell pwd)
SRC_DIR		= $(ROOT_DIR)
SRC_FILES_CPP	:= $(shell find $(SRC_DIR) -name '*.cpp')
SRC_FILES_C	:= $(shell find $(SRC_DIR) -name '*.c')
SRC_FILES_CC	:= $(shell find $(SRC_DIR) -name '*.cc')
OBJ_FILES	:= $(SRC_FILES_CPP:.cpp=.o)
OBJ_FILES	+= $(SRC_FILES_C:.c=.o)
OBJ_FILES	+= $(SRC_FILES_CC:.cc=.o)

INC_DIR		=  -I/usr/include -I/usr/local/include
INC_DIR		+= -I./

CFLAGS		:= -lpthread -Wwrite-strings -w # -fPIC

LIB_NAME	:= rpc_client
LIB_SUFFIX	:= .a
LIB_TARGET	:= lib$(LIB_NAME)$(LIB_SUFFIX)

TARGET		:= HFT_Server

.PHONY		: all clean

all: $(TARGET);

$(TARGET): $(OBJ_FILES)
	$(CC) -o $@ $(OBJ_FILES)
	@echo **********Build*********

%.o: %.cpp
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@
%.o: %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@
%.o: %.cc
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ_FILES)

