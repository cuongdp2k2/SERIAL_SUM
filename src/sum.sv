module sum (
    //inputs
    input logic clk_i,
    input logic rst_ni,
    input logic start_i,
    input logic [7:0] data_i, n_i,
    //outputs
    output logic done_o,
    output logic [7:0] sum_o
);
logic [7:0] get_sum = 0;
logic [7:0] get_n = 0;
logic [7:0] counter = 0;
//Defines the states
typedef enum logic [1:0] { 
    START = 0,
    CALC = 1,
    COMPLETE = 2
} the_state;
the_state state = START;
    always_ff @(posedge clk_i ) begin
        if (!rst_ni) begin
            sum_o <= 8'h0;
            done_o <= 0;
            get_sum <= 0;
            counter <= 0 ;    
            state <= START;
        end
        else begin
            case (state) 
                START: begin
                    done_o <= 0 ;
                    if (start_i) begin
                        state <= CALC;
                        get_n <= n_i;
                        get_sum <= 0 ;
                    end
                    else begin
                        state <= START;
                    end
                end
                CALC : begin
                    done_o <= 0 ;
                    if (counter < get_n) begin
                        get_sum <= (get_sum + data_i);
                        counter<= (counter + 1);
                        state <= CALC;
                    end
                    else begin
                        state <= COMPLETE;
                    end
                end 
                COMPLETE: begin
                    sum_o <= get_sum;
                    done_o <= 1;
                end
                default: begin
                    sum_o <= 8'h0;
                    get_sum <= 0 ;
                    done_o <= 0;     
                end 
            endcase
        end
    end
endmodule
