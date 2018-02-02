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
TESTSUITE_PATH=../tests/test_suite
TESTSUITE_PATH_WORKING=../tests/test_suite/working
LOG_WORKING='list_op_working'
LOG_BROKEN='list_op_broken'

echo "$YEL===== launching diff on our testsuite$DEF"
testfun(){
> my_dump_result;
> zaz_dump_result;
for i in $TESTSUITE_PATH/$1/**.s; do
	name=$i;
	echo "$SOU$CYA$name$DEF"
	../tests/asm $name;
	sleep 0.5;
#	for j in $(seq 1 $TEST_LEN); do
#		TEST_STR="\$TEST$j"
		champ=$(echo "$name" | sed -e 's/.s$/.cor/g');
#		command=$(eval echo "$TEST_STR");
		#echo "command is: $command"
		#echo "./corewar $command $champ > $TARGET_VM$j";
		./corewar -v $2 -d $3 $champ > $TARGET_VM;
		sleep 0.5;
		#echo "../tests/corewar $command $champ > $TARGET_ZAZ$j";
		../tests/corewar -v $2 -d $3 $champ > $TARGET_ZAZ;
		sleep 0.5;
		res=$(diff -s $TARGET_ZAZ $TARGET_VM);
		if [[ $res == "Files $TARGET_ZAZ$j and $TARGET_VM$j are identical" ]] ; then
			echo "$GRE OK $DEF"
		else
			./corewar -v $2 -d $3 $champ | tail -n 64 > my_dump_result;
			sleep 0.5;
			../tests/corewar -v $2 -d $3 $champ | tail -n 64 > zaz_dump_result;
			res1=$(diff -s zaz_dump_result my_dump_result);
			if [[ $res1 == "Files zaz_dump_result and my_dump_result are identical" ]] ; then
				echo "$GRE DUMP IS OK $DEF"
			else
				echo "$RED DUMP IS KO $DEF"
			fi
		fi
	echo '';
	sleep 0.5;
done ;
rm $TARGET_ZAZ* $TARGET_VM*
rm $TESTSUITE_PATH/*/*.cor
}
testfun $1 $2 $3
