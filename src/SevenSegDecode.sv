module SevenSegDecode (
    // input
        input logic [3:0] input_i ,

    // output
        output logic [7:0] output_o
);
    always_comb begin : Decode
        case (input_i)
            4'h0:   output_o = 8'hC0 ;
            4'h1:   output_o = 8'hF9 ;
            4'h2:   output_o = 8'hA4 ;
            4'h3:   output_o = 8'hB0 ;
            4'h4:   output_o = 8'h99 ;
            4'h5:   output_o = 8'h92 ;
            4'h6:   output_o = 8'h82 ;
            4'h7:   output_o = 8'hF8 ;
            4'h8:   output_o = 8'h80 ;
            4'h9:   output_o = 8'h90 ;
            4'hA:   output_o = 8'h88 ;
            4'hB:   output_o = 8'h80 ;
            4'hC:   output_o = 8'hC6 ;
            4'hD:   output_o = 8'hC0 ;
            4'hE:   output_o = 8'h86 ;
            4'hF:   output_o = 8'h8E ; 
        endcase
    end
endmodule : SevenSegDecode 
