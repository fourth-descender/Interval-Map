CMAKE_COMMAND = cmake
BUILD_DIR = build
TEST_EXECUTABLE = $(BUILD_DIR)/IntervalMap

all: build

build:
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && $(CMAKE_COMMAND) ..
	@$(MAKE) -C $(BUILD_DIR)

test:
	@if [ ! -d $(BUILD_DIR) ] || [ ! -f $(TEST_EXECUTABLE) ]; then \
		$(MAKE) build; \
	fi
	@$(TEST_EXECUTABLE)

clean:
	@$(MAKE) -C $(BUILD_DIR) clean
	@rm -rf $(BUILD_DIR)

.PHONY: all build test clean
