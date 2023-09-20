module sum_v2 (
    // input
        input logic       clk_i,
                          en_i ,
                          rst_ni ,
        input logic [7:0] n_i ,
        input logic [7:0] data_i ,

    // output
        output logic       done_o ,
        output logic [8:0] sum_o 

);
    reg [7:0] count_reg  ;
    reg [8:0] sum_reg    ;
    reg [8:0] out_reg    ;

    logic       done_wire   ;
    logic [7:0] n_in        ;
    logic [7:0] data_in     ;

    //logic [7:0] n_wire      ;
    logic [7:0] count_wire  ;
    logic [8:0] data_wire   ;
    logic [8:0] add_wire    ;
    logic [8:0] out_wire    ;


    always @(posedge clk_i) begin
        count_reg <= (rst_ni == 0 ) ? 0 : (done_wire) ? n_in : count_wire - 1 ;  // N_Selector 
        sum_reg   <= (rst_ni == 0 ) ? 0 : (done_wire) ? 0 : add_wire  ;  // Store sum
        out_reg   <= (rst_ni == 0 ) ? 0 : out_wire   ;
    end
    
    assign n_in      = (en_i) ? n_i : 0 ;
    assign data_in   = (en_i) ? data_i : 0 ;
    assign  sum_o    = (en_i) ? out_wire : 0 ;

    assign count_wire = count_reg ;
    assign done_wire = (count_wire == 8'b0) ;
    assign done_o    = done_wire ; 
    assign data_wire = (rst_ni == 0) ? 0 : (done_wire) ? 0 : {data_in[7],data_in} ;
    assign add_wire  = sum_reg + data_wire ;
    assign out_wire  = (done_wire) ? sum_reg : out_reg ;

endmodule : sum_v2