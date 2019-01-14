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

PROTO_DIR	= $(ROOT_DIR)/src/protobuf
PROTO_DEST	= $(ROOT_DIR)/src/common/proto

INC_DIR		=  -I/usr/include -I/usr/local/include
INC_DIR		+= -I./ -I./src

CFLAGS		:=  -pthread -std=c++11

TestFLAGS   := -std=c++11 -pthread -lboost_filesystem -lboost_thread -lboost_system


LIB_NAME	:= rpc_client
LIB_SUFFIX	:= .a
LIB_TARGET	:= lib$(LIB_NAME)$(LIB_SUFFIX)

TARGET		:= HFT_Server

.PHONY		: all clean

all: $(TARGET);

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $(OBJ_FILES)
	@echo **********Build*********

%.o: %.cpp
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@
%.o: %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@
%.o: %.cc
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ_FILES)

proto:
	protoc -I=$(PROTO_DIR) --cpp_out=$(PROTO_DEST) $(PROTO_DIR)/*.proto

