#define MAX_SIM 2000

void set_random(Vtop *dut, vluint64_t sim_unit) {
    dut->en_i = 1;
    dut->n_i = (sim_unit == 0 || dut->done_o==1 ) ? rand()%4 + 1 : dut->n_i ;
    dut->data_i = rand() % 128 ;
    dut-> rst_ni = 1;

    // Testbench
    static int sum = 0 ;
    static int test_counter = 0 ;
    if(dut->done_o) {
        if(dut->sum_o == sum )
            printf("Test %d : %d %d :  \033[0;32mPASSS\033[0m\n ",test_counter,sum,dut->sum_o) ;
        else
            printf("Test %d : %d %d :  \033[0;31mFAIL\033[0m\n ",test_counter,sum,dut->sum_o) ;
        sum = 0 ;
        test_counter ++ ;
    } else {
        sum += dut->data_i ;
    }

}

// void testbench(Vtop *dut){
    
// }