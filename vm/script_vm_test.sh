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

TEST_PATH=../tests
TESTSUITE_PATH=../tests/test_suite
TESTSUITE_PATH_WORKING=../tests/test_suite/working

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
TEST_LEN=19

TARGET_VM='vm_test'
TARGET_ZAZ='zaz_test'
echo "$YEL===== launching diff on our testsuite$DEF"
echo -n > list_working
echo -n > list_broken
for i in $TESTSUITE_PATH/*.s; do
	name=$i;
	echo "$SOU$CYA$name$DEF"
	../tests/asm $name;
	for j in $(seq 1 $TEST_LEN); do
		TEST_STR="\$TEST$j"
		champ=$(echo "$name" | sed -e 's/.s$/.cor/g');
		command=$(eval echo "$TEST_STR");
		#echo "command is: $command"
		#echo "./corewar $command $champ > $TARGET_VM$j";
		./corewar $command $champ > $TARGET_VM$j;
		#echo "../tests/corewar $command $champ > $TARGET_ZAZ$j";
		../tests/corewar $command $champ > $TARGET_ZAZ$j;
		res=$(diff -s $TARGET_ZAZ$j $TARGET_VM$j);
		if [[ $res == "Files $TARGET_ZAZ$j and $TARGET_VM$j are identical" ]] ; then
			echo "$GRE OK $DEF with $command"
			echo "$GRE OK $DEF with $command"  >> list_working
		else
			echo "$RED KO $DEF with $command"
			echo "$RED KO $DEF with $command" >> list_broken
			lines_conf="$TARGET_ZAZ$j $TARGET_VM$j | head -n 1 | cut -d , -f 1 -s";
			conflicts=$(eval diff "$lines_conf")
			echo "$conflicts conflicting lines"
		fi
	done ;
	echo '';
done ;
rm $TARGET_ZAZ* $TARGET_VM*
rm $TESTSUITE_PATH/*.cor
