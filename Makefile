### Build Commands ###
CC = g++
AR = ar

### Shell Commands ###
CP = cp -fr
MKDIR = mkdir -p
RM    = rm -f
RMDIR = rm -fr
TOUCH = touch

### Build Flags ###
CC_FLAGS = -Wall -Werror
LINK_FLAGS =
AR_FLAGS = rcs

### Rebuild Flag ###
REBUILD =

### Directories ###
BUILD_DIR = ./build
OUTPUT_DIR = ./output
SOURCE_DIR = ./source
HEADER_DIR = ./include

### Output Files ###
TARGET = euler.exe

### Source Files ###
SOURCES = $(SOURCE_DIR)/main.cpp \
          $(SOURCE_DIR)/Problem.cpp \
          $(SOURCE_DIR)/ProblemList.cpp \
          $(SOURCE_DIR)/ProblemHook.cpp \
		  $(wildcard $(SOURCE_DIR)/problem_*.cpp)

OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(SOURCES:.cpp=.o)))

### Default Target ###
default: all

### Build Dependencies ###
-include $(OBJECTS:.o=.d)

### Build Targets ###
.PHONY: all
all: build

.PHONY: build
build: $(OUTPUT_DIR)/$(TARGET)

.PHONY: rebuild
rebuild:
	@make build FORCE="force"

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp $(FORCE)
	@$(MKDIR) $(BUILD_DIR)
	$(CC) $(CC_FLAGS) -I$(HEADER_DIR) -c $< -o $@
	$(CC) $(CC_FLAGS) -I$(HEADER_DIR) -MM $< | sed "1 s|^|$(BUILD_DIR)/|" > $(BUILD_DIR)/$*.d

$(OUTPUT_DIR)/$(TARGET): $(OBJECTS) $(FORCE)
	@$(MKDIR) $(OUTPUT_DIR)
	$(CC) $(LINK_FLAGS) -o $@ $(OBJECTS)

.PHONY: clean
clean:
	$(RMDIR) $(BUILD_DIR)
	$(RMDIR) $(OUTPUT_DIR)

.PHONY: force
force:
