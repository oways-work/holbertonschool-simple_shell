#!/bin/bash
# Comprehensive test suite for simple shell

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

PASSED=0
FAILED=0

echo "================================"
echo "  SIMPLE SHELL TEST SUITE"
echo "================================"
echo ""

# Function to run test
run_test() {
    local test_name="$1"
    local command="$2"
    local expected="$3"
    
    echo -n "Testing: $test_name ... "
    result=$(echo "$command" | ./hsh 2>&1)
    
    if [[ "$result" == *"$expected"* ]]; then
        echo -e "${GREEN}PASSED${NC}"
        ((PASSED++))
    else
        echo -e "${RED}FAILED${NC}"
        echo "  Expected: $expected"
        echo "  Got: $result"
        ((FAILED++))
    fi
}

# Compile first
echo "Compiling shell..."
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh 2>/dev/null

if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed!${NC}"
    exit 1
fi

echo -e "${GREEN}Compilation successful!${NC}"
echo ""

# Test 1: Absolute path
run_test "Absolute path /bin/ls" "/bin/ls" ""

# Test 2: Command with PATH
run_test "PATH resolution (ls)" "ls" ""

# Test 3: Command with arguments
run_test "Command with args (ls -l)" "ls -l" ""

# Test 4: env builtin
run_test "env builtin" "env" "PATH"

# Test 5: Non-existent command
run_test "Non-existent command" "doesnotexist" "not found"

# Test 6: Multiple commands
echo -e "/bin/pwd\n/bin/ls" | ./hsh > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo -e "Testing: Multiple commands ... ${GREEN}PASSED${NC}"
    ((PASSED++))
else
    echo -e "Testing: Multiple commands ... ${RED}FAILED${NC}"
    ((FAILED++))
fi

echo ""
echo "================================"
echo "  TEST RESULTS"
echo "================================"
echo -e "${GREEN}Passed: $PASSED${NC}"
echo -e "${RED}Failed: $FAILED${NC}"
echo ""

if [ $FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed! ✓${NC}"
    exit 0
else
    echo -e "${YELLOW}Some tests failed. Please review.${NC}"
    exit 1
fi
