module sum_v2 (
    // input
        input logic         clk_i   ,
                            //en_i    ,
                            rst_ni  ,
        input logic  [7:0]  n_i     ,
        input signed [7:0]  data_i  ,

    // output
        output logic         done_o ,
        output signed [15:0] sum_o 

);
    // Register 
    reg [7:0] count_reg  ;
    reg [15:0] sum_reg    ;
    //reg [15:0] out_reg    ;

    // Wire main
    logic       done_wire   ;
    logic [7:0] n_in        ;
    logic [7:0] data_in     ;
    //logic [15:0] out_wire    ;

    // Wires inside
    logic [7:0] count_wire  ;
    logic [15:0] data_wire   ;
    logic [15:0] add_wire    ;

    always @(posedge clk_i) begin
        count_reg <= (rst_ni == 0 ) ? 0 : (done_wire) ? n_in : count_wire - 1 ;  // N_Selector 
        sum_reg   <= (rst_ni == 0 ) ? 0 : (done_wire) ? 0 : add_wire          ;  // Store sum
        //out_reg   <= (rst_ni == 0 ) ? 0 : out_wire                            ;  // Store output until update

    end
    
    assign sum_o     = sum_reg  ;
    assign n_in      = n_i      ;
    assign data_in   = data_i   ;

    // assign n_in      = (en_i) ? n_i : 0      ;
    // assign data_in   = (en_i) ? data_i : 0   ;
    // assign  sum_o    = (en_i) ? out_wire : 0 ;

    assign count_wire = count_reg ;
    assign done_wire = (count_wire == 8'b0) ;
    assign done_o    = done_wire ; 
    assign data_wire = (rst_ni == 0) ? 0 : (done_wire) ? 0 : {{8{data_in[7]}},data_in} ;
    assign add_wire  = sum_reg + data_wire ;
    //assign out_wire  = (done_wire) ? sum_reg : out_reg ;

endmodule : sum_v2
