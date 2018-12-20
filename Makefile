SHELL := /bin/bash
CC := g++
SRC_PATH := src/
OBJECTS = main.cpp
help:
	@echo "帮助："
	@echo " make data "
	@echo $(OBJECTS)
	@echo "		DATATYPE=type - 表示仅仅生成指定类型的数据 "
	@echo ""