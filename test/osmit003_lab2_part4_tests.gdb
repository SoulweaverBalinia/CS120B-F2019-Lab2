# Test file for Lab2_introToAVR part 4

echo ======================================================\n
echo Running all tests...\n\n

test "PINA: 40, PINB: 60, PINC: 40 => PORTD: 0x8C"
setPINA 40
setPINB 60
setPINC 40
continue 5
expectPORTD 0x8C
checkResult

test "PINA: 40, PINB: 50, PINC: 40 => PORTD: 0x80"
setPINA 40
setPINB 50
setPINC 40
continue 5
expectPORTD 0x8C
checkResult

test "PINA: 100, PINB: 25, PINC: 15 => PORTD: 0x8E"
setPINA 100
setPINB 25
setPINC 15
continue 5
expectPORTD 0x8E
checkResult

test "PINA: 100, PINB: 20, PINC: 40 => PORTD: 0x91"
setPINA 100
setPINB 25
setPINC 15
continue 5
expectPORTD 0x91
checkResult

test "PINA: 30, PINB: 40, PINC: 120 => PORTD: 0xBC"
setPINA 30
setPINB 25
setPINC 15
continue 5
expectPORTD 0xBC
checkResult

set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n