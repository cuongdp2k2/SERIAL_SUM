module top (
    //inputs
    input logic clk_i,
    input logic rst_ni,
    input logic en_i,
    input logic [7:0] data_i, n_i,
    //outputs
    output logic done_o,
    output logic [8:0] sum_o
);
sum_v2 sum_module (
    .*
); 
endmodule
