
PATH_SRC = ./test_suite/
PATH_STI = $(PATH_SRC)sti/

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
		sti_ind_32764.s \
		sti_ind_32765.s \
		sti_ind_32766.s \
		sti_ind_32767.s \
		sti_ind_32768.s \
		sti_ind_32769.s \
		sti_ind_32770.s \
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

SRC_STI = $(addprefix $(PATH_STI), $(STI))

OBJ_STI = $(SRC_STI:.s=.cor)

all : sti

sti: $(OBJ_STI)

$(PATH_STI)%.cor : $(PATH_STI)%.s
	./asm $^

clean :
	rm $(OBJ_STI)
