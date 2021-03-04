# GameServer MakeFile
.PHONY: gameserver clean

CC	:=	gcc
XX	:=	g++

ROOT_DIR	:= ../
EXT_DIR		:= $(ROOT_DIR)/ext/
CUR_DIR		:= ./
SRC_DIR		:= $(CUR_DIR)/code
INC_DIR		:= $(CUR_DIR)/code
LIB_DIR		:= ./
OUT_DIR		:= $(CUR_DIR)/out
LD_LIBS		+= boost_thread boost_system boost_coroutine boost_context boost_chrono boost_regex pthread

include $(EXT_DIR)/boost/MakeFile.inc
include $(ROOT_DIR)/common/MakeFile.inc

C_FLAGS		:= -g -Wall -Werror -O0 -std=c++17
C_FLAGS		+= $(addprefix -I,$(INC_DIR))
LD_FLAGS	+= $(addprefix -L,$(LIB_DIR)) $(addprefix -l, $(LD_LIBS))
LIB_DIR_SH  += $(shell echo "$(LIB_DIR)"| sed -e "s/ \./:\./g")

SOURCE_FILES := $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp)
OBJ := $(SOURCE_FILES:.cpp=.o)
OBL_WITHOUT_DIR := $(notdir $(OBJ))
OBJ_WITH_DIR := $(addprefix $(OUT_DIR)/, $(OBL_WITHOUT_DIR))

# 给%.cpp用的搜索路径
vpath %.cpp $(SRC_DIR)

# 目标模块
TARGET := gameserver

$(TARGET): $(OBJ_WITH_DIR)
	@echo "C_FLAGS:"$(C_FLAGS)
	@echo "SOURCE_FILES:"$(SOURCE_FILES)
	@echo "ALL_PROJECTS:"$(ALL_PROJECTS)
	@echo -e "\033[36m[$(APP_TARGET) LINK] $@\033[0m"
	$(XX) $^ $(LD_FLAGS) -o $@
	export LD_LIBRARY_PATH=$(LIB_DIR_SH)

$(OUT_DIR)/%.o:%.cpp
	$(XX) $(C_FLAGS) -c $< -o $@

lib:
	export LD_LIBRARY_PATH=$(LIB_DIR_SH)

clean:
	-rm $(TARGET) $(OBJ_WITH_DIR)

