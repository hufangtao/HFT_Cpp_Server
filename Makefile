CC := g++

ROOT_DIR	= $(shell pwd)
SRC_DIR		= $(ROOT_DIR)
SRC_FILES_CPP	:= $(shell find $(SRC_DIR) -name '*.cpp')
SRC_FILES_C		:= $(shell find $(SRC_DIR) -name '*.c')
SRC_FILES_CC	:= $(shell find $(SRC_DIR) -name '*.cc')
OBJ_FILES	:= $(SRC_FILES_CPP:.cpp=.o)
OBJ_FILES	+= $(SRC_FILES_C:.c=.o)
OBJ_FILES	+= $(SRC_FILES_CC:.cc=.o)

PROTO_DIR	:= $(ROOT_DIR)/src/protobuf
PROTO_DEST	:= $(ROOT_DIR)/src/common/proto
PROTO_FILE	:= $(shell find $(PROTO_DIR) -name '*.proto')

INC_DIR		:= -I./src -I/usr/local/protobuf/include

CFLAGS		:= -pthread 
CFLAGS		+= -L/usr/local/protobuf/lib -lprotobuf 

TARGET		:= HFT_Server

.PHONY		: all clean

all: $(TARGET);

$(TARGET): $(OBJ_FILES)
	$(CC) -o $@ $(OBJ_FILES) $(CFLAGS)
	@echo **********Build*********

%.o: %.cpp
	$(CC) -c $< $(INC_DIR) -o $@ 
%.o: %.c
	$(CC) -c $< $(INC_DIR) -o $@
%.o: %.cc
	$(CC) -c $< $(INC_DIR) -o $@

clean:
	-rm -f $(TARGET) $(OBJ_FILES)

proto1:
	for file in $(PROTO_FILE)
	do
		protoc -I=$(PROTO_DIR) --cpp_out=$(PROTO_DEST) $(file)
	done

proto: 
	rm -rf $(PROTO_DEST)/*
	protoc -I=$(PROTO_DIR) --cpp_out=$(PROTO_DEST) $(PROTO_FILE)

