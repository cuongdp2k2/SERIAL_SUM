#define MAX_SIM 2000

void set_random(Vtop *dut, vluint64_t sim_unit) {
    dut->en_i = 1;
    dut->n_i = (sim_unit == 0 || dut->done_o==1 ) ? rand()%7 + 1 : dut->n_i ;
    dut->data_i = rand() % 256 ;
    dut-> rst_ni = 1;

    // Testbench
    static int sum = 0 ;
    static int test_counter = 0 ;
    static int passed_test = 0 ;
    static int failed_test = 0 ;

    if(dut->done_o) {
        if(sum < 0) sum += 65536 ;
        if(dut->sum_o == sum ){
            printf("Test %d : %d -> %d :  \033[0;32mPASSSED\033[0m\n ",test_counter,sum,dut->sum_o) ;
            passed_test ++ ;
        }
        else {
            printf("Test %d : %d -> %d :  \033[0;31mFAILED\033[0m\n ",test_counter,sum,dut->sum_o) ;
            failed_test ++ ;
        }
        sum = 0 ;
        test_counter ++ ;
    } else {
        //sum += dut->data_i ;
        if(dut->data_i >= 128) sum+= -256 + dut->data_i ;
        else sum += dut->data_i ;
    }

    if(sim_unit == MAX_SIM-1){
        printf("\n--------REPORT ------------------- \n") ;
        printf("\033[0;32mPASSED : %d/%d\033[0m\n",passed_test,test_counter) ;
        printf("\033[0;31mFAILED : %d/%d\033[0m\n",failed_test,test_counter) ;
        printf("----------------------------------\n");
    }
}

// void testbench(Vtop *dut){
    
// }