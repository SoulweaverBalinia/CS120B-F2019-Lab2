# Test file for Lab2_introToAVR part 1

echo ======================================================\n
echo Running all tests...\n\n

test "PINA: 0x00 => PORTB: 0x00"
setPINA 0x00
continue 5
expectPORTB 0x00
checkResult

test "PINA: 0x01 => PORTB: 0x01"
setPINA 0x01
continue 5
expectPORTB 0x01
checkResult

test "PINA: 0x02 => PORTB: 0x00"
setPINA 0x02
continue 5
expectPORTB 0x00
checkResult

test "PINA: 0x03 => PORTB: 0x00"
setPINA 0x03
continue 5
expectPORTB 0x00
checkResult

set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n