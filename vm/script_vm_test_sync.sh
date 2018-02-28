#!/bin/zsh
DEF='\x1B[0m'
GRA='\x1B[1m'
SOU='\x1B[4m'
BLI='\x1B[5m'
INV='\x1B[7m'
BLA='\x1B[30m'
RED='\x1B[31m'
GRE='\x1B[32m'
YEL='\x1B[33m'
BLU='\x1B[34m'
PUR='\x1B[35m'
CYA='\x1B[36m'
WHI='\x1B[37m'
BACK_BLA='\x1B[40m'
BACK_RED='\x1B[41m'
BACK_GRE='\x1B[42m'
BACK_YEL='\x1B[43m'
BACK_BLU='\x1B[44m'
BACK_PUR='\x1B[45m'
BACK_CYA='\x1B[46m'
BACK_WHI='\x1B[47m'

TEST1="-v 31 -d 1800"
TEST2="-v 0"
TEST3="-v 1"
TEST4="-v 2"
TEST5="-v 3"
TEST6="-v 4"
TEST7="-v 5"
TEST8="-v 6"
TEST9="-v 7"
TEST10="-v 8"
TEST11="-v 9"
TEST12="-v 10"
TEST13="-v 11"
TEST14="-v 12"
TEST15="-v 13"
TEST16="-v 15"
TEST17="-v 16"
TEST18="-v 17"
TEST19="-v 18"
TEST20="-v 19"
TEST21="-v 20"
TEST22="-v 21"
TEST23="-v 22"
TEST24="-v 23"
TEST25="-v 24"
TEST26="-v 25"
TEST27="-v 26"
TEST28="-v 27"
TEST29="-v 28"
TEST30="-v 29"
TEST31="-v 30"
TEST32="-v 31"
TEST33="-v 32"
TEST34="-v 33"
TEST35="-v 34"
TEST36="-v 35"
TEST37="-v 36"
TEST38="-v 37"
TEST_LEN=38

TARGET_VM='vm_test'
TARGET_ZAZ='zaz_test'
TEST_PATH=../tests
TESTSUITE_PATH=**/tests/test_suiteTESTSUITE_PATH_WORKING=../tests/test_suite/working

echo "$YEL===== launching diff on our testsuite$DEF"
clear
testfile(){
	name=$(find ../tests/**/$1);
	echo "$SOU$CYA$name$DEF"
	../tests/asm $name;
	TEST_STR="\$TEST$j"
	champ=$(echo "$name" | sed -e 's/.s$/.cor/g');
	command=$(eval echo "$TEST_STR");
	./corewar -d $3 -v $2 $champ;
	./corewar -d $3 -v $2 $champ > my_res;
	./corewar -d $3 -v $2 $champ | tail -n 64 > my_dump_result;
	orig=$(ls /dev > diff1)
	osascript -e 'tell application "System Events" to keystroke "d" using command down'
	sleep 2
	next=$(ls /dev > diff2)
	diff_str=$(eval diff diff2 diff1 | tail -1 | cut -c 3-)
	echo "=======ZAZ======" > /dev/$diff_str
	../tests/corewar -d $3 -v $2 $champ > /dev/$diff_str;
	../tests/corewar -d $3 -v $2 $champ > zaz_res;
	../tests/corewar -d $3 -v $2 $champ | tail -n 64 > zaz_dump_result;
	res=$(diff -s zaz_dump_result my_dump_result);
	res1=$(diff -s zaz_res my_res);
	if [[ $res1 == "Files zaz_res and my_res are identical" ]] ; then
			echo "$GRE RESULT IS OK $DEF"
	else
			echo "$RED RESULT IS KO $DEF"
	fi
	if [[ $res == "Files zaz_dump_result and my_dump_result are identical" ]] ; then
		echo "$GRE DUMP IS OK $DEF"
	else
		echo "$RED DUMP IS KO $DEF"
	fi
	rm $champ
}
testfile $1 $2 $3
