#	Common MakeFile
.PHONY: common clean

CC	:=	gcc
XX	:=	g++

#
#	路径定义
#
CUR_DIR		:= ./
ROOT_DIR	:= ../
EXT_DIR		:= $(ROOT_DIR)/ext
TARGET_LIB_DIR	:= $(CUR_DIR)/lib/
INC_DIR		:= $(CUR_DIR)/code
INC_DIR		+= $(CUR_DIR)
SRC_DIR		:= $(CUR_DIR)/code
OUT_DIR		:= $(CUR_DIR)/out
#
#	依赖模块
#
include $(EXT_DIR)/boost/MakeFile.inc
include $(EXT_DIR)/curl/MakeFile.inc

#
#	所需编译的源文件
#
ALL_DIRS	:= $(shell find $(SRC_DIR) -maxdepth 4 -type d)
SRC_FILES	:= $(foreach dir,$(ALL_DIRS),$(wildcard $(dir)/*.cpp))
OBJ := $(SRC_FILES:.cpp=.o)
OBL_WITHOUT_DIR := $(notdir $(OBJ))
OBJ_WITH_DIR := $(addprefix $(OUT_DIR)/, $(OBL_WITHOUT_DIR))

# 给%.cpp用的搜索路径
vpath %.cpp $(ALL_DIRS)

#
#	目标模块
#
LIB_NAME	:= common
TARGET	:= $(TARGET_LIB_DIR)/lib$(LIB_NAME).a

#
#	编译配置
#
C_FLAGS		:= -g -pipe -W -Wall -Werror -fPIC -O0 -rdynamic -std=c++17
C_FLAGS		+= $(addprefix -I, $(INC_DIR))
LD_FLAGS	:= $(addprefix -L, $(LIB_DIR)) $(addprefix -l, $(LD_LIBS))
LIB_DIR_SH	:= $(shell echo "$(LIB_DIR)"| sed -e "s/ \./:\./g")

$(TARGET): $(OBJ_WITH_DIR)
	ar -r $@ $^
	@echo "\033[36m======== build $(LIB_NAME) succ ========\033[0m"

$(OUT_DIR)/%.o: %.cpp
	$(XX) $(C_FLAGS) -c $< -o $@

clean:
	-rm $(TARGET) $(OBJ_WITH_DIR)