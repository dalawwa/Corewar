
PATH_SRC = ./test_suite/
PATH_STI = $(PATH_SRC)sti/
PATH_TEST = ./
PATH_TEST_ADV = $(PATH_TEST)test_cor_wrong_ocp/

STI =	sti.s \
		sti_2.s \
		sti_3.s \
		sti_4.s \
		sti_5.s \
		sti_6.s \
		sti_all.s \
		sti_ind_-1.s \
		sti_ind_-2.s \
		sti_ind_00.s \
		sti_ind_01.s \
		sti_ind_02.s \
		sti_ind_03.s \
		sti_ind_1.s \
		sti_ind_2.s \
		sti_ind_3.s \
		sti_ind_4.s \
		sti_ind_5.s \
		sti_ind_6.s \
		sti_ind_7.s \
		sti_ind_8.s \
		sti_ind_9.s \
		sti_ind_10.s \
		sti_ind_11.s \
		sti_ind_12.s \
		sti_ind_13.s \
		sti_ind_14.s \
		sti_ind_15.s \
		sti_ind_16.s \
		sti_ind_17.s \
		sti_ind_18.s \
		sti_ind_19.s \
		sti_ind_20.s \
		sti_ind_21.s \
		sti_ind_22.s \
		sti_ind_254.s \
		sti_ind_255.s \
		sti_ind_256.s \
		sti_ind_257.s \
		sti_ind_258.s \
		sti_ind_51198.s \
		sti_ind_51199.s \
		sti_ind_51200.s \
		sti_ind_51201.s \
		sti_ind_51202.s \
		sti_ind_32700.s \
		sti_ind_32710.s \
		sti_ind_32720.s \
		sti_ind_32730.s \
		sti_ind_32740.s \
		sti_ind_32750.s \
		sti_ind_32751.s \
		sti_ind_32752.s \
		sti_ind_32753.s \
		sti_ind_32754.s \
		sti_ind_32755.s \
		sti_ind_32756.s \
		sti_ind_32757.s \
		sti_ind_32758.s \
		sti_ind_32759.s \
		sti_ind_32760.s \
		sti_ind_32761.s \
		sti_ind_32762.s \
		sti_ind_32763.s \
		sti_ind_32764.s \
		sti_ind_32765.s \
		sti_ind_32766.s \
		sti_ind_32767.s \
		sti_ind_32768.s \
		sti_ind_32769.s \
		sti_ind_32770.s \
		sti_ind_32771.s \
		sti_ind_32772.s \
		sti_ind_32773.s \
		sti_ind_33275.s \
		sti_ind_33276.s \
		sti_ind_33277.s \
		sti_ind_33278.s \
		sti_ind_33279.s \
		sti_ind_33280.s \
		sti_ind_33281.s \
		sti_ind_33282.s \
		sti_ind_33283.s \
		sti_ind_33284.s \
		sti_ind_33285.s \
		sti_ind_33286.s \
		sti_ind_33287.s \
		sti_ind_full.s

TEST_ADV =	fork_03_07_54.s \
			fork_03_07_64.s \
			fork_03_07_74.s \
			fork_03_07_94.s \
			fork_03_07_a4.s \
			fork_03_07_b4.s \
			fork_03_07_d4.s \
			fork_03_07_e4.s \
			fork_05_07_54.s \
			fork_05_07_64.s \
			fork_05_07_74.s \
			fork_05_07_94.s \
			fork_05_07_a4.s \
			fork_05_07_b4.s \
			fork_05_07_d4.s \
			fork_05_07_e4.s \
			fork_05_07_f4.s \
			fork_06_07_54.s \
			fork_06_07_64.s \
			fork_06_07_74.s \
			fork_06_07_94.s \
			fork_06_07_a4.s \
			fork_06_07_b4.s \
			fork_06_07_d4.s \
			fork_06_07_e4.s \
			fork_06_07_f4.s \
			fork_07_07_54.s \
			fork_07_07_64.s \
			fork_07_07_74.s \
			fork_07_07_94.s \
			fork_07_07_a4.s \
			fork_07_07_b4.s \
			fork_07_07_d4.s \
			fork_07_07_e4.s \
			fork_07_07_f4.s \
			fork_02_07_54.s \
			fork_02_07_64.s \
			fork_02_07_74.s \
			fork_02_07_94.s \
			fork_02_07_a4.s \
			fork_02_07_b4.s \
			fork_02_07_d4.s \
			fork_02_07_e4.s \
			fork_02_07_f4.s \
			fork_02_03_50.s \
			fork_07_03_50.s \
			fork_07_03_70.s \
			fork_02_03_50_new.s \
			fork_07_0a_54.s \
			fork_07_0a_64.s \
			fork_07_0a_94.s \
			fork_07_0a_a4.s \
			fork_07_0a_d4.s \
			fork_07_0a_e4.s \
			fork_07_0b_54.s \
			fork_07_0b_58.s \
			fork_07_0b_64.s \
			fork_07_0b_68.s \
			fork_07_0b_74.s \
			fork_07_0b_78.s \
			fork_02_03_70.s \
			fork_03_07_f4.s

SRC_STI = $(addprefix $(PATH_STI), $(STI))
SRC_TEST_ADV = $(addprefix $(PATH_TEST_ADV), $(TEST_ADV))

OBJ_STI = $(SRC_STI:.s=.cor)
OBJ_TEST_ADV = $(SRC_TEST_ADV:.s=.cor)

all : sti test_adv

sti: $(OBJ_STI)

test_adv : $(OBJ_TEST_ADV)

$(PATH_STI)%.cor : $(PATH_STI)%.s
	./asm $^

$(PATH_TEST_ADV)%.cor : $(PATH_TEST_ADV)%.s 
	./asm $^

clean :
	rm $(OBJ_STI) $(OBJ_TEST_ADV)
