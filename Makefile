CC := g++

ROOT_DIR	= $(shell pwd)
SRC_DIR		= $(ROOT_DIR)
SRC_FILES_CPP	:= $(shell find $(SRC_DIR) ! -path "$(SRC_DIR)/src/common/include/*" -name '*.cpp')
SRC_FILES_C	:= $(shell find $(SRC_DIR) ! -path "$(SRC_DIR)/src/common/include/*" -name '*.c')
SRC_FILES_CC	:= $(shell find $(SRC_DIR) ! -path "$(SRC_DIR)/src/common/include/*" -name '*.cc')
OBJ_FILES	:= $(SRC_FILES_CPP:.cpp=.o)
OBJ_FILES	+= $(SRC_FILES_C:.c=.o)
OBJ_FILES	+= $(SRC_FILES_CC:.cc=.o)

PROTOC		= $(ROOT_DIR)/src/common/bin/protoc
PROTO_DIR	:= $(ROOT_DIR)/src/common/protobuf
PROTO_DEST	:= $(ROOT_DIR)/src/common/proto
PROTO_FILE	:= $(shell find $(PROTO_DIR) -name '*.proto')

INC_DIR		:= -I./src -I./src/common/include

CFLAGS		:= -pthread -std=c++11 
CFLAGS		+= -L./src/common/lib -lprotobuf 

TARGET		:= HFT_Server

.PHONY		: all clean

all: $(TARGET);

$(TARGET): $(OBJ_FILES)
	$(CC) -o $@ $(OBJ_FILES) $(CFLAGS)
	@echo **********Build*********

%.o: %.cpp
	$(CC) -c $< $(INC_DIR) -o $@ $(CFLAGS)
%.o: %.c
	$(CC) -c $< $(INC_DIR) -o $@ $(CFLAGS)
%.o: %.cc
	$(CC) -c $< $(INC_DIR) -o $@ $(CFLAGS)

clean:
	-rm -f $(TARGET) $(OBJ_FILES)

proto: 
	rm -rf $(PROTO_DEST)/*
	$(PROTOC) -I=$(PROTO_DIR) --cpp_out=$(PROTO_DEST) $(PROTO_FILE)
