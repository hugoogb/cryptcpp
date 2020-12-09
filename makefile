CXX      := -g++
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
LDFLAGS  := -L/usr/lib -lstdc++ -lm
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := program
INCLUDE  := -Iinclude/
SRC      :=                      \
   $(wildcard src/util/*.cpp) \
   $(wildcard src/methods/*.cpp) \
   $(wildcard src/*.cpp)         \

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES \
         := $(OBJECTS:.o=.d)

.DEFAULT_GOAL := help

install: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

.PHONY: install build debug release info help clean

build:
	@mkdir -pv $(APP_DIR)
	@mkdir -pv $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: install

release: CXXFLAGS += -O2
release: install

info:
	@echo "[*] Application dir: ${APP_DIR}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRC}         "
	@echo "[*] Objects:         ${OBJECTS}     "
	@echo "[*] Dependencies:    ${DEPENDENCIES}"

help:
	@echo "[*] Avaliable commands: "
	@echo " - make install --> build dir, object files and executables"
	@echo " - make build --> creates build directories needed"
	@echo " - make debug --> install adding -DDEBUG and -g compile flags"
	@echo " - make release --> install adding -O2 compile flag"
	@echo " - make info --> show project build info"
	@echo " - make clean --> removes all the object files and executables built"

clean:
	-@rm -rvf $(BUILD)
